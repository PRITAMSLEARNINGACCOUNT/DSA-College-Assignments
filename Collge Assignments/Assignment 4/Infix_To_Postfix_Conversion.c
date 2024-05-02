#include <stdio.h>
#include <string.h>

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

char associativity(char c)
{
	if (c == '^')
		return 'R';
	return 'L';
}

void infixToPostfix(char s[])
{
	char output[10];	 // show the output
	int outputIndex = 0; // indexing for output array
	int len = strlen(s); // measure the length of input string so we have added string.h
	char stack[10];		 // array for push and pop
	int top = -1;		 // indexing of stack array

	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) // for operand
		{
			output[outputIndex++] = c;
		}
		else if (c == '(') // for left parenthesis
		{
			stack[++top] = c;
		}
		else if (c == ')')
		{
			while (top >= 0 && stack[top] != '(')
			{
				output[outputIndex++] = stack[top--];
			}
			top--; // deleting the left parenthesis
		}
		else // for operator
		{
			while (top >= 0 && (prec(s[i]) < prec(stack[top]) || prec(s[i]) == prec(stack[top]) && associativity(s[i]) == 'L'))
			{
				output[outputIndex++] = stack[top--];
			}
			stack[++top] = c;
		}
	}
	while (top >= 0)
	{
		output[outputIndex++] = stack[top--];
	}
	printf("%s", output);
}
int main()
{
	char exp[] = "(a+b)^d-i"; // exp is an array of character elements for taking input of infix expression
	infixToPostfix(exp);	  // function to convert infix to postfix
	return 0;
}
