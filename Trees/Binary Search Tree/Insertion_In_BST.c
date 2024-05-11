#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int Tree_Data;
    struct Tree *Next_Node;
    struct Tree *Previous_Node;
};
struct Tree *CreateNode(int Data)
{
    struct Tree *NewNode = (struct Tree *)malloc(sizeof(struct Tree));
    NewNode->Next_Node = NULL;
    NewNode->Previous_Node = NULL;
    NewNode->Tree_Data = Data;
    return NewNode;
}
void Inorder(struct Tree *Root_Node)
{
    if (Root_Node != NULL)
    {
        Inorder(Root_Node->Previous_Node);
        printf("%d ", Root_Node->Tree_Data);
        Inorder(Root_Node->Next_Node);
    }
}

struct Tree *Insert_Iterative(struct Tree *Node, int Data)
{
    struct Tree *NewNode = CreateNode(Data);
    struct Tree *Previous_Root = NULL;
    while (Node != NULL)
    {
        Previous_Root = Node;
        if (Node->Tree_Data == Data)
        {
            printf("The Data %d Is Already Present In The Tree\n", Data);
            return Node;
        }
        else if (Node->Tree_Data < Data)
        {
            Node = Node->Next_Node;
        }
        else
        {
            Node = Node->Previous_Node;
        }
    }
    if (Previous_Root->Tree_Data > Data)
    {
        // printf("Hello\n");

        Previous_Root->Previous_Node = NewNode;
        return NewNode;
    }
    else
    {
        // printf("Hello\n");
        Previous_Root->Next_Node = NewNode;
        return NewNode;
    }

    return NULL;
}

struct Tree *Insert_Recursive(struct Tree *Node, int Data)
{
    struct Tree *Previous_Root = NULL;
    if (Node == NULL)
    {
        return NULL;
    }
    else if (Node->Tree_Data == Data)
    {
        return Node;
    }
    else if (Node->Tree_Data > Data)
    {
        struct Tree *ptr = Insert_Recursive(Node->Previous_Node, Data);
        if (ptr == NULL)
        {
            struct Tree *Newnode = CreateNode(Data);
            Node->Previous_Node = Newnode;
        }
    }
    else
    {
        struct Tree *ptr = Insert_Recursive(Node->Next_Node, Data);
        if (ptr == NULL)
        {
            struct Tree *Newnode = CreateNode(Data);
            Node->Next_Node = Newnode;
        }
    }
}
int main()
{
    struct Tree *Root = CreateNode(50);
    struct Tree *Left_Node_1 = CreateNode(5);
    struct Tree *Left_Node_2 = CreateNode(2);
    struct Tree *Right_Node_1 = CreateNode(55);
    struct Tree *Right_Node_2 = CreateNode(3);
    Root->Next_Node = Right_Node_1;
    Root->Previous_Node = Left_Node_1;
    Left_Node_1->Previous_Node = Left_Node_2;
    Left_Node_2->Next_Node = Right_Node_2;
    Inorder(Root);
    Insert_Iterative(Root, 20);
    Insert_Recursive(Root, 200);
    printf("\nAfter Insertion\n");
    Inorder(Root);
    return 0;
}