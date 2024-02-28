#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack
{
    int Size;
    int Top_Index;
    int *Array;
};
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
int PEEK(struct Stack *Pointer, int Value)
{
    return Pointer->Array[(Pointer->Top_Index - Value) + 1];
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
    printf("So The Elements From The Top Of The Stack Is\n");
    for (int i = 1; i <= First_Stack->Top_Index + 1; i++)
    {
        printf("%d\n", PEEK(First_Stack, i));
    }

    free(First_Stack->Array);
    free(First_Stack);
    return 0;
}