#include "funcs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *input_file;
    
    if ((input_file = fopen("in.txt", "r")) == NULL)
    {
        printf("Error: file does not exist.\n");
        
        return FILE_NOT_EXIST;
    }
    
    char buffer[STR_LEN];
    
    fgets(buffer, STR_LEN, input_file);
    buffer[strlen(buffer) - 1] = '\0';
    
    if (strlen(buffer) >= STR_LEN - 3)
    {
        printf("Error: too long string.\n");
        
        return LENGTH_ERROR;
    }
    
    char *words[WORD_LEN];
    
    int size = split_str(input_file, words, buffer);
    
    if (size == EMPTY_STRING)
        return EMPTY_STRING;
    
    FILE *output_file;
    
    output_file = fopen("out.txt", "w");
    
    for (int i = size - 1; i >= 0; i--)
        reverse(output_file, words[i]);
    
    fprintf(output_file, "\n");
    
    fclose(input_file);
    fclose(output_file);
    
    return EXIT_SUCCESS;
}
