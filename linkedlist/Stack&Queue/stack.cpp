#include <iostream>
//#include <stdio.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

Node *top = NULL;

void push(int data)
{
	Node *temp = new Node();
	if(!temp)
	{
		cout<<"Heap Overflow"<<endl;
	}
	
	temp->data = data;
	temp->next = top;
	top = temp;
}

int isEmpty()
{
	return top==NULL;
}


int peek()
{
	if(!isEmpty())
		return top->data;
	else
		exit(EXIT_FAILURE);
}

void pop()
{
	Node *temp;
	
	if(top == NULL)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		temp = top;
		top = top->next;
		top->next = NULL;
		delete temp;
	}
}

void display()
{
	Node *temp;
	
	if(top == NULL)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		temp = top;
		while(!temp)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}


int main()
{
	push(11);
	push(12);
	push(13);
	push(14);
	push(15);
	push(16);
	display();
	cout<<peek()<<endl;
	pop();
	pop();
	display();
	cout<<peek()<<endl;
	return 0;
}
