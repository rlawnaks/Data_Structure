#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
	ElementType Data;
}Node;

typedef struct ArrayStack
{
	int Capacity;
	int Top;
	// 배열의 첫 번째 요소를 가리킴
	Node* Array;
}ArrayStack;


// Create Stack
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// Capacity만큼 스택 크기 할당
	(*Stack)->Array = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;

}

// Destory Stack
void AS_DestoryStack(ArrayStack* Stack) 
{
	free(Stack->Array);
	free(Stack);
}

// Push
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Array[++(Stack->Top)].Data = Data;
}

// Pop
ElementType AS_Pop(ArrayStack* Stack)
{
	return Stack->Array[(Stack->Top)--].Data;
}

// Top
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Array[(Stack->Top)].Data;
}

// Size
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top - 1;
}

// IsEmpty
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}