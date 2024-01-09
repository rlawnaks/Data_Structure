#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
	ElementType Data;
	struct Node* NextNode;
};

// Create Node
Node* SLL_CreateNode(ElementType Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->NextNode = NULL;

	return NewNode;
}

// Destroy Node
void SLL_DestroyNode(Node* Node) {
	free(Node);
}

// Append Node
void SLL_AppendNode(Node** Head, Node* NewNode) {

	// ** ��� ��尡 ����ִ� ���	
	// **		->	���ο� ��尡 ��� ��尡 �ȴ�. 
	if ((*Head) == NULL) {
		*Head = NewNode;
		return;
	}

	// ** ���� ��带 ã�´�.
	Node* Tail = (*Head);
	while (Tail->NextNode != NULL) {
		Tail = Tail->NextNode;
	}

	// ** ���ο� ��� ����
	Tail->NextNode = NewNode;

}

// Insert Node
void SLL_InsertNodeAt(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// Insert Head
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if ((*Head)->NextNode == NULL) {
		*Head = NewHead;
		return;
	}
	NewHead->NextNode = *Head;
	*Head = NewHead;
}

// Get Node
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	// ** ��ġ�� ���� �̵�
	// **	-> ����Ʈ �� OR �ش� ��ġ�� ������ ���
	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	// ** �ش� ��� ��ȯ
	return Current;
}

// Remove Node
void SLL_RemoveNode(Node** Head, Node* Remove) {
	// ** ��� ��带 ������ ���
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		return;
	}

	Node* Current = *Head;
	// ** �ش� ��� Ž�� 
	while (Current != NULL && Current->NextNode != Remove) {
		Current = Current->NextNode;
	}

	// ** ������ ��� ������ ��带 ����
	if (Current != NULL) {
		Current->NextNode = Remove->NextNode;
	}

	free(Remove);
}

