#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binary(char *item, int count, char key)
{
    int low, high, mid;

    low = 0;
    high = count - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key < item[mid]) {
            high = mid - 1;
        } else if (key > item[mid]) {
            low = mid + 1;
        } else {
            return mid; // O Valor foi encontrado.
        }
    }

    return -1; // Não há correspondência
}


int main(void)
{
    char *string = malloc(256 * sizeof(char));
    char c;
    char ch;

    printf("Insert a string for analysis: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    printf("Insert the key you want to search: ");
    scanf("%c", &ch);

    int result = binary(string, strlen(string) - 1, ch);

    if (result < 0)  printf("No result found!\n");
    else printf("Key [%c] is in position: %d\n", ch, result);

    free(string);

    return 0;
}
