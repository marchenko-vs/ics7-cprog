#ifndef _ARRAY_H_
#define _ARRAY_H_

#define ERR_NULL_POINTER -1
#define ERR_ZERO_SIZE -2
#define ERR_EMPTY_ARRAY -3
#define ERR_SMALL_DESTINATION_SIZE -4
#define ERR_DATA_TYPE -5

int get_array_size(FILE *filename);
int *create_array(FILE *filename, const int size);
void fprint_array(FILE *filename, int *ptr_begin, int *ptr_end);
int key(const int *pb_src, const int src_len, int *pb_dst, int *dst_len);

#endif // _ARRAY_H_
