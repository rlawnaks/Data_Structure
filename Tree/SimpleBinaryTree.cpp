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

// 전위 순회
void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 뿌리 노드
	printf(" %c", Node->Data);

	// 왼쪽 하위 트리
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리
	SBT_PreorderPrintTree(Node->Right);
}

// 중위 순회
void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리
	SBT_InorderPrintTree(Node->Left);

	// 뿌리 노드
	printf(" %c", Node->Data);

	// 오른쪽 하위 트리
	SBT_InorderPrintTree(Node->Right);

}

// 후위 순회
void SBT_PostordderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_PostordderPrintTree(Node->Left);

	SBT_PostordderPrintTree(Node->Right);

	printf(" %c", Node->Data);
}

// Destroy Tree
//  -> 후위 순회를 이용한다. (가장 끝 노드부터 하기위해서)
void SBT_DestoryTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	SBT_DestoryTree(Node->Left);

	SBT_DestoryTree(Node->Right);

	SBT_DestroyNode(Node);
}