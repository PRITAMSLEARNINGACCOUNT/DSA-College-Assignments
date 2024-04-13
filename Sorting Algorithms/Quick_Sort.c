#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *Array, int Length)
{
    for (int i = 0; i < Length; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}
int Partition(int *Array, int Low, int High)
{
    int Low_Copy = Low;
    int Pivot = Array[Low], Temporary_Value_1, Temporary_Value_2;

    do
    {
        while (Pivot >= Array[Low])
        {
            Low++;
        }
        while (Pivot < Array[High])
        {
            High--;
        }
        if (Low < High)
        {
            Temporary_Value_1 = Array[Low];
            Array[Low] = Array[High];
            Array[High] = Temporary_Value_1;
        }

    } while (Low < High);
    Temporary_Value_2 = Array[Low_Copy];
    Array[Low_Copy] = Array[High];
    Array[High] = Temporary_Value_2;
    return High;
}
void Quick_Sort(int *Array, int Low, int High)
{
    if (Low < High)
    {
        int Partition_Index = Partition(Array, Low, High);
        Quick_Sort(Array, Low, Partition_Index - 1);
        Quick_Sort(Array, Partition_Index + 1, High);
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
    Quick_Sort(Array, 0, Length - 1);
    printf("After Sorting\n");
    PrintArray(Array, Length);
    return 0;
}