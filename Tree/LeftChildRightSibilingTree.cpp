#include <stdlib.h>

typedef char ElementType;

typedef struct LCRSNode
{
	LCRSNode* LeftChild;
	LCRSNode* RightSibling;

	ElementType Data;
}LCRSNode;

// Create Node
LCRSNode* LCRS_CreateNode(ElementType Data) 
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = Data;

	return NewNode;
}

// Destroy Node
void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

// Destroy Tree
void LCRS_DestroyTree(LCRSNode* Root) {

	if (Root->RightSibling != NULL)
	{
		LCRS_DestroyNode(Root->RightSibling);
	}

	if (Root->LeftChild == NULL) 
	{
		// 자식 노드 찾아 내려가며 
		LCRS_DestroyNode(Root->LeftChild);
	}

	Root->RightSibling = NULL;
	Root->LeftChild = NULL;

	LCRS_DestroyNode(Root);
}

// AddChildNode
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	// 자식 노드가 없는 경우
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		// 자식 노드의 형제 노드 중 가장 끝 노드를 찾아 자식 노드 연결
		LCRSNode* Temp = Parent->LeftChild;

		while (Temp->RightSibling != NULL)
			Temp = Temp->RightSibling;

		Temp->RightSibling = Child;
	}

}

