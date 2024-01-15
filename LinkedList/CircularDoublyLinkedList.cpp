#include <stdlib.h>

typedef int ElementType;

typedef struct Node 
{
	ElementType Data;
	Node* NextNode;
	Node* PrevNode;
}Node;

// Create Node
Node* CDLL_CreateNode(ElementType Data) 
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// Destroy Node
void CDLL_DestroyNode(Node* Node) 
{
	free(Node);
}

// Append Node
void CDLL_AppendNode(Node** Head, Node* NewNode) 
{

	// 헤드 노드가 빈 경우에 새 노드를 헤드 노드로
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
		return;
	}

	// 꼬리 노드와 헤드 노드 사이 삽입
	Node* Tail = (*Head)->PrevNode;
	
	Tail->NextNode->PrevNode = NewNode;
	Tail->NextNode = NewNode;
	NewNode->NextNode = *Head;
	NewNode->PrevNode = Tail;

}

// Insert Node
void CDLL_InsertAfter(Node* Current, Node* NewNode) 
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}

}

// Remove Node
void CDLL_RemoveNode(Node** Head, Node* Remove)
{

	// 삭제 할 노드가 헤드 노드인 경우
	if ((*Head) == Remove) 
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		(*Head) = Remove->NextNode;
	}
	else 
	{
		Remove->NextNode->PrevNode = Remove->PrevNode;
		Remove->PrevNode->NextNode = Remove->NextNode;
	}

	Remove->NextNode = NULL;
	Remove->PrevNode = NULL;

	CDLL_DestroyNode(Remove);

}

// Get Node
Node* CDLL_GetNodeAt(Node* Head, int Location) 
{
	Node* Current = Head;

	while (Current != NULL && --Location >= 0) 
	{
		Current = Current->NextNode;
	}

	return Current;
}