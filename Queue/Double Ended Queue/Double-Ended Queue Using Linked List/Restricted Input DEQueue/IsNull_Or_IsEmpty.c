#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int Data;
    struct Queue *Node;
};
void IsNull(struct Queue *Front, struct Queue *Rear)
{

    if (Front == NULL && Rear == NULL)
    {
        printf("The Queue Is Empty\n");
    }
}

int main()
{
    struct Queue *Front_Index = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *Rear_Index = (struct Queue *)malloc(sizeof(struct Queue));
    Front_Index = NULL;
    Rear_Index = NULL;
    IsNull(Front_Index, Rear_Index);
    return 0;
}