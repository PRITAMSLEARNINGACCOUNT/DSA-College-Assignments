#include <stdio.h>
// Declared A Function With A Pointer Return Type.
int *Func()
{
    // Declaring A Pointer.
    int *ptr;
    // Assigning Value By De-Referencing The Address Of The Pointer.
    *ptr = 10;
    // Returning The Address Of The Pointer After Successful Completion Of Value Assignment.
    return ptr;
}
int main()
{
    // Declaring A Normal Integer Varriable.
    int integer = 112;
    // Trying To Replace The Address Of Integer Varriable With The Address Of A New Address Of A New Varriable Returned From The Function.
    &integer = Func();
    // Finally Printing The Value Of The Integer Declared At The Starting Of The Program(Main Function).
    printf("%d", integer);
    return 0;
}