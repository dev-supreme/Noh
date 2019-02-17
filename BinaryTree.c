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
	if(ChildNode->pLeft ==)
	if ((NULL == tmpNode->pLeft) || (NULL == tmpNode->pRight))
	{

	}

	;
}
int main(void)
{
	InsertNode(7);
	InsertNode(10);
	InsertNode(3);
	InsertNode(5);
	InsertNode(14);
	InsertNode(12);
	InsertNode(2);
	InsertNode(17);
	InsertNode(4);
	InsertNode(9);

	system("pause");
	return 0;
}