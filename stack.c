//LinkedList로 stack 구현
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#define STACK_SIZE 5

struct Node
{
	int nData;
	struct Node *pNext;
}; typedef struct Node Node;

Node *Top = NULL;
int count = 0;

void push(int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node*));

	pNewNode->nData = data;
	pNewNode->pNext = NULL;

	if (count > STACK_SIZE)
	{
		printf("stack overflow\n");
		return 1;
	}

	if (NULL == Top)
	{
		Top = pNewNode;
		count++;
	}
	else
	{
		pNewNode->pNext = Top;
		Top = pNewNode;
		count++;
	}
}

int pop()
{
	Node *pNode = Top;

	if (count > 0)
	{
		printf("pop : %d\n", pNode->nData);
		count--;
	}
	else if (count = 0)
	{
		printf("NULL\n");
		return 1;
	}
	else if (count < 0)
	{
		printf("stack underflow");
		return 1;
	}
	Top = pNode->pNext;

}

int main(void)
{
	push(10);
	push(4);
	pop(); //4
	push(7); // 10->7
	push(2); // 10->7->2
	push(3); // 10->7->2->3
	push(11);// 10->7->2->3->11
	pop(); //11
	pop(); //3
	pop(); //2
	pop(); //7
	pop(); //10
	pop();
	system("pause");
	return 0;
}

/*
// 배열로 구현한 STACK
#define STACK_SIZE 5

int stack[STACK_SIZE] = { 0, };
int top = -1;

void push(int data); //overflow
int pop(); //underflow

void push(int data)
{
	if (top >= STACK_SIZE - 1)
	{
		printf("Overflow");
	}
	else
		stack[++top] = data;
}

int pop()
{
	if (top < 0)
	{
		printf("underflow\n");
	}
	else
		return stack[top--];
}

int main(void)
{
	memset(stack, 0, sizeof(stack));
	push(10);
	push(4);
	printf("pop %d\n", pop());
	push(7);
	push(2);
	push(3);
	push(11);
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	

	return 0;
}
*/