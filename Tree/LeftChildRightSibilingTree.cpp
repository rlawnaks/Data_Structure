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
		// �ڽ� ��� ã�� �������� 
		LCRS_DestroyNode(Root->LeftChild);
	}

	Root->RightSibling = NULL;
	Root->LeftChild = NULL;

	LCRS_DestroyNode(Root);
}

// AddChildNode
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	// �ڽ� ��尡 ���� ���
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		// �ڽ� ����� ���� ��� �� ���� �� ��带 ã�� �ڽ� ��� ����
		LCRSNode* Temp = Parent->LeftChild;

		while (Temp->RightSibling != NULL)
			Temp = Temp->RightSibling;

		Temp->RightSibling = Child;
	}

}

