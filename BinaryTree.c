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
	Node *pNewNode = (Node*)malloc(sizeof(Node)); //��� ���� ���� head�޸𸮿� �Ҵ� (malloc)

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