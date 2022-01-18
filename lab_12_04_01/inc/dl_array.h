#ifndef _DL_ARRAY_H_
#define _DL_ARRAY_H_

#ifdef ARRAY_EXPORTS
#define ARRAY_DLL __declspec(dllexport)
#else
#define ARRAY_DLL __declspec(dllimport)
#endif

#define ARRAY_DECL __cdecl

#define ERR_NULL_POINTER -1
#define ERR_ZERO_SIZE -2
#define ERR_EMPTY_ARRAY -3
#define ERR_SMALL_DESTINATION_SIZE -4
#define ERR_DATA_TYPE -5

ARRAY_DLL int ARRAY_DECL get_array_size(FILE *filename);
ARRAY_DLL int ARRAY_DECL *create_array(FILE *filename, const int size);
ARRAY_DLL void ARRAY_DECL fprint_array(FILE *filename, int *ptr_begin, 
int *ptr_end);
ARRAY_DLL int ARRAY_DECL key(const int *pb_src, const int src_len, 
int *pb_dst, int *dst_len);

#endif // _DL_ARRAY_H_
