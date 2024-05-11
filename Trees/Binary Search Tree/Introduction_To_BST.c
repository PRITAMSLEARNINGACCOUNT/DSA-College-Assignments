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
    return 0;
}