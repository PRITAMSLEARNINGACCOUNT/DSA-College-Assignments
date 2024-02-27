#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int Size;
    int Top_Index;
    int *Array;
};
void IsFull(struct Stack *Pointer)
{
    if (Pointer->Top_Index == Pointer->Size - 1)
    {
        printf("Your Stack Is Full");
    }
    else
    {
        printf("Your Stack Isn't Full");
    }
}
int main()
{
    struct Stack *First_Stack = (struct Stack *)malloc(sizeof(struct Stack));
    First_Stack->Size = 6;
    First_Stack->Top_Index = -1;
    First_Stack->Array = (int *)malloc(First_Stack->Size * sizeof(int));
    

    printf("So I Have Successfully Implemented Stack Finally\n");
    IsFull(First_Stack);
    free(First_Stack->Array);
    free(First_Stack);
    return 0;
}