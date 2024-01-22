#include <stdlib.h>

typedef struct Node
{
	char* Data;
	Node* Next;
}Node;

typedef struct LinkedQueue
{
	int Count;
	Node* Front;	// 전단의 위치
	Node* Rear;	// 후단의 위치
}LinkedQueue;

// Create Queue
void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)Queue(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

// Enqueue
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else {
		Queue->Rear->Next = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}

// Dequeue
Node* LQ_Dequeue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;

	if (Queue->Front->Next == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->Next;
	}

	Queue->Count--;

	return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}

// Destory Node
void LQ_DestroyNode(Node* _Node) 
{
	free(_Node->Data);
	free(_Node);
}

// Destroy Queue
void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		Node* Poped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Poped);
	}

	free(Queue);
}