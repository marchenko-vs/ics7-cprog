#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

double average(FILE *file, double *current_num);
double variance(FILE *file, double *average);
int rule(FILE *file, double *average, double *interval);

#endif
