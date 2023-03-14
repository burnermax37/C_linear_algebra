#include <stdio.h>
#include <stdlib.h>

#include "linear_construction.h"
#include "linear_base.h"
#include "linear_baseOps.h"
#include "linear_rowColOps.h"
#include "linear_gaussian.h"




//IMPORTANT: All functions index rows and columns starting with 0. That is, first row is row 0, first column is column 0



int main()
{
    cellsize = sizeof(double);

    pMatrix test1;

    double test_values[9] = {0,3,6,0,0,0,0,8,3};

    test1 = build_pMatrix(3,3, test_values);

    printMatrix(test1);



    return 0;
}
