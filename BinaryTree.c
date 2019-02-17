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
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

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
	Node* tmpNode = NULL;  //�ӽó�弱��
	Node* ParentNode = NULL;
	Node* ChildNode;

	tmpNode = pRoot;

	//��� Ž��

	while (tmpNode != NULL && tmpNode->nData != data) // tmpNode->nData = data, Ž������ tmpNode = NULL, ã�� data�� tree�������� ����
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
	if (ParentNode == NULL)//�θ��忡 �ƹ��͵� ��������ʾ�����//data�� tree�� ��������������(while������ tmpNode = NULL�϶�)
	{
		printf("�˻��Ͻ� Node�� �������� �ʽ��ϴ�.\n");
		return;
	}

	//if childNode == Leaf
	if ((NULL == tmpNode->pLeft) && (NULL == tmpNode->pRight))
	{
		if (ParentNode != NULL)
		{
			if (ParentNode->pLeft = tmpNode) //�θ��� ������ ��尡�����Ҷ�
			{
				ParentNode->pLeft == NULL; //��� �ʱ�ȭ
			}
			else
			{
				ParentNode->pRight == NULL; //�θ��� ������ ��� �����Ҷ� ����ʱ�ȭ
			}
		}
		else //�θ��尡 NULL�̸� pRoot�ʱ�ȭ
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
