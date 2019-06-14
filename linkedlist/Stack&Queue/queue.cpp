#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Queue
{
	public:
		Node *front, *rear;
};

Queue *createQueue()
{
	Queue *q = new Queue();
	q->front = q->rear = NULL;
	return q;
}

void enqueue(Queue *q, int k)
{
	Node *temp = new Node();
	temp->data = k;
	temp->next = NULL;
	
	if(q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}
	
	q->rear->next = temp;
	q->rear = temp;
}

Node *dequeue(Queue *q)
{
	if(q->front == NULL)
		return NULL;
		
	Node *temp = q->front;
	q->front = q->front->next;
	
	// If front becomes NULL, then  
	// change rear also as NULL  
	if (q->front == NULL)  
		q->rear = NULL;  
	return temp;  	
}


int main()
{
	Queue *q = createQueue();
	enqueue(q,10);
	enqueue(q,39);
	enqueue(q,2);
	enqueue(q,339);
	
	Node *d = dequeue(q);
	while(d!=NULL)
	{
		cout<<"Dequeue item : "<<d->data<<endl;
		d = d->next;
	}
	return 0;
}

