#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void shell(char *item, int count)
{
    register int i, j, gap, k;
    char x, inc[5]; // inc -> increments

    inc[0] = 9; inc[1] = 5; inc[2] = 3; inc[3] = 2; inc[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = inc[k];
        for (i = gap; i < count; i++) {
            x = item[i];
            for (j = i - gap; x < item[j] && j >= 0; j -= gap)
                item[j + gap] = item[j];
            item[j + gap] = x;
        }
    }
}


int main(void)
{
    char *string = malloc(256 * sizeof(char));

    printf("Insert string: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    shell(string, strlen(string));

    printf("Shell sorted string: %s\n", string);

    free(string);

    return 0;
}
