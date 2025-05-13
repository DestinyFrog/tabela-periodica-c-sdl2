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

int border = 10,
    unit = 36,
    text_unit = 28,
    gap = 2,
    width,
    height, i, j;

TTF_Font* font = NULL;

void awake() {
    font = TTF_OpenFont("courier_new.ttf", 24);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    width = (border * 2) + (unit * COLS) + (gap * COLS);
    height = (border * 2) + (unit * ROWS) + (gap * ROWS);
}

SDL_Rect r;
SDL_Rect text_r;

SDL_Color White = {255, 255, 255};
SDL_Surface* text_surface;
SDL_Texture* text_texture;

int length;

void draw() {
    SDL_SetRenderDrawColor( render, 0, 0, 0, 255 );
    SDL_RenderClear( render );

    r.w = unit;
    r.h = unit;
    text_r.h = text_unit;

    for (i = 0; i < ELEMENT_COUNT; i++) {
        r.x = border + elements[i].x * (unit + gap);
        r.y = border + elements[i].y * (unit + gap);

        SDL_SetRenderDrawColor( render, 255, 255, 255, 255 );
		SDL_RenderDrawRect( render, &r );

        for (length = 0; elements[i].symbol[length] != '\0'; length++);
        
        text_r.w = text_unit/2 * length;
        text_r.x = r.x + unit/2 - (text_unit/2) + (length == 1 ? (text_r.w/2) : 0);
        text_r.y = r.y + unit/2 - (text_unit/2);

        text_surface = TTF_RenderText_Solid( font, elements[i].symbol, White );
        text_texture = SDL_CreateTextureFromSurface( render, text_surface );
        SDL_RenderCopy( render, text_texture, NULL, &text_r );
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

    draw();

    do {
        SDL_PollEvent( &window_event );
        SDL_Delay(10);
    }
    while ( SDL_QUIT != window_event.type );

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyWindow( window );
	SDL_Quit();
	return EXIT_SUCCESS;
}