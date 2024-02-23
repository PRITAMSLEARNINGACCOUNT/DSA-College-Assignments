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
void Delete(struct Linked_List *Copy, int index)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    }
}
int main()
{
    int Position;
    struct Linked_List *Head = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *First = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Second = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Third = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Fourth = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    struct Linked_List *Fifth = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    Head->Data = 90;
    Head->Node = First;
    First->Data = 20;
    First->Node = Second;
    Second->Data = 900;
    Second->Node = Third;
    Third->Data = 104;
    Third->Node = Fourth;
    Fourth->Data = 510;
    Fourth->Node = Fifth;
    Fifth->Data = 5401;
    Fifth->Node = NULL;
    printf("Before Deletion\n");
    Traversal(Head);
    printf("Enter The Position You Want To Delete??\n");
    scanf("%d", &Position);
    if ((Position - 1) == 0)
    {
        Head = Head->Node;
    }
    else
    {
        Delete(Head, Position - 1);
    }
    printf("After Deletion\n");
    Traversal(Head);
    return 0;
}