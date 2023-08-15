#include <stdio.h>
#include <stdlib.h>

//배열을 이용한 스택

#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;

int isFull()
{
	if (top > STACK_SIZE - 1)
	{
		printf("ERROR: Stack is full\n");
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if (top == -1)
	{
		printf("ERROR: Stack is empty\n");
		return 1;
	}
	return 0;
}

void Push(int value)
{
	if (!isFull())
	{
		top++;
		stack[top] = value;
	}
}

int Pop()
{
	if (!isEmpty())
	{
		return stack[top--];
	}
}

void PrintStack()
{
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	PrintStack();
	Pop();
	PrintStack();

	return 0;
}