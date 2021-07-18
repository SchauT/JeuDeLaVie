#include "struct.h"
#include "matrix.h"
#include <err.h>
#include <stdlib.h>
#include <stdio.h>

Matrix new_mat(size_t width, size_t height)
{
    size_t size = width * height;
    if (size == 0) errx(1,"Wrong values for sizes: size = 0");
    int* m =(int *) calloc(size,sizeof(int));
    if (m==NULL) errx(1,"Calloc returned NULL");
    Matrix matrix = {width, height, m};
    
    return matrix;

}

int  mat_get(Matrix m, size_t x, size_t y)
{
    if(x>=m.cols || y>=m.rows) errx(1,"Can't get value : Coordinates not in matrix");
    size_t v_co = y*m.cols+x;

    return m.values[v_co];  
}

void mat_put(Matrix m, size_t x, size_t y, int d)
{
   if(x>= m.cols || y>= m.rows) errx(1,"Can't put value : Coordinates not in matrix"); 
   m.values[y*m.cols+x] = d;
}



int round_check(Matrix m, size_t x, size_t y)
{
    int LN = 0;

    for (size_t i = y-1; i <= y+1;i++)
    {
        for(size_t j = x-1 ; j<=x+1;j++)
        {
         if(!(i==y && j == x))
         {
            LN+=mat_get(m,i,j);
         }
        }
    }
    return LN;
    
}


void mat_rand_fill(Matrix m, size_t n)
{
    if(n <  m.cols*m.rows)
    {
        for (size_t i = 0; i < n;i++)
        {
                size_t x = rand() % m.cols;
                size_t y = rand() % m.rows;
                mat_put(m,x,y,1);
        }
    }
}




void draw_m(Matrix m)
{
    for(size_t i = 0; i< m.rows;i++)
    {
        putchar('\n');
        for (size_t j = 0; j < m.cols;j++)
        {
           printf("%i\t",mat_get(m,j,i));
        }
    }
    putchar('\n');

}



void free_mat(Matrix m)
{
    free(m.values);
}
