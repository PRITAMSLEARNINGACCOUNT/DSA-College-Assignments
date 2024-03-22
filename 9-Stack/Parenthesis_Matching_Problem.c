#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack
{
    int Size;
    int Top_Index;
    char *Array;
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
int PUSH(struct Stack *Pointer, char Value)
{
    if (IsFull(Pointer))
    {
        return -1;
    }
    else
    {
        Pointer->Top_Index++;
        Pointer->Array[Pointer->Top_Index] = Value;
    }
}
void Parenthesis_Matching(char *Char_Ptr, struct Stack *Stack_Ptr)
{
    for (int i = 0; Char_Ptr[i] != '\0'; i++)
    {
        if (Char_Ptr[i] == '(')
        {
            PUSH(Stack_Ptr, Char_Ptr[i]);
        }
        else if (Char_Ptr[i] == ')')
        {
            if (IsEmpty(Stack_Ptr))
            {
                printf("Parenthesis Unmatched So The Expression Is Invalid\n");
            }

            POP(Stack_Ptr);
        }
    }
    if (IsEmpty(Stack_Ptr))
    {
        printf("Parenthesis Matched So The Expression Is Valid\n");
    }
    else
    {
        printf("Parenthesis Unmatched So The Expression Is Invalid\n");
    }
}
int main()
{
    char *Hello = "(jhvdsajvdsjhvak(jsdlksajbdak)";
    struct Stack *Parenthesis = (struct Stack *)malloc(sizeof(struct Stack));
    Parenthesis->Top_Index = -1;
    Parenthesis->Size = strlen(Hello) + 1;
    Parenthesis->Array = (char *)malloc(Parenthesis->Size * sizeof(char));
    Parenthesis_Matching(Hello, Parenthesis);
    return 0;
}