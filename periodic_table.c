#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL2/SDL_ttf.h>

#include "elements.h"

SDL_Window *window;
SDL_Renderer *render;
SDL_Event window_event;

TTF_Font *courier_new_24 = NULL,
         *courier_new_12 = NULL;

int mouse_x,
    mouse_y,
    window_x,
    window_y,
    window_mouse_x,
    window_mouse_y;

const unsigned int
    border = 10,
    unit = 64,
    text_unit_12 = 14,
    text_unit_24 = 28,
    gap = 2;

unsigned short int
    i,
    j,
    width,
    height,
    length;

void awake()
{
    courier_new_24 = TTF_OpenFont("courier_new.ttf", 24);
    if (!courier_new_24)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    courier_new_12 = TTF_OpenFont("courier_new.ttf", 12);
    if (!courier_new_12)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    width = (border * 2) + (unit * COLS) + (gap * COLS);
    height = (border * 2) + (unit * ROWS) + (gap * ROWS);
}

SDL_Rect r;
SDL_Color white = {255, 255, 255, 255};

SDL_Surface *text_surface;
SDL_Color color;

char str_atomic_number[4];

SDL_Texture *text_textures[ELEMENT_COUNT];

void start()
{
    for (i = 0; i < ELEMENT_COUNT; i++) {
        sprintf(str_atomic_number, "%hi", i + 1);
        for (length = 0; str_atomic_number[length] != '\0'; length++);

        text_surface = TTF_RenderText_Solid(courier_new_12, str_atomic_number, color);
        text_textures[i] = SDL_CreateTextureFromSurface(render, text_surface);
    }
}

void draw()
{
    SDL_RenderClear(render);

    for (i = 0; i < ELEMENT_COUNT; i++)
    {
        r.w = unit;
        r.h = unit;
        r.x = border + elements[i].x * (unit + gap);
        r.y = border + elements[i].y * (unit + gap);

        if (window_mouse_x > r.x && window_mouse_y > r.y && window_mouse_x < r.x + unit && window_mouse_y < r.y + unit)
            color = white;
        else
            color = category_to_color(elements[i].category);

        color.a = 255;

        SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(render, &r);

        r.w = text_unit_12;
        r.h = text_unit_12;
        r.x = r.x + 2;
        r.y = r.y + 2;

        SDL_RenderCopy(render, text_textures[i], NULL, &r);

        /*
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
        // */
    }

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
}

void end() {
    for (i = 0; i < ELEMENT_COUNT; i++) {
    SDL_DestroyTexture(text_textures[i]);
    }
    SDL_FreeSurface(text_surface);
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    awake();

    window = SDL_CreateWindow("SOLAR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == ((void *)0))
    {
        printf("Error creating window: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == ((void *)0))
    {
        printf("Error creating renderer: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);

    int running = true;

    start();
    while (true)
    {
        printf("loop\n");
        while (SDL_PollEvent(&window_event))
        {
            if (SDL_QUIT == window_event.type)
            {
                running = false;
            }
        }

        if (!running)
            break;

        SDL_GetWindowPosition(window, &window_x, &window_y);
        SDL_GetGlobalMouseState(&mouse_x, &mouse_y);
        window_mouse_x = mouse_x - window_x;
        window_mouse_y = mouse_y - window_y;

        draw();
    }
    end();

    TTF_CloseFont(courier_new_24);
    TTF_Quit();

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}