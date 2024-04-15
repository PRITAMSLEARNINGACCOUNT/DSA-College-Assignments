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
void Count_Sort(int *Arr, int Length)
{
    int Maximum_Value = Arr[0], j, i;
    for (i = 1; i <= Length - 1; i++)
    {
        if (Maximum_Value < Arr[i])
        {
            Maximum_Value = Arr[i];
        }
    }

    int *Max_Array = (int *)malloc(Maximum_Value * sizeof(Arr));
    for (i = 0; i <= Maximum_Value; i++)
    {
        Max_Array[i] = 0;
    }
    for (i = 0; i < Length; i++)
    {
        Max_Array[Arr[i]]++;
    }
    i = j = 0;
    while (i <= Maximum_Value)
    {
        if (Max_Array[i] != 0)
        {
            Arr[j] = i;
            Max_Array[i]--;
            j++;
        }
        else
        {
            i++;
        }
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
    Count_Sort(Array, Length);
    printf("After Sorting\n");
    PrintArray(Array, Length);
    return 0;
}