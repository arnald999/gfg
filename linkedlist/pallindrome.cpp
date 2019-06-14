#include <iostream>
#include <stack>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

void push(Node **rehead, int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->next = *rehead;
	*rehead = temp;
}

void print(Node *head)
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void pallindrome(Node *head)
{
	stack<int> s;
	
	Node *temp = head;
	while(temp !=NULL)
	{
		s.push(temp->data);
		temp = temp->next;
	}
	
	int flag = 1;
	Node *newtemp = head;
	int i;
	while(!s.empty())
	{
		i = s.top();
		s.pop();
		if(i != newtemp->data)
		{
			//cout<<"Not a pallindrome"<<endl;
			flag = 0;
			break;
		}
		newtemp = newtemp->next;
	}
	
	if(flag==1)
	{
		cout<<"Pallindrome"<<endl;
	}
	
	else if(flag==0)
	{
		cout<<"Not a pallindrome"<<endl;
	}
}

int main()
{
	Node *newnode;
	
	Node *head1 = new Node();
	head1->data = 5;

	
	newnode = new Node();
	newnode->data = 1;
	head1->next = newnode;
	
	newnode = new Node();
	newnode->data = 3;
	head1->next->next = newnode;
	//head2->next->next->next = newnode;
	
	newnode = new Node();
	newnode->data = 5;
	head1->next->next->next = newnode;
	//head2->next->next->next->next = newnode;
	
	print(head1);
	
	pallindrome(head1);
	//print(res);
	return 0; 
}
