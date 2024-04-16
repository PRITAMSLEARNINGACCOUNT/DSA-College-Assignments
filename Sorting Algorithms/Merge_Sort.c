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
void Merge(int *Array, int Low, int Mid, int High)
{
    int *Extra_Array = (int *)malloc(((High - Low) + 1) * sizeof(int));
    int k = Low;
    int L = Low;
    int i = Mid + 1;
    int j = High;
    while (L <= Mid && i <= High)
    {
        if (Array[L] < Array[i])
        {
            Extra_Array[k] = Array[L];
            k++;
            L++;
        }
        else
        {
            Extra_Array[k] = Array[i];
            k++;
            i++;
        }
    }
    while (i <= High)
    {
        Extra_Array[k] = Array[i];
        k++;
        i++;
    }
    while (L <= Mid)
    {
        Extra_Array[k] = Array[L];
        k++;
        L++;
    }
    for (i = Low; i <= High; i++)
    {
        Array[i] = Extra_Array[i];
    }
}
void Merge_Sort(int *Arr, int Low, int High)
{
    if (Low < High)
    {
        int Mid = (Low + High) / 2;
        Merge_Sort(Arr, Low, Mid);
        Merge_Sort(Arr, Mid + 1, High);
        Merge(Arr, Low, Mid, High);
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
    Merge_Sort(Array, 0, Length - 1);
    printf("After Sorting\n");
    PrintArray(Array, Length);
    return 0;
}