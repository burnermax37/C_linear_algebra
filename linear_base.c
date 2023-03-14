#include <stdio.h>
#include "linear_base.h"


//Printing matrices to output


void printMatrix(pMatrix input){
    //Declare variables
    double * ePoint = input.elements;


    //Print values
    FOR(i, input.rows){
        printf("|");
        FOR(j,input.columns){
            printf("%.2f", *ePoint);
            if(j < (input.columns - 1)){
                printf(" ");
            }
            ++ePoint;
        }
        printf("|\n");
    }
    printf("\n");
}







//Function to retrieve value at specified element from pMatrix
double get_value(pMatrix input, int row, int column){
    double * ePoint;


    ePoint = input.elements;

    //Set pointer to start of indicated row
    ePoint += input.columns*(row-1);

    //Set pointer to indicated column
    ePoint += (column - 1);

    return *ePoint;

}

