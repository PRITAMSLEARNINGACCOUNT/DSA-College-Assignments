#include <stdio.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
void IsFull()
{
    struct Linked_List *Temporary_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    if (Temporary_Node == NULL)
    {
        printf("Stack Is Full");
    }
    else
    {
        printf("Stack Isn't Full");
    }
}
int main()
{

    return 0;
}