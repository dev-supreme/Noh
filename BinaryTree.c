#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct Node
{
	int nData;
	struct Node* pLeft;
	struct Node* pRight;
}Node;

Node* pRoot = NULL;

int InsertNode(int data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //노드 담을 공간 head메모리에 할당 (malloc)

	pNewNode->nData = data;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;

	if (NULL == pRoot)
	{
		pNewNode = pRoot;
	}
	else
	{
		Node *pNode = pRoot;
		//smalelr than parent Node
		if (pNewNode->nData < pNode->nData)
		{
			pNode->pLeft = pNewNode;
		}
		while (1) //Something on the Left or Right Node //pRoot->pLeft != NULL || pRoot->pRight != NULL
		{
			if (pNewNode->nData < pNode->nData) //smaller than parent Node
			{
				if (pNode->pLeft == NULL)
				{

					pNode->pLeft = pNewNode;
					break;
				}
				else
				{
					pNode->pLeft = pNode;
				}
			}
			else if (pNewNode->nData > pNode->nData) // bigger than parent Node
			{
				if (pNode->pRight == NULL)
				{
					pNode->pRight = pNewNode;
					break;
				}
				else
				{
					pNode->pRight = pNode;
				}
			}
			else
			{
				free(pNewNode);
				return -1;
			}
		}
	}
}

int main(void)
{
	InsertNode(7);
	InsertNode(10);
	InsertNode(3);

	system("pause");
	return 0;
}