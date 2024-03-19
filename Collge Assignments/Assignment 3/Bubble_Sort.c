#include <stdio.h>
void bubble_sorting(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[10], size, i;
    printf("Enter the size of array-");
    scanf("%d", &size);

    if (size > 10)
    {
        printf("Array overflows");
    }
    else
    {
        printf("The the size of array-%d", size);
        printf("\nEnter the elements of the array-");
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }

        printf("\nThe elements of the array\n");
        for (i = 0; i < size; i++)
        {
            printf("[%d]", a[i]);
        }
        bubble_sorting(a, size);
        printf("\nThe elements of the array\n");
        for (i = 0; i < size; i++)
        {
            printf("[%d]", a[i]);
        }
    }
    return 0;
}
