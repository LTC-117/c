#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void quicksort(char *item, int left, int right)
{
    int l, r;
    char pivot, exchange;

    l = left; r = right;
    pivot = item[(left + right) / 2];

    do {
        while (item[l] < pivot && l < right) l++;
        while (pivot < item[r] && r > left) r--;

        if (l <= r) {
            exchange = item[l];
            item[l] = item[r];
            item[r] = exchange;
            l++; r--;
        }
    } while (l <= r);

    if (left < r) quicksort(item, left, r);
    if (l < right) quicksort(item, l, right);
}


// Initializes the quicksort
void quick(char *item, int count)
{
    quicksort(item, 0, count - 1);
}


int main(void)
{
    char *string = malloc(256 * sizeof(char));

    printf("Insert string: ");
    fgets(string, 256, stdin);

    string[strlen(string) - 1] = '\0';

    quick(string, strlen(string));

    printf("Qsorted string: %s\n", string);

    free(string);

    return 0;
}
