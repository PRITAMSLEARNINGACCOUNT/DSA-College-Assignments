#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
char POP(struct Stack *ptr)
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
bool Is_Operator(char Charecter)
{
    // printf("%c\n", Charecter);
    if (Charecter == '+' || Charecter == '-' || Charecter == '*' || Charecter == '/')
    {
        // printf("Returning False\n");
        return true;
    }
    return false;
}
int Operator_Precedence(char Char)
{
    if (Char == '+' || Char == '-')
    {
        return 1;
    }
    else if (Char == '*' || Char == '/')
    {
        return 2;
    }
}
char Stack_Top(struct Stack *ptr)
{
    return ptr->Array[ptr->Top_Index];
}
void Convert(char *Charecter_Pointer, struct Stack *ptr, int String_Length)
{
    // printf("%c\n", Charecter_Pointer[0]);
    int j = 0;
    int i = 0;
    char *PostFix = (char *)malloc(String_Length + 1 * sizeof(char));
    while (Charecter_Pointer[i] != '\0')
    {
        if (!Is_Operator(Charecter_Pointer[i]))
        {
            PostFix[j] = Charecter_Pointer[i];
            j++;
            i++;
            // printf("Running\n");
            // printf("%c\n", PostFix[j]);
            // printf("%c\n", Charecter_Pointer[i]);
        }
        else
        {
            // printf("Not Running\n");
            if (IsEmpty(ptr))
            {
                PUSH(ptr, Charecter_Pointer[i]);
                i++;
            }
            else if (Operator_Precedence(Charecter_Pointer[i]) > Operator_Precedence(Stack_Top(ptr)))
            {
                PUSH(ptr, Charecter_Pointer[i]);
                i++;
            }
            else
            {
                while (!IsEmpty(ptr))
                {
                    PostFix[j] = POP(ptr);
                    j++;
                }
            }
        }
    }
    while (!IsEmpty(ptr))
    {

        PostFix[j] = POP(ptr);
        j++;
    }
    PostFix[j] = '\0';
    printf("%s\n", PostFix);
}
int main()
{
    char *Hello = "p-q-r/a";
    struct Stack *Parenthesis = (struct Stack *)malloc(sizeof(struct Stack));
    Parenthesis->Top_Index = -1;
    Parenthesis->Size = strlen(Hello) + 1;
    Parenthesis->Array = (char *)malloc(Parenthesis->Size * sizeof(char));
    Convert(Hello, Parenthesis, strlen(Hello));
    return 0;
}