#include <stdio.h>
 

int main(void)
{
    int num_of_elements, i, j, c, root, temp;
 
    printf("\n Enter number of elements :");
    scanf("%d", &num_of_elements);

    int heap[num_of_elements];

    printf("\n Enter the elements: ");

    for (i = 0; i < num_of_elements; i++)
       scanf("%d", &heap[i]);

    for (i = 1; i < num_of_elements; i++) {
        c = i;
        do {
            root = (c - 1) / 2; // Honestly, WTH is that??
            if (heap[root] < heap[c]) {     /* to create MAX heap array */
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");

    for (i = 0; i < num_of_elements; i++)
        printf("%d\t ", heap[i]);

    for (j = num_of_elements - 1; j >= 0; j--) {
        temp = heap[0];
        heap[0] = heap[j];   /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do  {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j) {    /* again rearrange to max heap array */
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 

    printf("\n The sorted array is : ");

    for (i = 0; i < num_of_elements; i++)
       printf("\t %d", heap[i]);

    printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");

    return 0;
}
