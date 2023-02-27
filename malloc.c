//Dynamically allocates memory using malloc by asking user how large array size should be.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i", arr[i]);
    }

    printf("\n");

    free(arr);
}