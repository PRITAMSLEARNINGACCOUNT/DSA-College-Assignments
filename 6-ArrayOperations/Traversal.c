#include <stdio.h>
void show(int arr[], int size)
{
    printf("I Am Doing Traversal Through The Array\n");
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
        show(a, Size);
    }

    return 0;
}