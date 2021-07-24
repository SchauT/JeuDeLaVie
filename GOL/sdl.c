#include "matrix.h"
#include "struct.h"
#include "sdl.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int PIXSIZE = 10;

void InitSDL(void)
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        errx(1, "Erreur SDL_Init : %s", SDL_GetError());
}

SDL_Window* OpenWindow(void) // Creates a window of 800*800
{
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("** Game Of Life **", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);

    if(NULL == window)
        errx(1, "Erreur SDL_CreateWindow : %s", SDL_GetError());

    return window;
}

SDL_Renderer* CreateRenderer(SDL_Window *window)
{
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    
    if(NULL == renderer)
        errx(1, "Erreur SDL_CreateRenderer : %s", SDL_GetError());

    return renderer;
}

void CursedColor(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 255); 
}

void DrawPoint(SDL_Renderer *renderer, size_t x, size_t y)
{
    for(size_t i = y; i < y+PIXSIZE; i++)
        for(size_t j = x; j < x+PIXSIZE; j++)
        {
            //CursedColor(renderer); // cringe
            SDL_RenderDrawPoint(renderer, j, i);
        }
}

void DrawMatrix(SDL_Renderer *renderer, Matrix m)
{
    if(0 != SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)) // Black background
        errx(1, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());

    if(0 != SDL_RenderClear(renderer))
        errx(1, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //White points
    for(size_t y = 0; y < m.rows; y++)
    {
        for(size_t x = 0; x < m.cols; x++)
        {
            if(m.values[y*m.cols+x] == 1)
            {
                CursedColor(renderer); // cricricriiiiiinge
                DrawPoint(renderer, x*PIXSIZE, y*PIXSIZE);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(100); // Iteration time
}
