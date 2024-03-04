#include <stdio.h>
int *Func()
{
    int *ptr;
    *ptr = 10;
    return ptr;
}
int main()
{
    int *integer;
    *integer = 112;
    integer = Func();
    printf("%d", integer);
    return 0;
}