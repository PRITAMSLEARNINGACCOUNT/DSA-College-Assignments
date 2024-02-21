#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Size = 0;
    int array[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};
    // printf("Enter The Size Of The Array For Shell Sort?\n");
    // scanf("%d", &Size);
    // int *array = (int *)malloc(Size * sizeof(int));
    // int array[] = {50, 50, 780, 66, 98, 2, 3, 4, 5, 7};
    // for (int i = 0; i < Size; i++)
    // {
    //     printf("Enter Element No \n", i + 1);
    //     scanf("%d", &array[i]);
    // }
    // Size -= 1;
    Size = sizeof(array) / sizeof(int);
    printf("%d\n", Size);
    printf("Now The Sorting Begins\n");
    int gap = Size;
    int orggap = 0;
    for (int f = 0; gap != 0; f++)
    {
        // if (orggap == 2)
        // {
        //     // printf("Hello Loop 1\n");
        //     gap = 1;
        // }
        // else
        // {
        gap = gap / 2;
        if (gap == 0)
        {
            break;
        }
        // printf("%d\n", gap);

        // orggap = gap;
        // }
        int i = 0;
        for (int j = gap + i; j < Size; j++)
        {
            // printf("%d\n", gap);
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                // printf("Outer IF\n");
                if ((j - gap) >= 0 && array[j - gap] > array[i])
                {
                    printf("Hello World\n");
                    int temp = array[j - gap];
                    array[j - gap] = array[i];
                    array[i] = temp;
                }
            }

            i++;
        }
        i = 0;
    }
    for (int ele = 0; ele < Size; ele++)
    {
        printf("%d\n", array[ele]);
    }

    // printf("Now The Sorting Ends\n");
    // free(array);
    return 0;
}