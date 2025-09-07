#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <SDL.h>
#include <SDL2/SDL_ttf.h>

#define ROWS 10
#define COLS 18
#define ELEMENT_COUNT 118

typedef enum {
    HIDROGEN,
    ALKALI_METAL,
    EARTH_ALKALI_METAL,
    TRANSITION_METAL,
    OTHER_METALS,
    SEMIMETAL,
    NON_METAL,
    HALOGEN,
    NOBLE_GAS,
    UNKNOWN,
    LANTHANIDE,
    ACTINIDE
} CATEGORY;

typedef enum {
    TEXT_CENTER,
    TEXT_LEFT,
    TEXT_RIGHT
} TEXTHORIZONTAL;

typedef enum {
    TEXT_TOP,
    TEXT_MID,
    TEXT_BASE
} TEXTVERTICAL;

typedef struct {
    int layers[7];
    int atomic_number;
    char symbol[3];
    char name[20];
    float atomic_mass;
    CATEGORY category;
    int x, y;
} ELEMENT;

const int border = 20;
const int unit = 64;
const int gap = 4;

const int win_element_border = 10;
const int win_element_width = 200;
const int win_element_height = 200;

TTF_Font *courier_new_12 = NULL;
TTF_Font *courier_new_18 = NULL;
TTF_Font *courier_new_24 = NULL;
TTF_Font *courier_new_60 = NULL;

void draw( SDL_Renderer* );
void on_click( int, int );
void open_window_element( ELEMENT* );
SDL_Color category_to_color( CATEGORY );
void draw_element( SDL_Renderer*, ELEMENT* );
void write_text( const char*, SDL_Renderer*, TTF_Font*, SDL_Color, int, int, TEXTHORIZONTAL, TEXTVERTICAL );
void capitalize( char* );

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    SDL_Init( SDL_INIT_EVERYTHING );
    
    TTF_Init();

    courier_new_12 = TTF_OpenFont( "courier_new.ttf", 12 );
    if(!courier_new_12) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    courier_new_18 = TTF_OpenFont( "courier_new.ttf", 18 );
    if(!courier_new_18) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    courier_new_24 = TTF_OpenFont( "courier_new.ttf", 24 );
    if(!courier_new_24) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    courier_new_60 = TTF_OpenFont( "courier_new.ttf", 60 );
    if(!courier_new_60) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    const int width = (border * 2) + (unit * COLS) + (gap * COLS),
              height = (border * 2) + (unit * ROWS) + (gap * ROWS);

    SDL_Window* window = SDL_CreateWindow( "TABELA PERIÓDICA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI );
	if ( window == NULL ) {
        printf( "Error creating window: %s", SDL_GetError() );
		return EXIT_FAILURE;
	}

    int window_id = SDL_GetWindowID( window );

    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if ( render == NULL ) {
        printf( "Error creating renderer: %s", SDL_GetError() );
		return EXIT_FAILURE;
	}

    SDL_SetRenderDrawBlendMode( render, SDL_BLENDMODE_BLEND );

    SDL_Event window_event;

    bool running = true;

    while (running) {
        while (SDL_PollEvent(&window_event)) {
            if ( window_event.window.windowID == window_id ) {
                switch ( window_event.type ) {
                    case SDL_QUIT:
                        running = false;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        int window_mouse_pos_x;
                        int window_mouse_pos_y;
                        int window_pos_x;
                        int window_pos_y;
                        SDL_GetGlobalMouseState( &window_mouse_pos_x, &window_mouse_pos_y );
                        SDL_GetWindowPosition( window, &window_pos_x, &window_pos_y );
                        int mouse_pos_x = window_mouse_pos_x - window_pos_x;
                        int mouse_pos_y = window_mouse_pos_y - window_pos_y;
                        on_click( mouse_pos_x, mouse_pos_y );
                        break;
                }
            }
        }

        draw( render );
    }

    TTF_CloseFont( courier_new_60 );
    TTF_CloseFont( courier_new_24 );
    TTF_CloseFont( courier_new_18 );
    TTF_CloseFont( courier_new_12 );
    TTF_Quit();

    SDL_DestroyWindow( window );
	SDL_Quit();
    return EXIT_SUCCESS;
}

void draw( SDL_Renderer *render ) {
    SDL_SetRenderDrawColor( render, 0, 0, 0, 255 );
    SDL_RenderClear( render );

    SDL_Rect r;

    FILE *file = fopen("data.bin", "rb");
    ELEMENT element;

    for (int i = 0; i < ELEMENT_COUNT; i++) {
        fseek(file, i * sizeof(ELEMENT), SEEK_SET);
        fread(&element, sizeof(ELEMENT), 1, file);

        r.w = unit;
        r.h = unit;
        r.x = border + element.x * (unit + gap);
        r.y = border + element.y * (unit + gap);

        SDL_Color color = category_to_color(element.category);
        color.a = 255;

        SDL_SetRenderDrawColor( render, color.r, color.g, color.b, color.a );
		SDL_RenderFillRect( render, &r );

        color.r = 0;
        color.g = 0;
        color.b = 0;

        char str_atomic_number[4];
        sprintf(str_atomic_number, "%hi", element.atomic_number);
        write_text( str_atomic_number, render, courier_new_18, color, r.x + 1, r.y + 1, TEXT_LEFT, TEXT_TOP );

        write_text( element.symbol, render, courier_new_24, color, r.x + unit/2, r.y + unit/2, TEXT_CENTER, TEXT_MID );
    }

    fclose( file );
    SDL_RenderPresent( render );
}

void on_click( int mouse_x, int mouse_y ) {
    FILE *file = fopen("data.bin", "rb");
    ELEMENT element;

    for (int i = 0; i < ELEMENT_COUNT; i++) {
        fseek(file, i * sizeof(ELEMENT), SEEK_SET);
        fread(&element, sizeof(ELEMENT), 1, file);

        int x = border + element.x * (unit + gap);
        int y = border + element.y * (unit + gap);

        if (
            mouse_x >= x &&
            mouse_y >= y &&
            mouse_x <= x + unit &&
            mouse_y <= y + unit
        )
            open_window_element( &element );
    }

    fclose(file);
}

void open_window_element( ELEMENT* element ) {
    SDL_Window* window = SDL_CreateWindow( element->name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        win_element_width + win_element_border * 2,
        win_element_height + win_element_border * 2,
        SDL_WINDOW_ALLOW_HIGHDPI );

	if ( window == NULL ) {
        printf( "Error creating window: %s", SDL_GetError() );
		exit(1);
	}

    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if ( render == NULL ) {
        printf( "Error creating renderer: %s", SDL_GetError() );
		exit(1);
	}

    SDL_SetRenderDrawBlendMode( render, SDL_BLENDMODE_BLEND );
    // SDL_SetWindowBordered( window, false );
    int window_id = SDL_GetWindowID( window );

    SDL_Event window_event;
    bool running = true;

    draw_element( render, element );
    while (running) {
        while (SDL_PollEvent(&window_event)) {
            if ( window_event.type == SDL_MOUSEBUTTONDOWN && window_event.window.windowID == window_id )
                running = false;
        }
    }

    SDL_DestroyRenderer( render );
    SDL_DestroyWindow( window );
}

void draw_element( SDL_Renderer *render, ELEMENT* element ) {
    SDL_Rect r;
    SDL_Surface *text_surface;
    SDL_Texture *text_texture;

    SDL_Color color = category_to_color( element->category );
    SDL_SetRenderDrawColor( render, color.r, color.g, color.b, color.a );

    r.x = win_element_border;
    r.y = win_element_border;
    r.w = win_element_width;
    r.h = win_element_height;
    SDL_RenderFillRect( render, &r );

    r.x = 1;
    r.y = 1;
    r.w = win_element_width + win_element_border * 2 - 1;
    r.h = win_element_height + win_element_border * 2 - 1;
    SDL_RenderDrawRect( render, &r );

    color.r = 0;
    color.g = 0;
    color.b = 0;

    char str_atomic_number[4];
    sprintf( str_atomic_number, "%d", element->atomic_number );
    write_text( str_atomic_number, render, courier_new_18, color,
        win_element_border + 2,
        win_element_border + 2, TEXT_LEFT, TEXT_TOP );

    write_text( element->symbol, render, courier_new_60, color,
        win_element_width/2 + win_element_border,
        win_element_height * 0.4 + win_element_border, TEXT_CENTER, TEXT_MID );

    capitalize(element->name);
    write_text( element->name, render, courier_new_24, color,
        win_element_width/2 + win_element_border,
        win_element_height * 0.75 + win_element_border, TEXT_CENTER, TEXT_MID );

    char str_atomic_mass[11];
    sprintf( str_atomic_mass, "%.4f u", element->atomic_mass );
    write_text( str_atomic_mass, render, courier_new_12, color,
        win_element_width/2 + win_element_border,
        win_element_height * 0.9 + win_element_border, TEXT_CENTER, TEXT_MID );

    char str_layer[4];
    for (int i = 0; i < 7; i++) {
        if ( element->layers[i] == 0 ) break;

        sprintf( str_layer, "%d", element->layers[i] );
        write_text( str_layer, render, courier_new_18, color,
            win_element_border + win_element_width - 2,
            win_element_border + 20 * i + 2, TEXT_RIGHT, TEXT_TOP );
    }

    SDL_RenderPresent( render );
}

SDL_Color category_to_color(CATEGORY category) {
    switch (category) {
        case HIDROGEN:              return (SDL_Color) { 220, 228, 255, 255 };
        case ALKALI_METAL:          return (SDL_Color) { 253, 233, 16 , 255 };
        case EARTH_ALKALI_METAL:    return (SDL_Color) { 250, 190, 14 , 255 };
        case TRANSITION_METAL:      return (SDL_Color) { 201, 48 , 44 , 255 };
        case OTHER_METALS:          return (SDL_Color) { 255, 0  , 255, 255 };
        case SEMIMETAL:             return (SDL_Color) { 227, 68 , 137, 255 };
        case NON_METAL:             return (SDL_Color) { 25 , 230, 25 , 255 };
        case HALOGEN:               return (SDL_Color) { 106, 90 , 205, 255 };
        case NOBLE_GAS:             return (SDL_Color) { 144, 16 , 136, 255 };
        case LANTHANIDE:            return (SDL_Color) { 173, 216, 230, 255 };
        case ACTINIDE:              return (SDL_Color) { 148, 123, 192, 255 };
        case UNKNOWN:               return (SDL_Color) { 100, 100, 100, 255 };
        default:                    return (SDL_Color) { 255, 255, 255, 255 };
    }
}

void write_text( const char *text, SDL_Renderer *render, TTF_Font *font, SDL_Color color, int x, int y, TEXTHORIZONTAL text_horiz, TEXTVERTICAL text_vert ) {    
    SDL_Surface *text_surface = TTF_RenderUTF8_Blended(font, text, color);
    if (!text_surface) return;
    
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(render, text_surface);
    if (!text_texture) {
        SDL_FreeSurface(text_surface);
        return;
    }
    
    int text_width, text_height;
    SDL_QueryTexture(text_texture, NULL, NULL, &text_width, &text_height);

    SDL_Rect dest_rect;

    switch (text_vert) {
        case TEXT_TOP:
            dest_rect.y = y;
            break;

        case TEXT_MID:
            dest_rect.y = y - text_height / 2;
            break;

        case TEXT_BASE:
            dest_rect.y = y - text_width;
            break;
    }

    switch (text_horiz) {
        case TEXT_LEFT:
            dest_rect.x = x;
            break;

        case TEXT_RIGHT:
            dest_rect.x = x - text_width;
            break;

        case TEXT_CENTER:
            dest_rect.x = x - text_width / 2;
            break;
    }

    dest_rect.w = text_width;
    dest_rect.h = text_height;
    
    SDL_RenderCopy(render, text_texture, NULL, &dest_rect);
    
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

void capitalize( char* text ) {
    text[0] = toupper(text[0]);
}