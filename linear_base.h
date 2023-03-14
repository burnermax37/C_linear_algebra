#ifndef LINEAR_BASE_H_INCLUDED
#define LINEAR_BASE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Macro to facilitate making loops
#define FOR(x,y) for(int x = 0; x < y; x++)




int cellsize;


//Struct for basic matrix; stores doubles
typedef struct{
    int rows;
    int columns;
    double *elements;
}pMatrix;



void printMatrix(pMatrix input);
double get_value(pMatrix input, int row, int column);






#endif // LINEAR_BASE_H_INCLUDED
