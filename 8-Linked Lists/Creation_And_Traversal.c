#include <stdio.h>
// #include <stdlib.h>
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
    Traversal(&Head);
    // Head.Node=First;
    return 0;
}