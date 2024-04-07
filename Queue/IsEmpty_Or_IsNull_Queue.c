#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int *array;
    int Front_Index;
    int Rear_Index;
};
void IsEmpty(struct Queue *ptr)
{
    if (ptr->Front_Index == ptr->Front_Index || ptr->Rear_Index == -1)
    {
        printf("The Queue Is Empty\n");
    }
    else
    {
        printf("The Queue Is Not Empty\n");
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 1;
    Q1->Front_Index = -1;
    Q1->Rear_Index = -1;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    IsEmpty(Q1);

    return 0;
}