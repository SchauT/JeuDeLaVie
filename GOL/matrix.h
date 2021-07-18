#ifndef MATRIX_H
#define MATRIX_H
#include "struct.h"
#include <stdlib.h>

Matrix new_mat(size_t width, size_t height);

int mat_get(Matrix m, size_t x, size_t y);
void mat_put(Matrix m, size_t x, size_t y, int d);

int round_check(Matrix m, size_t x,size_t y);

void mat_rand_fill(Matrix m,size_t n);

void draw_m(Matrix m);

void free_mat(Matrix m);




#endif
