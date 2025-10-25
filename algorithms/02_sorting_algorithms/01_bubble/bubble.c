#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubble_sort(char *item, int count)
{
    char temporary;

    for (int a = 0; a < count; a++) {
        for (int b = count - 1; b >= a; b--) {
            if (item[b - 1] > item[b]) {
                temporary = item[b - 1];
                item[b - 1] = item[b];
                item[b] = temporary;
            }
        }
    }
}


int main(void)
{
    char *string = malloc(256 * sizeof(char));

    printf("Insert string: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    bubble_sort(string, strlen(string));

    printf("Bubble sorted string: %s\n", string);

    free(string);

    return 0;
}
