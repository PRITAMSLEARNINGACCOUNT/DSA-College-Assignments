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
int main()
{
    struct Tree *Root = CreateNode(50);
    struct Tree *Node_1 = CreateNode(5);
    struct Tree *Node_2 = CreateNode(0);
    Root->Next_Node = Node_1;
    Root->Previous_Node = Node_2;

    return 0;
}