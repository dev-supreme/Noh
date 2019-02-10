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
		pRoot = pNewNode;
	}
	else
	{
		Node *pNode = pRoot;
		//smalelr than parent Node
		if (pNewNode->nData < pNode->nData)
		{
			pNode->pLeft = pNewNode;
		}
		while (pRoot->pLeft != NULL || pRoot->pRight != NULL) //Something on the Left or Right Node
		{
			if (pNewNode->nData < pNode->nData) //smaller than parent Node
			{
				pNode->pLeft = pNewNode;
			}
			else // bigger than parent Node
			{
				pNode->pRight = pNewNode;
			}
		}
	}
}

void Printtree()
{
	
}
int main(void)
{


	system("pause");
	return 0;
}