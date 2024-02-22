#include <stdio.h>
#include <stdlib.h>
//{23,29,15,19,31,7,9,5,2};
int main()
{
    int i, j, gap, size;
    printf("Enter the size of the array:: ");
    scanf("%d", &size);
    int *array = malloc(size * sizeof(int));
    printf("\nEnter the elements of the array:: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    // printf("\nArray elements are:: ");
    // for(i=0;i<size;i++){
    //     printf("%d   ",array[i]);
    // }
    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (j = gap; j < size; j++)
        {
            i = j - gap;
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                if (i - gap >= 0 && array[i - gap] > array[i])
                {
                    temp = array[i - gap];
                    array[i - gap] = array[i];
                    array[i] = temp;
                }
            }

            i++;
        }
    }
    printf("\nArray elements are:: ");
    for (i = 0; i < size; i++)
    {
        printf("%d   ", array[i]);
    }
    return 0;
}