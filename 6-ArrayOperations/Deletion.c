#include <stdio.h>
int DEL(int arr[], int position, int *size)
{
    if (position > *size || position < 0)
    {
        printf("Position Is Ivalid");
        return 0;
    }
    else
    {
        for (int i = position; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
            // printf("Element To Be Deleted %d\n", arr[i + 1]);
        }
        *size = *size - 1;
        return 1;
    }
}
void show(int arr[], int size)
{
    printf("Now The Elements In The Array Are \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int a[10], Size = 0, Position = 0;
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
        printf("Enter The Position You Want To Delete??\n");
        scanf("%d", &Position);
        DEL(a, Position - 1, &Size);
        // printf("%d\n", Size);
        show(a, Size);
    }

    return 0;
}