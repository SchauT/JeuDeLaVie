#include "matrix.h"
#include "struct.h"
#include "sdl.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


int round_test(Matrix m, size_t x, size_t y)
{
    int ln = 0;

    if(x==0)
    {
        if(y==0)
            return mat_get(m,x+1,0) + mat_get(m,x+1,1) + mat_get(m,x,1);

        if(y==m.cols-1)
            return mat_get(m,x,y-1) + mat_get(m,x+1,y-1) + mat_get(m,x+1,y);

        else
            for(size_t i = y-1; i <= y+1; i++)
                for(size_t j = x; j <= x+1; j++)
                    if(!(j==x && i==y))
                        ln += mat_get(m, j, i);
    }

    else if(x==m.rows-1)
    {
        if(y==0)
            return mat_get(m,x-1,0) + mat_get(m,x-1,1) + mat_get(m,x,1);

        if(y==m.cols-1)
            return mat_get(m,x-1,y) + mat_get(m,x-1,y-1) + mat_get(m,x,y-1);

        else
            for (size_t i = y-1;i<=y+1;i++)
                for(size_t j = x-1;j<=x;j++)
                    if(!(j==x && i==y))
                        ln += mat_get(m, j, i);
    }

    else if(y==0)
    {
        for(size_t i = 0; i <= 1; i++)
            for(size_t j = x-1; j <= x+1; j++)
                if(!(j==x && i==0))
                    ln += mat_get(m, j, i);
    }

    else if(y==m.cols-1)
    {
        for(size_t i = y-1; i <= y; i++)
            for(size_t j = x-1; j <= x+1; j++)
                if(!(j==x && i==y))
                    ln += mat_get(m, j, i);
    }

    else
        ln = round_check(m, x, y);

    return ln;

}


Matrix Game_Of_Life(Matrix m)
{
    int alive_cell = 0;
    int ln = 0;
    Matrix nm = new_mat(m.cols,m.rows);

    for(size_t i = 0; i < m.rows; i++)
    {
        for (size_t j = 0; j < m.cols;j++)
        {
            ln = round_test(m, j, i);

            if(ln == 3)
            {
                mat_put(nm, j, i, 1);
                alive_cell++;
            }

            else if(ln == 2)
            {
                if(mat_get(m, j, i))
                {
                    mat_put(nm, j, i, 1);
                    alive_cell++;
                }
            }
        }
    }

    free_mat(m);

    if(!(alive_cell))
        errx(1, "End of game of life : no alive cells left");

    return nm;
}






int main(void)
{
    int i = 0;
    InitSDL();
    SDL_Window *window = OpenWindow();
    SDL_Renderer *renderer = CreateRenderer(window);


    Matrix m = new_mat(80, 80);
    mat_rand_fill(m, 1000);

    /*
    m.values[2*m.cols+3] = 1;
    m.values[2*m.cols+4] = 1;
    m.values[3*m.cols+3] = 1;
    m.values[3*m.cols+4] = 1;
    */

    while (i < 150)
    {
        //draw_m(m);
        DrawMatrix(renderer, m);
        m = Game_Of_Life(m);
        i++;
    }

    free_mat(m);
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
