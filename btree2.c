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
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

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
	Node* tmpNode = *root;  //임시노드선언
	Node* ParentNode = NULL;
	Node* ChildNode = NULL;
	//노드 탐색(따로 함수 빼주면 좋을듯)
	while (tmpNode != NULL && tmpNode->nData != data) // tmpNode->nData = data, 탐색종료 tmpNode = NULL, 찾는 data가 tree에없을때 종료
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
	if (ParentNode == NULL)//부모노드에 아무것도 저장되지않았을때//data가 tree에 존재하지않을때(while문에서 tmpNode = NULL일때)
	{
		printf("검색하신 Node가 존재하지 않습니다.\n");
		free(tmpNode);
		return;
	}
	//if childNode == Leaf
	else if ((NULL == tmpNode->pLeft) && (NULL == tmpNode->pRight))
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
			root == NULL;
		free(tmpNode);
	}
	//if childNode == 1
	else if ((NULL != tmpNode->pLeft) || (NULL != tmpNode->pRight))
	{
		if (ParentNode->pLeft == tmpNode) //부모노드 왼쪽에 탐색노드가 있는경우
		{
			if (tmpNode->pLeft != NULL) // 탐색노드의 왼쪽에 값이 있을때
			{
				ParentNode->pLeft = tmpNode->pLeft; //부모노드와 왼쪽값 연결
			}
			else if (tmpNode->pRight != NULL)
			{
				ParentNode->pLeft = tmpNode->pRight;
			}
		}
		else if(ParentNode->pRight == tmpNode) //부모노드의 오른쪽에 탐색노드가 있는경우
		{
			if (tmpNode->pLeft != NULL) // 탐색노드의 왼쪽에 값이 있을때
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
		if (ParentNode->pLeft == tmpNode) //부모노드 왼쪽에 탐색노드가 있는경우
		{
			if (tmpNode->pLeft->nData <= ParentNode->nData && tmpNode->pRight->nData <= ParentNode->nData) //둘다 작으면
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