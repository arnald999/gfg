#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class compare
{
	public:
		bool operator()(Node *a, Node *b)
		{
			return a->data > b->data;
		}
};

Node *newNode(int k)
{
	Node *temp = new Node();
	temp->data = k;
	temp->next = NULL;
	return temp;
}

void printpq(priority_queue<Node*, vector<Node*>, compare> pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()->data<<" ";
		pq.pop();
	}
	cout<<endl;
}


Node* mergeKlist(Node *arr[], int k)
{
	Node *head = NULL, *last;
	priority_queue<Node*, vector<Node*>, compare> pq;
	//priority_queue<Node*, vector<Node*>, compare> test;
	
	for(int i = 0; i<k; i++)
	{
		pq.push(arr[i]);
		//test.push(arr[i]);
	}
	
	printpq(pq);
	
	while(!pq.empty())
	{
		Node *top = pq.top();
		pq.pop();
		
		if(top->next != NULL)
			pq.push(top->next);
			
		if(head==NULL)
		{
			head = top;
			last = top;
		}
		
		else
		{
			last->next = top;
			last = top;
		}
		printpq(pq);
	}
	return head;
}


void print(Node *head)
{
	Node *temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


int main() 
{ 
    int k = 3; // Number of linked lists 
    int n = 4; // Number of elements in each list 
  
    // an array of pointers storing the head nodes 
    // of the linked lists 
    Node* arr[k]; 
  
    // creating k = 3 sorted lists 
    arr[0] = newNode(1); 
    arr[0]->next = newNode(3); 
    arr[0]->next->next = newNode(5); 
    arr[0]->next->next->next = newNode(7); 
  
    arr[1] = newNode(2); 
    arr[1]->next = newNode(4); 
    arr[1]->next->next = newNode(6); 
    arr[1]->next->next->next = newNode(8); 
  
    arr[2] = newNode(0); 
    arr[2]->next = newNode(9); 
    arr[2]->next->next = newNode(10); 
    arr[2]->next->next->next = newNode(11); 
  
    // merge the k sorted lists 
    Node* head = mergeKlist(arr, k); 
  
    // print the merged list 
    print(head); 
  
    return 0; 
} 
