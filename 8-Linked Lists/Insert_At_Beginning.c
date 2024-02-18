/*
Note:An Address Of Any Type Of Data Can not be Changed Without Being Pointer
The Above Line Means We Just Can's Change Address Of An Already Declared Data.
&Data=Address_Of_Data---->This Can Not Be Done.
In Order To Do Something I Wanted In The Above Line Can Be Done By Doing Something Like Below:-
Data_Type *Data;
Data=Address_Of_Data;

*/

#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int Data;
    struct Linked_List *Node;
};
void Traversal(struct Linked_List *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    }
}
struct Linked_List *Insert(struct Linked_List *Copy, int data)
{

    struct Linked_List *Extra_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Extra_Node->Data = data;
    // struct Linked_List *Temp_Node = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    // struct Linked_List Temp_Head = *Copy;
    // Temp_Node = Copy;
    Extra_Node->Node = Copy;
    // Traversal(Extra_Node);
    // Copy = Extra_Node;
    // return Extra_Node;
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
    Fourth.Node = NULL;
    printf("Before Insertion\n");
    Traversal(&Head);
    printf("After Insertion\n");

    // printf("%d\n", Head.Data);
    Traversal(Insert(&Head, 507));
    // Head.Node=First;
    return 0;
}