#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int Data;
    struct Queue *Node;
};
void Traversal(struct Queue *Copy)
{
    while (Copy != NULL)
    {
        printf("%d\n", Copy->Data);
        Copy = Copy->Node;
    }
}

int main()
{
    struct Queue *Front_Index = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *Rear_Index = (struct Queue *)malloc(sizeof(struct Queue));
    Front_Index = NULL;
    Rear_Index = NULL;
    // Initialized An Empty Queue.
    return 0;
}