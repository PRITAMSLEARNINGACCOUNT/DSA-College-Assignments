#include <stdio.h>
#include <malloc.h>

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

struct Tree *Predecessor(struct Tree *Root_Node)
{
    Root_Node = Root_Node->Previous_Node;
    while (Root_Node->Next_Node != NULL)
    {
        Root_Node = Root_Node->Next_Node;
    }
    return Root_Node;
}

struct Tree *Deletion(struct Tree *Root_Node, int Data)
{

    struct Tree *Predecessor_Node;
    if (Root_Node == NULL)
    {
        return NULL;
    }
    if (Root_Node->Previous_Node == NULL && Root_Node->Next_Node == NULL)
    {
        free(Root_Node);
        return NULL;
    }

    // searching for the node to be deleted
    if (Data < Root_Node->Tree_Data)
    {
        Root_Node->Previous_Node = Deletion(Root_Node->Previous_Node, Data);
    }
    else if (Data > Root_Node->Tree_Data)
    {
        Root_Node->Next_Node = Deletion(Root_Node->Next_Node, Data);
    }
    // deletion strategy when the node is found
    else
    {
        if (Root_Node->Previous_Node == NULL)
        {
            struct Tree *temp = Root_Node->Next_Node;
            free(Root_Node);
            return temp;
        }
        else if (Root_Node->Next_Node == NULL)
        {
            struct Tree *temp = Root_Node->Previous_Node;
            free(Root_Node);
            return temp;
        }
        Predecessor_Node = Predecessor(Root_Node);
        Root_Node->Tree_Data = Predecessor_Node->Tree_Data;
        Root_Node->Previous_Node = Deletion(Root_Node->Previous_Node, Predecessor_Node->Tree_Data);
    }
    return Root_Node;
}

struct Tree *Deletion_Iterative(struct Tree *Node, int Data)
{
    struct Tree *Predecessor_Node;
    while (Node != NULL)
    {
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

    return NULL;
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
    printf("\n");
    Deletion(Root, 6);
    Inorder(Root);

    return 0;
}
