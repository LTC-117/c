#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertion_sort(char *item, int count)
{
    register int a, b;
    char temporary;

    for (a = 1; a < count; a++) {
        // armazena o item atual pois ele vai sumir
        // (todas as variáveis vão subir uma posição)
        temporary = item[a];
        for (b = (a - 1); b >= 0 && temporary < item[b]; b--) {
            item[b + 1] = item[b];
        }

        item[b + 1] = temporary;
    }
}


int main(void)
{
    char *string = malloc(256 * sizeof(string));

    printf("Insert string: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    insertion_sort(string, strlen(string));

    printf("Insertion sorted string: %s\n", string);

    free(string);

    return 0;
}
