//링크드 리스트 ordered insert / find / delete 구현
//뎁스

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef enum {
	false = 0,
	true = 1
} bool;

struct Node
{
	int nData;
	struct Node *pNext;
}; typedef struct Node Node;

Node *head = NULL;      //시작점
int Enqueue(int);
void Pop();
int count = 0;

int Enqueue(int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewNode->nData = data;
	pNewNode->pNext = NULL;   //pnewNode 는 독립적 공간

	if (NULL == head)
	{
		head = pNewNode;
	}
	else
	{
		Node* pNode = head; //또다른공간
		
		if (pNode->nData <= pNewNode->nData)
		{
			pNewNode->pNext = pNode;
			head = pNewNode;
		}
		else
		{
			//중간값인 수가 들어왔을 때
			while (pNode->pNext != NULL)
			{
				if (pNode->pNext->nData <= pNewNode->nData)
				{
					pNewNode->pNext = pNode->pNext;
					pNode->pNext = pNewNode;
					break;
				}

				pNode = pNode->pNext;
			}

			if (pNode->pNext == NULL)
			{
				pNode->pNext = pNewNode;
			}
		}
	}
}

void Pop()
{
	Node* PopNode = head;
	Node* pNode = head;

	if (pNode->pNext != NULL)
	{
		printf("pop : %d\n", PopNode->nData);
		head = pNode->pNext;

		free(PopNode);
	}
	else
	{
		printf("pop : %d\n", pNode->nData);
		printf("Empty Queue");
	}
}


void PrintList()
{
	Node* pNode = head;
	while (pNode)
	{
		printf("%d -> ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

/*
void DisposeList()
{
	Node *p = head;
	while (p)
	{
		Node *tmp = p;
		p = p->pNext;
		free(tmp);
		tmp = NULL;
	}
}
*/
int main(void)
{
	int data;
	//Ordered Insert
	printf("숫자 삽입을 끝내려면 '0'을 입력하세요\n");
	printf("Put Insert number\n");
	while (true)
	{
		scanf_s("%d", &data);
		// 종료 조건 확인 및 유효성 검사 

		if (data == false)
		{
			printf("\nEnd Enqueue\n");
			break;
		}

		Enqueue(data);
	}
	PrintList();
	Pop();
	Pop();
	Pop();
	puts("");

	system("pause");
	return 0;
}