#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct _Node
{
	int nData;
	struct _Node* pLeft;
	struct _Node* pRight;
}Node;

typedef struct _QNode
{
	Node* qData;
	struct _QNode *pNext;
}QNode;

typedef struct _Queue
{
	QNode* front;
	QNode* rear;
}Queue;


void Enqueue(Queue *queue, Node* data)
{
	QNode* qNewNode = (QNode*)malloc(sizeof(QNode));

	qNewNode->qData = data;
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

Node* Dequeue(Queue* queue)
{
	QNode* QtmpNode = queue->front;
	if (queue->front == NULL)
		return NULL;

	Node *Data = QtmpNode->qData;
	queue->front = queue->front->pNext;

	free(QtmpNode);
	QtmpNode = NULL;
	return Data;
}

void InsertNode(Node **root, int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

	pNewNode->nData = data;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	Node *pRoot = *root;

	if (NULL == pRoot)
	{
		*root = pNewNode;
	}
	else
	{
		Node *pNode = pRoot;
		//smalelr than parent Node
		
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
					pNode = pNode->pLeft;
				}
			}
			else // bigger than parent Node
			{
				if (pNode->pRight == NULL)
				{
					pNode->pRight = pNewNode;
					break;
				}
				else
				{
					pNode = pNode->pRight;
				}
			}
		}
	}
}


int DeleteNode(Node** root, int data)
{
	Node* tmpNode = *root;  //�ӽó�弱��
	Node* ParentNode = NULL;
	Node* ChildNode = NULL;
	//��� Ž��(���� �Լ� ���ָ� ������)
	while (tmpNode != NULL && tmpNode->nData != data) // tmpNode->nData = data, Ž������ tmpNode = NULL, ã�� data�� tree�������� ����
	{
		ParentNode = tmpNode;
		if (data <= ParentNode->nData)
		{
			tmpNode = ParentNode->pLeft;
		}
		else
		{
			tmpNode = ParentNode->pRight;
		}
	}
	if (ParentNode == NULL)//�θ��忡 �ƹ��͵� ��������ʾ�����//data�� tree�� ��������������(while������ tmpNode = NULL�϶�)
	{
		printf("�˻��Ͻ� Node�� �������� �ʽ��ϴ�.\n");
		free(tmpNode);
		return;
	}
	//if childNode == Leaf
	else if ((NULL == tmpNode->pLeft) && (NULL == tmpNode->pRight))
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
			root == NULL;
		free(tmpNode);
	}
	//if childNode == 1
	else if ((NULL != tmpNode->pLeft) || (NULL != tmpNode->pRight))
	{
		if (ParentNode->pLeft == tmpNode) //�θ��� ���ʿ� Ž����尡 �ִ°��
		{
			if (tmpNode->pLeft != NULL) // Ž������� ���ʿ� ���� ������
			{
				ParentNode->pLeft = tmpNode->pLeft; //�θ���� ���ʰ� ����
			}
			else if (tmpNode->pRight != NULL)
			{
				ParentNode->pLeft = tmpNode->pRight;
			}
		}
		else if(ParentNode->pRight == tmpNode) //�θ����� �����ʿ� Ž����尡 �ִ°��
		{
			if (tmpNode->pLeft != NULL) // Ž������� ���ʿ� ���� ������
			{
				ParentNode->pLeft = tmpNode->pLeft;
			}
			else if (tmpNode->pRight != NULL)
			{
				ParentNode->pLeft = tmpNode->pRight;;
			}
		}
		free(tmpNode);
	}
	//if childNode == 2
	if ((NULL != tmpNode->pLeft) && (NULL != tmpNode->pRight))
	{
		if (ParentNode->pLeft == tmpNode) //�θ��� ���ʿ� Ž����尡 �ִ°��
		{
			if (tmpNode->pLeft->nData <= ParentNode->nData && tmpNode->pRight->nData <= ParentNode->nData) //�Ѵ� ������
			{
				while (tmpNode->pLeft != NULL)
				{

				}
			}
		}
		if (ParentNode->pRight == tmpNode)
		{

		}
	}

} 

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

	system("pause");
	return 0;
}