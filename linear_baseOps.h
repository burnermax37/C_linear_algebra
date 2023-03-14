#ifndef LINEAR_BASEOPS_H_INCLUDED
#define LINEAR_BASEOPS_H_INCLUDED


#include <linear_base.h>

pMatrix scalar_multiplication(pMatrix input, double scalar);
pMatrix vector_addition(pMatrix input1, pMatrix input2);
pMatrix vector_subtraction(pMatrix input1, pMatrix input2);
double dot_product(pMatrix input1, pMatrix input2);
pMatrix matrix_multiplication(pMatrix input1, pMatrix input2);








#endif // LINEAR_BASEOPS_H_INCLUDED
