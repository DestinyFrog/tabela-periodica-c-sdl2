#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL2/SDL_ttf.h>

#include "elements.h"

SDL_Window* window;
SDL_Renderer* render;
SDL_Event window_event;

TTF_Font *courier_new_24 = NULL,
         *courier_new_12 = NULL;

const unsigned int
    border = 10,
    unit = 64,
    text_unit_12 = 14,
    text_unit_24 = 28,
    gap = 2;

unsigned short int
    i, j,
    width,
    height,
    length;

void awake() {
    courier_new_24 = TTF_OpenFont("courier_new.ttf", 24);
    if(!courier_new_24) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    courier_new_12 = TTF_OpenFont("courier_new.ttf", 12);
    if(!courier_new_12) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    width = (border * 2) + (unit * COLS) + (gap * COLS);
    height = (border * 2) + (unit * ROWS) + (gap * ROWS);
}

SDL_Rect r;

SDL_Surface* text_surface;
SDL_Texture* text_texture;
SDL_Color color;

char str_atomic_number[4];

void draw() {
    SDL_SetRenderDrawColor( render, 0, 0, 0, 255 );
    SDL_RenderClear( render );

    for (i = 0; i < ELEMENT_COUNT; i++) {
        r.w = unit;
        r.h = unit;
        r.x = border + elements[i].x * (unit + gap);
        r.y = border + elements[i].y * (unit + gap);

        color = category_to_color(elements[i].category);
        color.a = 255;

        SDL_SetRenderDrawColor( render, color.r, color.g, color.b, color.a );
		SDL_RenderDrawRect( render, &r );

        sprintf(str_atomic_number, "%hi", i + 1);

        for (length = 0; str_atomic_number[length] != '\0'; length++);

        r.w = text_unit_12/2 * length;
        r.h = text_unit_12;
        r.x = r.x + 2;
        r.y = r.y + 2;

        text_surface = TTF_RenderText_Solid( courier_new_12, str_atomic_number, color );
        text_texture = SDL_CreateTextureFromSurface( render, text_surface );
        SDL_RenderCopy( render, text_texture, NULL, &r );
        SDL_DestroyTexture( text_texture );
        SDL_FreeSurface( text_surface );

        for (length = 0; elements[i].symbol[length] != '\0'; length++);

        r.w = text_unit_24/2 * length;
        r.h = text_unit_24;
        r.x = r.x + unit/2 - (text_unit_24/2) + (length == 1 ? (r.w/2) : 0);
        r.y = r.y + unit/2 - (text_unit_24/2);

        text_surface = TTF_RenderText_Solid( courier_new_24, elements[i].symbol, color );
        text_texture = SDL_CreateTextureFromSurface( render, text_surface );
        SDL_RenderCopy( render, text_texture, NULL, &r );
        SDL_DestroyTexture( text_texture );
        SDL_FreeSurface( text_surface );
    }

    SDL_RenderPresent( render );
}

int main() { 
    SDL_Init( SDL_INIT_EVERYTHING );
    TTF_Init();

    awake();

    window = SDL_CreateWindow( "SOLAR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI );
	if ( window == ((void*)0) ) {
        printf( "Error creating window: %s", SDL_GetError() );
		return EXIT_FAILURE;
	}
    
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if ( render == ((void*)0) ) {
        printf( "Error creating renderer: %s", SDL_GetError() );
		return EXIT_FAILURE;
	}

    SDL_SetRenderDrawBlendMode( render, SDL_BLENDMODE_BLEND );

    draw();

    do {
        SDL_PollEvent( &window_event );
        SDL_Delay(10);
    }   while ( SDL_QUIT != window_event.type );

    TTF_CloseFont(courier_new_24);
    TTF_Quit();

    SDL_DestroyWindow( window );
	SDL_Quit();
	return EXIT_SUCCESS;
}