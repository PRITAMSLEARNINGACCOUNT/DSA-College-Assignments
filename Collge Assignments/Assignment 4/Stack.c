#include <stdio.h>

void display(int stack[], int top)
{
    int i;
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW \n");
        return;
    }
    printf("\n THE STACK IS:- \n");
    for(i = top; i>= 0; i--)
    {
        printf("|%d|\n", stack[i]);
        printf("---\n");
    }
    printf("\n------------------------------\n");
}

int main()
{
    int stack[10], size=10, choice, data;
    int top=-1;
    while(1)
    {
        printf("\n----------------\n");
        printf("\n 1. PUSH\n");
        printf("\n 2. POP\n");
        printf("\n 3. DISPLAY\n");
        printf("\n 4. PEEK\n");
        printf("\n 5. EXIT\n");
        printf("\n----------------\n");
        printf("ENTER CHOICE :\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                if(top >= size - 1)
                {
                    printf("\n STACK OVERFLOW \n");
                }
                else
                {   printf("\n ENTER DATA TO PUSH:\n");
                    scanf("%d", &data);
                    top = top+1;
                    stack[top]=data;
                    display(stack, top);
                }
                break;
            case 2: 
                if (top == -1)
                    printf("\n STACK UNDERFLOW \n");
                else
                {
                    printf("\n DELETED ITEM IS: %d \n", stack[top]);
                    top = top-1;
                    display(stack, top);
                }
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                if(top == -1)
                    printf("\n STACK UNDERFLOW \n");
                else
                    printf("\n THE TOPMOST ELEMENT IS: %d \n", stack[top]);
                break;
            case 5:
                exit(0);
            default:
                printf("\n YOU HAVE ENTERED WRONG CHOICE.\n");
        }
    }
    return 0;
}
