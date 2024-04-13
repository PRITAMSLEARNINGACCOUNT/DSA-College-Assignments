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
void Insertion_Sort(int *Arr, int Length)
{
    int Temp_Value = 0, j;
    for (int i = 1; i < Length - 1; i++)
    {
        Temp_Value = Arr[i];
        for (j = i - 1; j >= 0 && Arr[j] > Temp_Value; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = Temp_Value;
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
    Insertion_Sort(Array, Length);
    printf("After Sorting\n");
    PrintArray(Array, Length);
    return 0;
}