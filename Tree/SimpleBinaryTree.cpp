#include <stdlib.h>
#include <stdio.h>

typedef char ElementType;

typedef struct SBTNode
{
	SBTNode* Left;
	SBTNode* Right;

	ElementType Data;
}SBTNode;

// Create Node
SBTNode* SBT_CreateNode(ElementType Data)
{
	SBTNode* NewNode = (SBTNode *)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = Data;

	return NewNode;
}

// Destroy Node
void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

// ���� ��ȸ
void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// �Ѹ� ���
	printf(" %c", Node->Data);

	// ���� ���� Ʈ��
	SBT_PreorderPrintTree(Node->Left);

	// ������ ���� Ʈ��
	SBT_PreorderPrintTree(Node->Right);
}

// ���� ��ȸ
void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// ���� ���� Ʈ��
	SBT_InorderPrintTree(Node->Left);

	// �Ѹ� ���
	printf(" %c", Node->Data);

	// ������ ���� Ʈ��
	SBT_InorderPrintTree(Node->Right);

}

// ���� ��ȸ
void SBT_PostordderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_PostordderPrintTree(Node->Left);

	SBT_PostordderPrintTree(Node->Right);

	printf(" %c", Node->Data);
}

// Destroy Tree
//  -> ���� ��ȸ�� �̿��Ѵ�. (���� �� ������ �ϱ����ؼ�)
void SBT_DestoryTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_DestoryTree(Node->Left);

	SBT_DestoryTree(Node->Right);

	SBT_DestroyNode(Node);
}