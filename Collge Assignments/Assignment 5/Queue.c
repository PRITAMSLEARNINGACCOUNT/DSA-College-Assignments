#include <stdio.h>

void display(int queue[], int front, int rear)
{
    int i;
    if (front == -1)
    {
        printf("\n EMPTY QUEUE \n");
        return;
    }
    printf("\n THE QUEUE IS:- \n");
    for (i = front; i <= rear; i++)
        printf("[%d]", queue[i]);
    printf("\n-------------------\n");
}

int main()
{
    int queue[10], choice, data, removed_data;
    int size = 10;
    int front = -1, rear = -1;
    while (1)
    {
        printf("\n------------\n");
        printf("\n 1. INSERT \n");
        printf("\n 2. DELETE \n");
        printf("\n 3. DISPLAY\n");
        printf("\n 4. EXIT \n");
        printf("\n------------\n");
        printf("\n ENTER CHOICE: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rear < size - 1)
            {
                if (rear == -1)
                {
                    front = rear = 0;
                }
                else
                    rear++;
                printf("\n ENTER DATA TO INSERT: \n");
                scanf("%d", &data);
                queue[rear] = data;
                display(queue, front, rear);
            }
            else
                printf("\n QUEUE OVERFLOW \n");
            break;
        case 2:
            if (front == -1)
                printf("\n QUEUE IS EMPTY \n");
            if (front > -1)
            {
                removed_data = queue[front];
                if (front == rear)
                {
                    printf("\n DELETED ITEM IS: %d \n", removed_data);
                    front = rear = -1;
                }
                else
                {
                    printf("\n DELETED ITEM IS: %d \n", removed_data);
                    front++;
                }
                display(queue, front, rear);
            }
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            exit(0);
        default:
            printf("\n YOU HAVE ENTERED WRONG CHOICE. \n");
        }
    }
    return 0;
}
