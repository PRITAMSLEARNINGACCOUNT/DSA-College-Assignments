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
    if (ptr->Front_Index == ptr->Rear_Index)
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
    Q1->size = 2;
    Q1->Front_Index = 0;
    Q1->Rear_Index = 0;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    Q1->Rear_Index = ((Q1->Rear_Index + 1) % Q1->size);
    Q1->array[Q1->Rear_Index] = 20;
    IsEmpty(Q1);

    return 0;
}