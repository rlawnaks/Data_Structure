#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char* Data;
	Node* NextNode;
} Node;

typedef struct LinkedListStack
{
	Node* List;
	Node* Top;
}LinkedListStack;

// Create Stack
void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

// Create Node
Node* LLS_CreateNode(char* Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(Data) + 1);

	strcpy(NewNode->Data, Data);

	NewNode->NextNode = NULL;

	return NewNode;
}

// Destory Node
void LLS_DestroyNode(Node* _Node) 
{
	free(_Node->Data);
	free(_Node);
}

// IsEmpty
int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}

// Push
void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else 
	{
		// �� ��� �ø���
		Stack->Top->NextNode = NewNode;
	}

	// Top ��� ���
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* Top = Stack->Top;

	// ���ÿ� �ϳ��� ��常 �ִ� ���
	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// �ι�° ��� Ž��
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Top) 
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}
	return Top;
}

// Destroy Stack
void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack)) 
	{
		Node* Pop = LLS_Pop(Stack);
		LLS_DestroyNode(Pop);
	}
	free(Stack);
}

// Top
Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

// Size
int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;

	Node* Current = Stack->List;
	while (Current != NULL)
	{
		Count++;
		Current = Current->NextNode;
	}

	return Count;
}