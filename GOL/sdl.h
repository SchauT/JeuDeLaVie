#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include "struct.h"


void InitSDL(void);

SDL_Window* OpenWindow(void);

SDL_Renderer* CreateRenderer(SDL_Window *window);

void DrawMatrix(SDL_Renderer *renderer, Matrix m);


#endif
