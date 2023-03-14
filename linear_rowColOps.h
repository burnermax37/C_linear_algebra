#ifndef LINEAR_ROWCOLOPS_H_INCLUDED
#define LINEAR_ROWCOLOPS_H_INCLUDED


#include <linear_base.h>
#include <linear_construction.h>

pMatrix rowOpOut_multiply(pMatrix input, int row_index, double scalar);
void rowOpIn_multiply(pMatrix input, int row_index, double scalar);

pMatrix rowOpOut_add(pMatrix input, int row_source, int row_target, double scalar);
void rowOpIn_add(pMatrix input, int row_source, int row_target, double scalar);

void rowOpIn_swap(pMatrix input, int row1, int row2);
pMatrix rowOpOut_swap(pMatrix input, int row1, int row2);

void colOpIn_multiply(pMatrix input, int col_target, double scalar);
pMatrix colOpOut_multiply(pMatrix input, int col_target, double scalar);

void colOpIn_add(pMatrix input, int col_source, int col_target, double scalar);
pMatrix colOpOut_add(pMatrix input, int col_source, int col_target, double scalar);

void colOpIn_swap(pMatrix input, int col1, int col2);
pMatrix colOpOut_swap(pMatrix input, int col1, int col2);


#endif // LINEAR_ROWCOLOPS_H_INCLUDED
