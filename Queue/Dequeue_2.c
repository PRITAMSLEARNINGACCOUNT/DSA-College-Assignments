#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue
{
    int size;
    int *array;
    int Rear_Index;
};
bool IsEmpty(struct Queue *ptr)
{
    if (ptr->Rear_Index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Dequeue(struct Queue *Pointer)
{

    if (IsEmpty(Pointer))
    {
        printf("The Queue Is Already Empty\n");
    }
    else
    {
        int a = Pointer->array[0];
        if (Pointer->Rear_Index == 0)
        {
            Pointer->Rear_Index--;
            return a;
        }
        else
        {

            for (int i = 0; i < Pointer->Rear_Index; i++)
            {
                Pointer->array[i] = Pointer->array[i + 1];
            }
            Pointer->Rear_Index--;
        }
        return a;
    }
}
int main()
{
    struct Queue *Q1 = (struct Queue *)malloc(sizeof(struct Queue));
    Q1->size = 20;
    Q1->Rear_Index = -1;
    Q1->array = (int *)malloc(Q1->size * (sizeof(int)));
    Q1->Rear_Index += 1;
    Q1->array[Q1->Rear_Index] = 10;
    Q1->Rear_Index += 1;
    Q1->array[Q1->Rear_Index] = 100;
    Q1->Rear_Index += 1;
    Q1->array[Q1->Rear_Index] = 1000;
    printf("%d\n", Dequeue(Q1));
    printf("%d\n", Dequeue(Q1));
    printf("%d\n", Dequeue(Q1));
    printf("%d\n", IsEmpty(Q1));
    return 0;
}