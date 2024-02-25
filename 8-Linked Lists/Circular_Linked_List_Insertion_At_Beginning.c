#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
void Traversal(struct Linked_List *Copy)
{
    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node = Copy;
    do
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    } while (Extra_Node != Copy);
}
struct Linked_List *Insert(struct Linked_List *Copy, struct Linked_List *Last, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    Extra_Node->Node = Copy;
    Last->Node = Extra_Node;
    return Extra_Node;
}

int main()
{
    struct Linked_List Head;
    struct Linked_List First;
    struct Linked_List Second;
    struct Linked_List Third;
    struct Linked_List Fourth;
    Head.Node = &First;
    Head.Data = 50;
    First.Node = &Second;
    First.Data = 510;
    Second.Node = &Third;
    Second.Data = 10;
    Third.Node = &Fourth;
    Third.Data = 20;
    Fourth.Data = 600;
    Fourth.Node = &Head;
    printf("Before Insertion\n");
    Traversal(&Head);
    printf("After Insertion\n");

    Traversal(Insert(&Head, &Fourth, 507));
    return 0;
}