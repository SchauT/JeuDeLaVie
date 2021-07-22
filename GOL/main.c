#include "matrix.h"
#include "struct.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


int round_test(Matrix m, size_t x, size_t y)
{
    int ln = 0;
    if( x==0 || x==m.rows-1 || y==0 || y==m.cols-1 )
    {
        if(x==0)
        {
            if(y==0) return mat_get(m,x+1,y)+mat_get(m,x+1,y+1)+mat_get(m,x,y+1);
 
            if(y==m.cols-1) return mat_get(m,x,y-1)+mat_get(m,x+1,y-1)+mat_get(m,x+1,y);
           
            else
            {
                for(size_t i = y-1; i<=y+1; i++)
                {
                    for(size_t j = x;j<=x+1;j++ )
                    {
                        if(!(i==x && j==y))
                            ln+=mat_get(m,i,j);
                    }
                }
            }
        }
        if(x==m.rows-1)
        {
            if(y==0) return mat_get(m,x-1,y)+mat_get(m,x-1,y+1)+mat_get(m,x,y+1);
           
            if(y==m.cols-1) return mat_get(m,x-1,y)+mat_get(m,x-1,y-1)+mat_get(m,x,y-1);

            else
            {
                for (size_t i = y-1;i<=y+1;i++)
                {
                    for(size_t j = x-1;j<=x;j++)
                    {
                        if(!(i==x && j==y))
                            ln+= mat_get(m,i,j);

                    }
                }
            }
        }
        if(y==0)
        {
            for(size_t i = y; i<=y+1;i++)
            {
                for(size_t j = x-1;j<=x+1;j++)
                {
                    if(!(i==x && j==y))
                    ln+=mat_get(m,i,j);
                }
            }

        }
        if(y==m.cols-1)
        {
            for(size_t i=y-1;i<=y;i++)
            {
                for(size_t j=x-1;j<=x+1;j++)
                {
                    if(!(i==x&&j==y))
                    ln+=mat_get(m,i,j);
                }
            }
        }
    }
    else
    {
        ln = round_check(m,x,y);
    }

    return ln;

}


Matrix Game_Of_Life(Matrix m)
{
    int alive_cell = 0;
    int ln = 0;
    Matrix nm = new_mat(m.cols,m.rows);

    for(size_t i =0;i<m.rows;i++)
    {
        for (size_t j = 0; j<m.cols;j++)
        {
            //printf("[ %zu,%zu ] : %i\n",i,j,round_test(m,j,i));
            ln = round_test(m,j,i);
            if(mat_get(m,j,i))
            {
                if(ln<2 || ln > 3) mat_put(nm,j,i,0);
                alive_cell++;
            }
            else
            {
                if(ln == 2) mat_put(nm,j,i,1);
            }
        }
    }
    free_mat(m);

    if(!(alive_cell))
    {
        errx(1,"End of game of life : no alive cells left");
    }

    return nm;
}






int main(void)
{
    if(0 != SDL_Init(SDL_INIT_TIMER))
        errx(1,"Initialisation of SDL_INIT_TIMER failed");
    

    Matrix m = new_mat(5,5);
    mat_rand_fill(m,10);

    while (1)
    {
        m = Game_Of_Life(m);
        draw_m(m);
    }

    free_mat(m);

    
    SDL_Quit();
    
    return 0;
}
