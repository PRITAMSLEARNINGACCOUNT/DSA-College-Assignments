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
    if (Pointer->Top_Index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int POP(struct Stack *ptr)
{
    if (IsEmpty(ptr))
    {
        return -1;
    }
    else
    {
        ptr->Top_Index--;
        return ptr->Array[ptr->Top_Index + 1];
    }
}

int main()
{
    struct Stack *First_Stack = (struct Stack *)malloc(sizeof(struct Stack));
    First_Stack->Size = 6;
    First_Stack->Top_Index = -1;
    First_Stack->Array = (int *)malloc(First_Stack->Size * sizeof(int));
    First_Stack->Top_Index++;
    First_Stack->Array[First_Stack->Top_Index] = 50;
    int Return_Value = POP(First_Stack);
    if (Return_Value == -1)
    {
        printf("Stack Underflows\n");
    }
    else
    {
        printf("So Popped Out One Element From The Array Which Is %d\n", Return_Value);
    }
    free(First_Stack->Array);
    free(First_Stack);
    return 0;
}