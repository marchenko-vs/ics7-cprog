#ifndef _ARRAY_H_

#define _ARRAY_H_

#define DATA_TYPE_ERROR -1
#define EMPTY_ARRAY_ERROR -2
#define MEMORY_ALLOC_ERROR -3

int get_array_size(FILE *filename);
int *create_array(FILE *filename, const int size);
void fprint_array(FILE *filename, int *ptr_begin, int *ptr_end);
double count_average(const int *begin, const int *end);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
