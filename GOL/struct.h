#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>

typedef struct Matrix
{
    size_t cols;
    size_t rows;
    int* values; 
}Matrix;
#endif
