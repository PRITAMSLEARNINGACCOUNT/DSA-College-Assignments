#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Size = 0, i;
    printf("Enter The Size Of The Array For Shell Sort?\n");
    scanf("%d", &Size);
    int *array = (int *)malloc(Size * sizeof(int));
    for (int i = 0; i < Size; i++)
    {
        printf("Enter Element No \n", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Now The Sorting Begins\n");
    int gap = Size;
    for (int f = 0; gap != 0; f++)
    {
        gap = gap / 2;
        if (gap == 0)
        {
            break;
        }

        i = 0;
        // }
        for (int j = gap + i; j < Size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                if ((i - gap) >= 0 && array[i - gap] > array[i])
                {
                    int temp = array[i - gap];
                    array[i - gap] = array[i];
                    array[i] = temp;
                }
            }

            i++;
        }
        i = 0;
    }
    printf("Now The Sorting Ends\n");
    for (int ele = 0; ele < Size; ele++)
    {
        printf("%d\n", array[ele]);
    }

    free(array);
    return 0;
}