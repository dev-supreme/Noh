#include <stdio.h>
#include <string.h>
#include <Windows.h>

struct _Node
{
	int nData;
	struct _Node* pLeft;
	struct _Node* pRight;
}; typedef struct _Node Node;

struct _QNode
{
	Node* qdata;
	struct _QNode *pNext;
}; typedef struct _QNode QNode;

struct _Queue
{
	QNode* front;
	QNode* rear;
}; typedef struct _Queue Queue;


Node* pRoot = NULL;


void Enqueue(Queue *queue, Node* data)
{
	QNode* qNewNode = (QNode*)malloc(sizeof(QNode));

	qNewNode->qdata = data;
	qNewNode->pNext = NULL;

	if (queue->front == NULL)
	{
		queue->front = qNewNode;
		queue->rear = qNewNode;
	}
	else
	{
		queue->rear->pNext = qNewNode;
		queue->rear = qNewNode;
	}
}

QNode* Dequeue(Queue* queue)
{
	if (queue->front == NULL)
		return NULL;

	QNode* QtmpNode = queue->front;
	QNode* data = QtmpNode->qdata;
	queue->front = queue->front->pNext;

	free(QtmpNode);
	QtmpNode = NULL;
	return data;
}

void Printtree(Queue *queue)
{
	Node* data = NULL;
	Queue *q;

	Enqueue(&q, pRoot);
	while (1)
	{
		data = Dequeue(&q);
		if (data == NULL) break;
		printf("%d", data->nData);

		if (data->pLeft != NULL)
			Enqueue(&q, data->pLeft);
		if (data->pRight != NULL)
			Enqueue(&q, data->pRight);
	}
}

void InsertNode(Node **pRoot, int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewNode->nData = data;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;

	if (NULL == *pRoot)
	{
		*pRoot = pNewNode;
	}
	else
	{
		Node *pNode = *pRoot;
		//smalelr than parent Node
		if (pNewNode->nData < pNode->nData)
		{
			pNode->pLeft = pNewNode;
		}
		while (1) //Something on the Left or Right Node //pRoot->pLeft != NULL || pRoot->pRight != NULL
		{
			if (data <= pNode->nData) //smaller than parent Node
			{
				if (pNode->pLeft == NULL)
				{
					pNode->pLeft = pNewNode;
					break;
				}
				else
				{
					pNode->pLeft = pNode;
					continue;
				}
			}
			else if (data > pNode->nData) // bigger than parent Node
			{
				if (pNode->pRight == NULL)
				{
					pNode->pRight = pNewNode;
					break;
				}
				else
				{
					pNode->pRight = pNode;
					continue;
				}
			}
		}
	}
}

/*
int DeleteNode(int data)
{
	Node* tmpNode = NULL;  //임시노드선언
	Node* ParentNode = NULL;
	Node* ChildNode;

	tmpNode = pRoot;

	//노드 탐색

	while (tmpNode != NULL && tmpNode->nData != data) // tmpNode->nData = data, 탐색종료 tmpNode = NULL, 찾는 data가 tree에없을때 종료
	{
		ParentNode = tmpNode;
		if (data <= ParentNode->nData)
		{
			ParentNode->pLeft = tmpNode;
		}
		else
		{
			ParentNode->pRight = tmpNode;
		}
	}
	if (ParentNode == NULL)//부모노드에 아무것도 저장되지않았을때//data가 tree에 존재하지않을때(while문에서 tmpNode = NULL일때)
	{
		printf("검색하신 Node가 존재하지 않습니다.\n");
		return;
	}

	//if childNode == Leaf
	if ((NULL == tmpNode->pLeft) && (NULL == tmpNode->pRight))
	{
		if (ParentNode != NULL)
		{
			if (ParentNode->pLeft = tmpNode) //부모노드 좌측에 노드가존재할때
			{
				ParentNode->pLeft == NULL; //노드 초기화
			}
			else
			{
				ParentNode->pRight == NULL; //부모노드 우측에 노드 존재할때 노드초기화
			}
		}
		else //부모노드가 NULL이면 pRoot초기화
			pRoot == NULL;
	}

	//if childNode == 1
	if ((NULL != tmpNode->pLeft) || (NULL == tmpNode->pRight))
	{
		if (tmpNode->pLeft != NULL)
		{
			if(tmpNode->pLeft)
		}
	}d

	;
} */

int main(void)
{
	Node* root = NULL;

	InsertNode(&root, 7);
	InsertNode(&root, 10);
	InsertNode(&root, 3);
	InsertNode(&root, 5);
	InsertNode(&root, 14);
	InsertNode(&root, 12);
	InsertNode(&root, 2);
	InsertNode(&root, 17);
	InsertNode(&root, 4);
	InsertNode(&root, 9);

	Printtree(&root);

	system("pause");
	return 0;
}
