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

	// ** 헤드 노드가 비어있는 경우	
	// **		->	새로운 노드가 헤드 노드가 된다. 
	if ((*Head) == NULL) {
		*Head = NewNode;
		return;
	}

	// ** 테일 노드를 찾는다.
	Node* Tail = (*Head);
	while (Tail->NextNode != NULL) {
		Tail = Tail->NextNode;
	}

	// ** 새로운 노드 연결
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

	// ** 위치한 노드로 이동
	// **	-> 리스트 끝 OR 해당 위치에 도달한 경우
	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	// ** 해당 노드 반환
	return Current;
}

// Remove Node
void SLL_RemoveNode(Node** Head, Node* Remove) {
	// ** 헤드 노드를 삭제할 경우
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		return;
	}

	Node* Current = *Head;
	// ** 해당 노드 탐색 
	while (Current != NULL && Current->NextNode != Remove) {
		Current = Current->NextNode;
	}

	// ** 삭제할 노드 다음의 노드를 연결
	if (Current != NULL) {
		Current->NextNode = Remove->NextNode;
	}

	free(Remove);
}

