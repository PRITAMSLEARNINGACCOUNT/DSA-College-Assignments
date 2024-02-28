#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack
{
    int Size;
    int Top_Index;
    int *Array;
};
bool IsEmpty(struct Stack *Pointer)
{
    if (Pointer->Top_Index > -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsFull(struct Stack *Pointer)
{
    if (Pointer->Top_Index == Pointer->Size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PUSH(struct Stack *Pointer, int Value)
{
    if (IsFull(Pointer))
    {
        printf("Stack Overflows\n");
    }
    else
    {
        Pointer->Top_Index++;
        Pointer->Array[Pointer->Top_Index] = Value;
    }
}
int Stack_Top(struct Stack *ptr)
{
    return ptr->Array[ptr->Top_Index];
}
int Stack_Bottom(struct Stack *ptr)
{
    return ptr->Array[0];
}

int main()
{
    struct Stack *First_Stack = (struct Stack *)malloc(sizeof(struct Stack));
    First_Stack->Size = 6;
    First_Stack->Top_Index = -1;
    First_Stack->Array = (int *)malloc(First_Stack->Size * sizeof(int));
    PUSH(First_Stack, 50);
    PUSH(First_Stack, 500);
    PUSH(First_Stack, 504);
    PUSH(First_Stack, 74);
    PUSH(First_Stack, 844);
    if (IsEmpty(First_Stack))
    {
        printf("So The Top Most Element From The Stack Is %d\n", Stack_Top(First_Stack));
        printf("And The Bottom Element From The Stack Is %d\n", Stack_Bottom(First_Stack));
    }

    free(First_Stack->Array);
    free(First_Stack);
    return 0;
}