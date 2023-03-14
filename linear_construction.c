#include <stdio.h>
#include "linear_base.h"

pMatrix build_pMatrix(int rownum, int colnum, double values[]){
    int cellcount = rownum*colnum;


    double * ePoint;

    pMatrix out;

    out.rows = rownum;
    out.columns = colnum;
    out.elements =  (double*)malloc(cellsize*colnum*rownum);


    ePoint = out.elements;



    //Fill in values
    FOR(i, cellcount){
        *ePoint = values[i];
        ++ePoint;
    }



    return out;
}



pMatrix copy_matrix(pMatrix input){
    int cellcount = input.rows*input.columns;
    double * ePointer;
    double values_hold[input.columns*input.rows];
    pMatrix output;


    //Set pointer
    ePointer = input.elements;

    //Extract values

    FOR(i, cellcount){
        values_hold[i] = *ePointer;
        ++ePointer;
    }



    //Create copy matrix
    output = build_pMatrix(input.rows, input.columns, values_hold);


    return output;
}
