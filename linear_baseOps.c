#include <stdio.h>
#include <linear_base.h>
#include <linear_construction.h>

//Scalar multiplication
pMatrix scalar_multiplication(pMatrix input, double scalar){
    //Declare variables
    int cellcount = input.rows*input.columns;

    double * ePoint;

    //Set pointer
    ePoint = input.elements;

    //Perform multiplication
    FOR(i,cellcount){
        *ePoint = *ePoint * scalar;
        ++ePoint;
    }

    return input;
}










//Vector Addition
pMatrix vector_addition(pMatrix input1, pMatrix input2){
    pMatrix output;
    output.columns = 0;
    output.rows = 0;

    if(input1.rows == input2.rows){
        if(input1.columns == input2.columns){

            //Declare variables
            int cellcount = input1.columns*input1.rows;

            double * ePoint_target;
            double * ePoint_source;


            output = copy_matrix(input1); //Make output as a copy of first input matrix


            ePoint_target = output.elements; //target ePoint points to output values
            ePoint_source = input2.elements; //source ePoint points to values of second input


            //Add values of second input matrix to values of output matrix
            FOR(i,cellcount){
                    *ePoint_target += *ePoint_source;
                    ++ePoint_target;
                    ++ePoint_source;
            }

        }
    }else{
        printf("Matrices do not have matching size\n");
    }


    return output;

}


//Vector Subtraction
pMatrix vector_subtraction(pMatrix input1, pMatrix input2){
    pMatrix output;
    output.columns = 0;
    output.rows = 0;

    if(input1.rows == input2.rows){
        if(input1.columns == input2.columns){

            //Declare variables
            int cellcount = input1.columns*input1.rows;

            double * ePoint_target;
            double * ePoint_source;


            output = copy_matrix(input1); //Make output as a copy of first input matrix


            ePoint_target = output.elements; //target ePoint points to output values
            ePoint_source = input2.elements; //source ePoint points to values of second input


            //Add values of second input matrix to values of output matrix
            FOR(i,cellcount){
                    *ePoint_target -= *ePoint_source;
                    ++ePoint_target;
                    ++ePoint_source;
            }

        }
    }else{
        printf("Matrices do not have matching size\n");
    }


    return output;

}


//Dot Product
double dot_product(pMatrix input1, pMatrix input2){
    double output = 0;
    double hold;
    double * ePointer1;
    double * ePointer2;


    ePointer1 = input1.elements;
    ePointer2 = input2.elements;

    //Horizontal vectors
    if((input1.rows == 1)&&(input2.rows == 1)){
        if(input1.columns == input2.columns){
            FOR(i,input1.columns){
                hold = (*ePointer1)*(*ePointer2);
                output = output + hold;

                ePointer1++;
                ePointer2++;
            }

        }else{
            printf("Element numbers do not match");
        }
    }
    //Vertical Vectors
     else if((input1.columns == 1)&&(input2.columns == 1)){
        if(input1.rows == input2.rows){
            FOR(i, input1.rows){
                hold = (*ePointer1)*(*ePointer2);
                output = output + hold;

                ePointer1++;
                ePointer2++;
            }
        } else{
            printf("Element numbers do not match");

        }
    }else{
        printf("Not horizontal or vertical vectors");
    }

    return output;
}



//Matrix Multiplication



pMatrix matrix_multiplication(pMatrix input1, pMatrix input2){
    pMatrix output;
    output.rows = 0;
    output.columns = 0;

    //Ensure matrices match
    if(input1.columns == input2.rows){
        //Declare variables
        int n = 0;
        double hold;


        double value_hold[(input1.rows)*(input2.columns)];



        FOR(i, input1.rows){    //For each row of left matrix
            FOR(j, input2.columns){//For each column of right matrix
                hold = 0;
                FOR(k, input1.columns){ //For each element k in the row and column
                    //Get left_in + right_nj
                    hold = hold + get_value(input1, i+1, k+1)*get_value(input2, k+1, j+1);
                }
                value_hold[n] = hold;
                n++;
            }
        }

        //Build matrix
        output = build_pMatrix(input1.rows, input2.columns, value_hold);

    }else{
        printf("Matrix dimensions are incompatible\n");
    }

    return output;
}



