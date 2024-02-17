#include <stdio.h>

int main()
{
    int a[10], size, i, pos, del_pos, val;
    printf("Enter the number of elements of array-");
    scanf("%d", &size);

    if (size > 10)
    {
        printf("Array overflows");
    }
    else
    {
        printf("The number of elements of array-%d", size);
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

        printf("\nEnter the value you want to insert:");
        scanf("%d", &val);
        printf("Enter the position where you want to insert:");
        scanf("%d", &pos);

        if (pos < 0 || pos > size + 1)
        {
            printf("Invalid position");
        }
        else
        {
            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }
            a[pos - 1] = val;
            size++;
            printf("\nThe elements of the array\n");
            for (i = 0; i < size; i++)
            {
                printf("[%d]", a[i]);
            }
        }

        printf("\nEnter the position where you want to delete:");
        scanf("%d", &del_pos);
        if (del_pos < 0 || del_pos > size)
        {
            printf("Wrong position");
        }
        else
        {
            for (i = del_pos - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            size--;
            printf("\nThe elements of the array\n");
            for (i = 0; i < size; i++)
            {
                printf("[%d]", a[i]);
            }
        }
    }
    return 0;
}