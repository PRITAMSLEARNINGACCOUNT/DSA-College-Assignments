#include <stdio.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
void IsNull(struct Linked_List *Top)
{
    if (Top == NULL)
    {
        printf("Stack Is Empty");
    }
    else
    {
        printf("Stack Isn't Empty");
    }
}
int main()
{
    struct Linked_List *Top;
    Top = NULL;
    IsNull(Top);

    return 0;
}