#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int Data;
    struct Queue *Previous_Node;
    struct Queue *Next_Node;
};
void IsFull()
{
    struct Queue *Node = (struct Queue *)malloc(sizeof(struct Queue));
    if (Node == NULL)
    {
        printf("The Queue Is Full\n");
    }
}

int main()
{
    struct Queue *Front_Index = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *Rear_Index = (struct Queue *)malloc(sizeof(struct Queue));
    Front_Index = NULL;
    Rear_Index = NULL;
    return 0;
}