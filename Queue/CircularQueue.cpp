#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
	ElementType Data;
}Node;

// ���� �迭 ť
typedef struct CircularQueue
{
	int Capacity;
	int Front;	// ������ ��ġ
	int Rear;	// �Ĵ��� ��ġ

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

	// �Ĵ��� ��ġ�� �迭�� ���� �ִ� ���
	//	 -> �Ĵ��� ��ġ�� ó������ �ű�� 
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


	// ������ ��ġ�� �迭�� ���� �ִ°��
	//   -> ������ ��ġ�� ó������ �ű��
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