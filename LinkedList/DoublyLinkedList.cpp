#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
	ElementType Data;
	Node* NextNode;
	Node* PrevNode;
}Node;

// Create Node
Node* DLL_CreateNode(ElementType Data) {
	Node* NewNode = (Node *)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

// Destroy Node
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

// Append Node
void DLL_AppendNode(Node** Head, Node* NewNode) {

	// ��� ��尡 ���� ��� ���ο� ��带 ����
	if (*Head == NULL) {
		*Head = NewNode;
		return;
	}

	// ���� ��带 ã�´�
	Node* Tail = NewNode;
	while (Tail->NextNode != NULL) {
		Tail = Tail->NextNode;
	}

	// ���� ��忡 �� ��� ����
	Tail->NextNode = NewNode;
	NewNode->PrevNode = Tail;

}

// Get Node
Node* DLL_GetNodeAt(Node* Head, int Location) {
	
	Node* Current = Head;

	while (Current != NULL && --Location >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

// Remove Node
void DLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		(*Head) = Remove->NextNode;
		Remove->PrevNode = NULL;
		DLL_DestroyNode(*Head);
		return;
	}

	Node* TempNode = Remove;

	if (Remove->NextNode != NULL) {
		Remove->NextNode->PrevNode = TempNode->PrevNode;
	}

	if (Remove->PrevNode != NULL) {
		Remove->PrevNode->NextNode = TempNode->NextNode;
	}

	Remove->PrevNode = NULL;
	Remove->NextNode = NULL;
}

// Insert Node
void DLL_InsertAfter(Node* Current, Node* NewNode) {

	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}