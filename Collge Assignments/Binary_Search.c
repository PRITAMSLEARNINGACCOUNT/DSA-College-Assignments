#include <stdio.h>
int Binary_Search(int arr[], int Array_Size, int Search, int low_point, int high_point)
{
    int Mid_Point;
    if (Search == arr[high_point])
    {
        return high_point;
    }
    else if (Search == arr[low_point])
    {
        return low_point;
    }
    else
    {

        // while (low_point <= high_point)
        // {
        Mid_Point = (high_point + low_point) / 2;
        if (arr[Mid_Point] == Search)
        {
            return Mid_Point;
        }
        else if (Search > arr[Mid_Point])
        {
            low_point = Mid_Point+1;
            return (arr, Array_Size, Search, low_point, high_point);
        }
        else
        {
            high_point = Mid_Point-1;
            return (arr, Array_Size, Search, low_point, high_point);
        }
        // }.
        
    }

    return -1;
}
int main()
{
    int a[10], Size = 0, Position = 0, Find = 0;
    printf("Enter The Size Of The Array??\n");
    scanf("%d", &Size);
    if (Size > 10)
    {
        printf("The Array Overflows.\n");
    }
    else
    {
        printf("Enter The Elements In The Array\n");
        for (int i = 0; i < Size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Enter The Element You Want To Find From The Array?\n");
        scanf("%d", &Find);
        if (Binary_Search(a, Size, Find, 0, Size - 1) == -1)
        {
            printf("The Element %d Is Not Founded In The Array\n", Find);
        }
        else
        {
            printf("The Element %d Is Founded In %dth Index Of The Array\n", Find, Binary_Search(a, Size, Find, 0, Size - 1));
        }
    }

    return 0;
}