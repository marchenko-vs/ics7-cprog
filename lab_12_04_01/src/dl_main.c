#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ERR_KEY_NUMBER -1
#define ERR_FILE_OPEN -2
#define ERR_EMPTY_FILE -3
#define ERR_MEMORY_ALLOC -4
#define ERR_DYNAMIC_LIB -5
#define ERR_DATA_TYPE -6
#define ERR_EMPTY_ARRAY -7

typedef int (__cdecl *fn_get_array_size_t)(FILE *);
typedef int *(__cdecl *fn_create_array_t)(FILE *, const int);
typedef void (__cdecl *fn_fprint_array_t)(FILE *, int *, int *);
typedef int (__cdecl *fn_key_t)(const int *, const int, int *, int *);
typedef void (__cdecl *fn_mysort_t)(void *, size_t, size_t, 
int (*compar)(const void *, const void *));

int compare(const void *a, const void *b);

int main(int argc, char **argv)
{
    HMODULE hlib;
    fn_get_array_size_t get_array_size;
    fn_create_array_t create_array;
    fn_fprint_array_t fprint_array;
    fn_key_t key;
    fn_mysort_t mysort;

    hlib = LoadLibrary("array.dll");

    if (!hlib)
        return EXIT_FAILURE;

    if ((argc < 3 || argc > 4) || (argc == 4 && strcmp(argv[3], "f") != 0))
        return ERR_KEY_NUMBER;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return ERR_FILE_OPEN;

    int array_size = 0, rc = 0;

    get_array_size = (fn_get_array_size_t)GetProcAddress(hlib, 
        "get_array_size");

    if (!get_array_size)
    {
        FreeLibrary(hlib);

        return ERR_DYNAMIC_LIB;
    }

    if ((array_size = get_array_size(input_file)) == ERR_DATA_TYPE)
    {
        fclose(input_file);
        FreeLibrary(hlib);

        return ERR_DATA_TYPE;
    }

    if (array_size == 0)
    {
        fclose(input_file);
        FreeLibrary(hlib);

        return ERR_EMPTY_FILE;
    }

    int *array_begin = NULL;
    create_array = (fn_create_array_t)GetProcAddress(hlib, "create_array");

    if (!create_array)
    {
        FreeLibrary(hlib);

        return ERR_DYNAMIC_LIB;
    }

    if ((array_begin = create_array(input_file, array_size)) == NULL)
    {
        fclose(input_file);
        FreeLibrary(hlib);

        return ERR_MEMORY_ALLOC;
    }

    fclose(input_file);

    
    mysort = (fn_mysort_t)GetProcAddress(hlib, "mysort");

    if (!mysort)
    {
        free(array_begin);
        FreeLibrary(hlib);

        return ERR_DYNAMIC_LIB;
    }

    fprint_array = (fn_fprint_array_t)GetProcAddress(hlib, "fprint_array");

    if (!fprint_array)
    {
        free(array_begin);
        FreeLibrary(hlib);

        return ERR_DYNAMIC_LIB;
    }

    FILE *output_file = fopen(argv[2], "w");

    if (argc == 4)
    {
        int new_size = array_size;
        int *beg = malloc(array_size * sizeof(int));

        if (!beg)
        {
            fclose(output_file);
            free(array_begin);
            FreeLibrary(hlib);

            return ERR_MEMORY_ALLOC;
        }

        key = (fn_key_t)GetProcAddress(hlib, "key");

        if (!key)
        {
            fclose(output_file);
            free(array_begin);
            FreeLibrary(hlib);

            return ERR_DYNAMIC_LIB;
        }

        rc = key(array_begin, array_size, beg, &new_size);

        if (rc == EXIT_FAILURE)
        {
            int *tmp = realloc(beg, new_size);

            if (!tmp)
            {
                fclose(output_file);
                free(array_begin);
                FreeLibrary(hlib);

                return ERR_MEMORY_ALLOC;
            }

            beg = tmp;

            rc = key(array_begin, array_size, beg, &new_size);
        }

        if (rc != EXIT_SUCCESS)
        {
            fclose(output_file);
            free(array_begin);
            free(beg);
            FreeLibrary(hlib);

            return ERR_EMPTY_ARRAY;
        }

        mysort(beg, new_size, sizeof(int), compare);
        fprint_array(output_file, beg, beg + new_size);
        free(beg);
        free(array_begin);
        fclose(output_file);
        FreeLibrary(hlib);
    }
    else
    {
        mysort(array_begin, array_size, sizeof(int), compare);
        fprint_array(output_file, array_begin, array_begin + array_size);
        free(array_begin);
        fclose(output_file);
        FreeLibrary(hlib);
    }

    return EXIT_SUCCESS;
}

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;

    if (*(int *)a < *(int *)b)
        return -1;

    return 0;
}
