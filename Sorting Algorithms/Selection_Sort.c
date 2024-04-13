#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *Arr, int Length)
{
    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}
void Selection_Sort(int *Arr, int Length)
{
    int Minimum_Index = 0, j, Swap_Value;
    for (int i = 0; i < Length - 1; i++)
    {
        Minimum_Index = i;
        for (j = i + 1; j <= Length - 1; j++)
        {
            if (Arr[j] < Arr[Minimum_Index])
            {
                Minimum_Index = j;
            }
        }
        Swap_Value = Arr[i];
        Arr[i] = Arr[Minimum_Index];
        Arr[Minimum_Index] = Swap_Value;
    }
}

int main()
{
    int Length = 0;
    printf("Enter The Length Of The Array??\n");
    scanf("%d", &Length);
    int *Array = (int *)malloc(Length * sizeof(int));
    printf("Give Inputs Of The Array Elements\n");
    for (int i = 0; i < Length; i++)
    {
        printf("Enter Element No %d \n", i);
        scanf("%d", &Array[i]);
    }
    printf("\n");
    printf("Before Sorting\n");
    PrintArray(Array, Length);
    Selection_Sort(Array, Length);
    printf("After Sorting\n");
    PrintArray(Array, Length);
    return 0;
}