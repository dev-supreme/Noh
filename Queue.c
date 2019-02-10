//Queue 문제점 : 5이후에 출력이안됌 //연결문제
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define QUEUE_SIZE 5

struct Node
{
	int ndata;
	struct Node* pNext;
	struct Node *pPrev;
}; typedef struct Node Node;

Node* head = NULL;
Node* tail = NULL;

void Enqueue(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	pNewNode->ndata = data;
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;


	if (NULL == head)
	{
		head = pNewNode;
	}
	else
	{
		Node* pNode = head;
		pNode->pPrev = NULL;
		pNode->pNext = pNewNode;
		tail = pNewNode;
		pNewNode->pPrev = pNode;
		pNode->pNext = pNode;
	}
}

int Dequeue()
{
	Node* pNode = head;
	Node* tmpNode = tail;
	int returnvalue = 0;
	
	pNode->pNext = pNode;
	tmpNode->pNext = NULL;
	if(NULL == head)
	{
		printf("queue is empty");
		return 0;
	}
	else
	{
		tmpNode->pPrev = pNode;
		tmpNode = tail;
		pNode->pNext = tmpNode;

		returnvalue = tmpNode->ndata;
		free(tmpNode);
		return returnvalue;
	}
}


int main()
{
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	printf("%d\n", Dequeue());
	printf("%d\n", Dequeue());
	printf("%d\n", Dequeue());
	printf("%d\n", Dequeue());
	printf("%d\n", Dequeue());

	system("pause");
	return 0;
}