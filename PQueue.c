//��ũ�� ����Ʈ ordered insert / find / delete ����
//����

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

Node *head = NULL;      //������
int Enqueue(int);
void Pop();
int count = 0;

int Enqueue(int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

	pNewNode->nData = data;
	pNewNode->pNext = NULL;   //pnewNode �� ������ ����

	if (NULL == head)
	{
		head = pNewNode;
	}
	else
	{
		Node* pNode = head; //�Ǵٸ�����
		
		if (pNode->nData <= pNewNode->nData)
		{
			pNewNode->pNext = pNode;
			head = pNewNode;
		}
		else
		{
			//�߰����� ���� ������ ��
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
	printf("���� ������ �������� '0'�� �Է��ϼ���\n");
	printf("Put Insert number\n");
	while (true)
	{
		scanf_s("%d", &data);
		// ���� ���� Ȯ�� �� ��ȿ�� �˻� 

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