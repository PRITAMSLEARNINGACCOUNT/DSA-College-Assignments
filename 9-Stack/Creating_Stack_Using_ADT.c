#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int Size;
    int Top_Index;
    int *Array;
};

int main()
{
    struct Stack *First_Stack = (struct Stack *)malloc(sizeof(struct Stack));
    First_Stack->Size = 6;
    First_Stack->Top_Index = -1;
    First_Stack->Array = (int *)malloc(First_Stack->Size * sizeof(int));
    printf("So I Have Successfully Implemented Stack Finally\n");
    free(First_Stack->Array);
    free(First_Stack);
    return 0;
}