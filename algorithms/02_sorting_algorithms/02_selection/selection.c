#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void selection_sort(char *item, int count)
{
    int c;
    int exchange;
    char temp;

    for (int a = 0; a < count - 1; a++) {
        exchange = 0;
        c = a;
        temp = item[a];
        for (int b = a + 1; b < count; b++) {
            if (item[b] < temp) {
                c = b;
                temp = item[b];
                exchange = 1;
            }
        }
        if (exchange) {
            item[c] = item[a];
            item[a] = temp;
        }
    }
}


int main(void)
{
    char *string = malloc(256 * sizeof(string));

    printf("Insert string: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    selection_sort(string, strlen(string));

    printf("Selection sorted string: %s\n", string);

    free(string);

    return 0;
}
