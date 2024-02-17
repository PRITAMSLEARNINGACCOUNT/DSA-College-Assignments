#include <stdio.h>
int Binary_Search(int arr[], int Array_Size, int Search)
{
    int Mid_Point, High_Point = Array_Size - 1, Low_Point = 0;
    if (Search == arr[High_Point])
    {
        return High_Point;
    }
    else if (Search == arr[Low_Point])
    {
        return Low_Point;
    }
    else
    {

        while (Low_Point <= High_Point)
        {
            Mid_Point = (High_Point + Low_Point) / 2;
            if (arr[Mid_Point] == Search)
            {
                return Mid_Point;
            }
            else if (Search > arr[Mid_Point])
            {
                Low_Point = Mid_Point;
            }
            else
            {
                High_Point = Mid_Point;
            }
        }
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
        if (Binary_Search(a, Size, Find) == -1)
        {
            printf("The Element %d Is Not Founded In The Array\n", Find);
        }
        else
        {
            printf("The Element %d Is Founded In %dth Index Of The Array\n", Find, Binary_Search(a, Size, Find));
        }
    }

    return 0;
}