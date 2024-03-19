#include <stdio.h>

void insertion_sort(int a[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
        insertion_sort(a, size);
        printf("\nThe elements of the array\n");
        for (i = 0; i < size; i++)
        {
            printf("[%d]", a[i]);
        }
    }
    return 0;
}
