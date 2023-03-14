#include <stdio.h>
#include <stdlib.h>
#include "linear_base.h"
#include "linear_construction.h"
#include "linear_baseOps.h"

//Row Operations; first row is indexed as 0

pMatrix rowOpOut_multiply(pMatrix input, int row_index, double scalar){ //Multiply a specified row by a scalar; this version creates a new matrix

    int rowsize;

    pMatrix output;
    double* ePoint;


    output = copy_matrix(input); //Create output matrix


    rowsize = cellsize*output.columns; //Calculate size of one row in memory

    ePoint = output.elements + (rowsize*row_index); //Set pointer to appropriate row of output matrix

    //For each column, each entry in row, multiply entry by scalar
    FOR(i, output.columns){
        *ePoint = (*ePoint)*scalar;
        ePoint++;
    }

    return output;
}

void rowOpIn_multiply(pMatrix input, int row_index, double scalar){ //Multiply a specified row by a scalar; this version modifies input matrix
    int rowsize;

    double* ePoint;


    rowsize = input.columns; //Calculate size of one row in memory

    ePoint = input.elements + (rowsize*row_index); //Set pointer to start of appropriate row of input matrix

    FOR(i, input.columns){
        *ePoint = (*ePoint)*scalar;
        ePoint++;
    }


}

/*
   Functions to multiply values of one row by a scalar, and add that to another row. One version makes new matrix, other modifies existing matrix
*/




pMatrix rowOpOut_add(pMatrix input, int row_source, int row_target, double scalar){
    int rowsize = input.columns;

    double* source_ePoint;
    double * target_ePoint;

    pMatrix output = copy_matrix(input);





    source_ePoint = input.elements + (row_source*rowsize); //Set source pointer to source row of input matrix
    target_ePoint = output.elements + (row_target*rowsize); //Set target pointer to target row of output matrix


    //For each column (for each entry in row), multiply value of source row entry by scalar, and add that to target row entry
    FOR(i, input.columns){
        *target_ePoint += (*source_ePoint)*scalar;
        target_ePoint++;
        source_ePoint++;
    }

    return output;
}




void rowOpIn_add(pMatrix input, int row_source, int row_target, double scalar){
    int rowsize = input.columns;

    double* source_ePoint;
    double * target_ePoint;




    source_ePoint = input.elements + (row_source*rowsize); //Set source pointer to source row of input matrix
    target_ePoint = input.elements + (row_target*rowsize); //Set target pointer to target row of output matrix


    //For each column (for each entry in row), multiply value of source row entry by scalar, and add that to target row entry
    FOR(i, input.columns){
        *target_ePoint += (*source_ePoint)*scalar;
        target_ePoint++;
        source_ePoint++;
    }

}



//Functions to swap values of two rows

void rowOpIn_swap(pMatrix input, int row1, int row2){
    double* ePoint1;
    double* ePoint2;
    double* hold_base;
    double* hold_point;


    //Create hold, memory area to store values during swap
    hold_base = malloc(input.columns*cellsize); //Stores location of start of hold
    hold_point = hold_base; //Tracks movement through hold

    ePoint1 = input.elements + (row1*input.columns); //set first pointer to point at first row

    FOR(i, input.columns){ //copy values of row1 to hold
        *hold_point = *ePoint1;
        ++hold_point;
        ++ePoint1;
    }

    ePoint1 = input.elements + (row1*input.columns); //Reset first pointer
    ePoint2 = input.elements + (row2*input.columns); //Set second pointer to point at row 2

    FOR(i, input.columns){ //Copy values of second row to first row
        *ePoint1 = *ePoint2;
        ++ePoint1;
        ++ePoint2;
    }

    //Copy values of hold to second row
    hold_point = hold_base; //Reset hold pointer to start of hold
    ePoint2 = input.elements + (row2*input.columns); //Reset pointer two to start of second row

    FOR(i, input.columns){
        *ePoint2 = *hold_point;
        ++ePoint2;
        ++hold_point;
    }


}


pMatrix rowOpOut_swap(pMatrix input, int row1, int row2){
    double* ePoint1;
    double* ePoint2;
    double* hold_base;
    double* hold_point;

    pMatrix output = copy_matrix(input);



    //Create hold, memory area to store values during swap
    hold_base = malloc(input.columns*cellsize); //Stores location of start of hold
    hold_point = hold_base; //Tracks movement through hold

    ePoint1 = output.elements + (row1*input.columns); //set first pointer to point at first row

    FOR(i, input.columns){ //copy values of row1 to hold
        *hold_point = *ePoint1;
        ++hold_point;
        ++ePoint1;
    }

    ePoint1 = output.elements + (row1*input.columns); //Reset first pointer
    ePoint2 = output.elements + (row2*input.columns); //Set second pointer to point at row 2

    FOR(i, input.columns){ //Copy values of second row to first row
        *ePoint1 = *ePoint2;
        ++ePoint1;
        ++ePoint2;
    }

    //Copy values of hold to second row
    hold_point = hold_base; //Reset hold pointer to start of hold
    ePoint2 = output.elements + (row2*input.columns); //Reset pointer two to start of second row

    FOR(i, input.columns){
        *ePoint2 = *hold_point;
        ++ePoint2;
        ++hold_point;
    }

    return output;

}







//Multiply a target column by a function
void colOpIn_multiply(pMatrix input, int col_target, double scalar){
    double* ePoint;

    ePoint = input.elements + col_target; //set pointer to top of target column

    FOR(i, input.rows){
        *ePoint *= scalar;
        ePoint += input.columns;
    }
}


pMatrix colOpOut_multiply(pMatrix input, int col_target, double scalar){

    pMatrix output = copy_matrix(input);
    double* ePoint;

    ePoint = output.elements + col_target; //set pointer to top of target column

    FOR(i, output.rows){
        *ePoint *= scalar;
        ePoint += output.columns;
    }

    return output;
}




//Functions to add a multiple of one column to another column
void colOpIn_add(pMatrix input, int col_source, int col_target, double scalar){

    double* source_ePoint;
    double * target_ePoint;


    source_ePoint = input.elements + col_source; //Set source pointer to source column of input matrix
    target_ePoint = input.elements + col_target; //Set target pointer to target row of output matrix


    //For each column (for each entry in row), multiply value of source row entry by scalar, and add that to target row entry
    FOR(i, input.rows){
        *target_ePoint += (*source_ePoint)*scalar;
        target_ePoint += input.columns;
        source_ePoint += input.columns;
    }

}



pMatrix colOpOut_add(pMatrix input, int col_source, int col_target, double scalar){

    double* source_ePoint;
    double * target_ePoint;

    pMatrix output = copy_matrix(input);


    source_ePoint = output.elements + col_source; //Set source pointer to source column of input matrix
    target_ePoint = output.elements + col_target; //Set target pointer to target row of output matrix


    //For each column (for each entry in row), multiply value of source row entry by scalar, and add that to target row entry
    FOR(i, output.rows){
        *target_ePoint += (*source_ePoint)*scalar;
        target_ePoint += output.columns;
        source_ePoint += output.columns;
    }

    return output;

}




//Functions to swap two matrix columns
void colOpIn_swap(pMatrix input, int col1, int col2){
    double* ePoint1;
    double* ePoint2;
    double* hold_base;
    double* hold_point;


    //Create hold, memory area to store values during swap
    hold_base = malloc(input.rows*cellsize); //Stores location of start of hold
    hold_point = hold_base; //Tracks movement through hold

    ePoint1 = input.elements + col1; //set first pointer to point at first column

    FOR(i, input.rows){ //copy values of column 1 to hold
        *hold_point = *ePoint1;
        ++hold_point;
        ePoint1 += input.columns;
    }



    ePoint1 = input.elements + col1; //Reset first pointer
    ePoint2 = input.elements + col2; //Set second pointer to point at column 2

    FOR(i, input.rows){ //Copy values of second column to first row
        *ePoint1 = *ePoint2;
        ePoint1 += input.columns;
        ePoint2 += input.columns;
    }


    //Copy values of hold to second row
    hold_point = hold_base; //Reset hold pointer to start of hold
    ePoint2 = input.elements + col2; //Reset pointer two to start of second row

    FOR(i, input.rows){
        *ePoint2 = *hold_point;
        ePoint2 += input.columns;
        ++hold_point;
    }


}


pMatrix colOpOut_swap(pMatrix input, int col1, int col2){
    double* ePoint1;
    double* ePoint2;
    double* hold_base;
    double* hold_point;

    pMatrix output = copy_matrix(input);


    //Create hold, memory area to store values during swap
    hold_base = malloc(input.rows*cellsize); //Stores location of start of hold
    hold_point = hold_base; //Tracks movement through hold

    ePoint1 = output.elements + col1; //set first pointer to point at first column

    FOR(i, input.rows){ //copy values of column 1 to hold
        *hold_point = *ePoint1;
        ++hold_point;
        ePoint1 += input.columns;
    }



    ePoint1 = output.elements + col1; //Reset first pointer
    ePoint2 = output.elements + col2; //Set second pointer to point at column 2

    FOR(i, input.rows){ //Copy values of second column to first row
        *ePoint1 = *ePoint2;
        ePoint1 += input.columns;
        ePoint2 += input.columns;
    }


    //Copy values of hold to second row
    hold_point = hold_base; //Reset hold pointer to start of hold
    ePoint2 = output.elements + col2; //Reset pointer two to start of second row

    FOR(i, input.rows){
        *ePoint2 = *hold_point;
        ePoint2 += input.columns;
        ++hold_point;
    }

    return(output);

}


