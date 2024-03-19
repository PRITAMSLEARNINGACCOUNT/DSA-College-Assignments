#include <stdio.h>

void print(int arr[], int s)
{
    printf("\nThe Array is :::-----------------------");
    for (int i = 0; i < s; i++)
    {
        printf(" [%d] ,", arr[i]);
    }
}

void insertion(int arr[], int *s, int indx)
{
    int element;
    if (indx < 1 || indx > *s)
    {
        printf("Invalid POSITION! Please enter a valid POSITION between 1 and %d.", *s);
    }
    else
    {
        printf("\nEnter the Element that you want to Insert: ");
        scanf("%d", &element);
        *s += 1;
        for (int i = *s - 1; i > indx - 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[indx - 1] = element;
    }
}

void deletion(int arr[], int s, int indx)
{
    if (indx < 1 || indx > s)
    {
        printf("Invalid Index! Please enter a valid Index between 1 and %d.\n", s);
    }
    else
    {
        for (int i = indx - 1; i < s - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        s--;
    }
}

void searching(int arr[], int s, int key)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (arr[i] == key)
        {
            printf("\n The POSITION of the element is :: %d", i + 1);
            printf("\n The INDEX of the element is :: %d", i);
            break;
        }
    }
    if (i == s)
    {
        printf("\n \n SORRY!! the element is not present in this Array");
    }
}

int main()
{

    int array[10], size;
    printf("Enter the size of the array:: ");
    scanf(" %d", &size);

    if (size > 10)
    {
        printf("SORRY!! But the maximum limit is 10 only.\n");
    }
    else
    {
        printf("Enter the elements of the array:\n");

        for (int i = 0; i < size; i++)
        {
            printf("Element %d: ", i + 1);
            scanf("%d", &array[i]);
        }
        // Printing the original array
        print(array, size);

        int option;
        printf("\n=====================================");
        printf("\n\t\tMenu\n");
        printf("======================================");
        printf("\nA: Insert an Element at a specified position [Enter 1].");
        printf("\nB: Delete an Element from a specified position [Enter 2].");
        printf("\nC: Search an Element in the Array the Array[Enter 3].");
        printf("\nD: Display the Array [Enter 4].");
        printf("\nE: Exit [Enter 5].");

        do
        {
            printf("\n\n------------------------------------------");
            printf("\n   Enter What You Want to Do: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                int index;
                printf("\nEnter the POSITION where you want to Insert the Element:: ");
                scanf("%d", &index);

                insertion(array, &size, index);
                break;

            case 2:
                int delIndex;
                printf("\nEnter the POSITION of which Element you want to Delete: ");
                scanf("%d", &delIndex);

                deletion(array, size, delIndex);
                break;

            case 3:
                int value;
                printf("\nEnter the Element that you want to Search: ");
                scanf("%d", &value);

                searching(array, size, value);
                break;

            case 4:
                print(array, size);
                break;

            case 5:
                printf("Thank you for using.......");
                break;
            }
            if (option > 5 || option < 1)
            {
                printf("SORRY!! You choose a Invalid option.....");
                printf("Please Choose a Correct Option.....");
            }
        } while (option != 5);
    }
}
