#include "funcs.h"
#include <stdio.h>
#include <string.h>

struct dictionary
{
    int size;
    char matrix[STR_LEN][WORD_LEN];
};

int split_str(FILE *file_name, char *matrix[WORD_LEN], char *string)
{
    if ((matrix[0] = strtok(string, " ")) == NULL)
    {
        printf("Error: empty string.\n");
        
        return EMPTY_STRING;
    }
    
    int i = 1;
    
    while (1)
    {
        if ((matrix[i] = strtok(NULL, " ")) == NULL)
            break;
        
        i++;
    }
    
    return i;
}

void reverse(FILE *file_name, const char *string)
{
    for (int i = strlen(string) - 1; i >= 0; i--)
        fprintf(file_name, "%c", string[i]);
    
    fprintf(file_name, " ");
}
