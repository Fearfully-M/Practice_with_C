//A program that dynamically allocates a 2D array where size is specified by the user.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%i", &rows);
    printf("Enter the number of columns: ");
    scanf("%i",&cols);

    int **arr = (int **) malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *) malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory Allocation Failed\n");
            return 1;
        }
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i * j;
        }
    }

    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j <cols; j++)
        {
            printf("%i", arr[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }

    free(arr);
}
