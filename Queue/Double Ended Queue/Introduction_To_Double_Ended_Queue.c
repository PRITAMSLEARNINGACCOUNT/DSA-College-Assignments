#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int *array;
    int Front_Index;
    int Rear_Index;
};

int main()
{
    struct Queue Q1;
    Q1.size = 10;
    Q1.Front_Index = -1;
    Q1.Rear_Index = -1;
    Q1.array = (int *)malloc(Q1.size * (sizeof(int)));
    return 0;
}