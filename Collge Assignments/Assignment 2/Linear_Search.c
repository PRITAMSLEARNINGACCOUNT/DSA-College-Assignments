#include <stdio.h>
int Linear_Search(int arr[], int Array_Size, int Search)
{
    for (int i = 0; i < Array_Size; i++)
    {
        if (arr[i] == Search)
        {
            return i;
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
        if (Linear_Search(a, Size, Find) == -1)
        {
            printf("The Element %d Is Not Founded In The Array\n", Find);
        }
        else
        {
            printf("The Element %d Is Founded In %dth Index Of The Array\n", Find, Linear_Search(a, Size, Find));
        }
    }

    return 0;
}