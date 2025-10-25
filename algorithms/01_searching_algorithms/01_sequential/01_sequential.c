#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sequential(char *item, int count, char key)
{
    for (int i = 0; i < count; i++) {
        if (item[i] == key)  return i; // Retorna a posição correspondente.
    }

    return -1; // Retorno indicativo de nenhuma posição correspondente.
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

    int result = sequential(string, strlen(string) - 1, ch);

    if (result < 0)  printf("No result found!\n");
    else printf("Key [%c] is in position: %d\n", ch, result);

    free(string);

    return 0;
}
