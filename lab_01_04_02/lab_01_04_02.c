#include <stdio.h>
#include <stdlib.h>

#define SECONDS 60

int main(void)
{
    int hours, minutes, seconds, input_seconds;

    printf("Enter the number of seconds\n");
    scanf("%i", &input_seconds);

    hours = input_seconds / (SECONDS * SECONDS);
    input_seconds %= (SECONDS * SECONDS);
    minutes = input_seconds / SECONDS;
    seconds = input_seconds % SECONDS;

    printf("HH : MM : SS\n");
    printf("%i : %i : %i", hours, minutes, seconds);

    return EXIT_SUCCESS;
}