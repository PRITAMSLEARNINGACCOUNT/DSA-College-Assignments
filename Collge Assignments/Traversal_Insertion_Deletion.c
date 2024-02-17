#include <stdio.h>
int Insert(int arr[], int position, int element, int size)
{
    if (position > size || position < 0)
    {
        printf("Position Is Ivalid");
        return 0;
    }
    else
    {
        for (int i = size - 1; i >= position - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[position - 1] = element;
        return 1;
    }
}

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
    int a[10], Size = 0, Position = 0, Element = 0, Delete = 0;
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
        printf("Enter The Position You Want To Insert??\n");
        scanf("%d", &Position);
        printf("Enter The The Element You Want To Insert??\n");
        scanf("%d", &Element);
        Size += Insert(a, Position, Element, Size);
        show(a, Size);
        printf("Now Enter Which Position You Want To Delete From This Array??\n");
        scanf("%d", &Delete);
        DEL(a, Delete - 1, &Size);
        show(a, Size);
    }

    return 0;
}