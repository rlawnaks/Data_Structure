#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
	ElementType Data;
}Node;

// 원형 배열 큐
typedef struct CircularQueue
{
	int Capacity;
	int Front;	// 전단의 위치
	int Rear;	// 후단의 위치

	Node* Node;
}CircularQueue;

// Create Queue
void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Node = (Node*)malloc(sizeof(Node) * (Capacity + 1));

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;

}

// Destroy Queue
void CQ_DestroyQueue(CircularQueue* Queue)
{
	free(Queue->Node);
	free(Queue);
}

// Enqueue
void CA_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;

	// 후단의 위치가 배열의 끝에 있는 경우
	//	 -> 후단의 위치를 처음으로 옮긴다 
	if (Queue->Rear == Queue->Capacity)
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
	{
		Position = Queue->Rear++;
	}

	Queue->Node[Position].Data = Data;

}

// Dequeue
ElementType CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;


	// 전단의 위치가 배열의 끝에 있는경우
	//   -> 전단의 위치를 처음으로 옮긴다
	if (Queue->Front == Queue->Capacity)
	{
		Queue->Front = 0;
	}
	else
	{
		Queue->Front++;
	}

	return Queue->Node[Position].Data;

}

// IsEmpty
int CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

// IsFull
int CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
	{
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	}
	else
	{
		return (Queue->Rear + 1) == Queue->Front;
	}
}