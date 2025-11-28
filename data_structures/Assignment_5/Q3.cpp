#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		
		Node(int data1)
		{
			data=data1;
			next=NULL;
		}
		Node(int data1,Node* next1)
		{
			data=data1;
			next=next1;
		}
};
Node* middle(Node* head)
{
	if(head==NULL)
	return NULL;
	
	Node*slow=head;
	Node*fast=head;
	
	while(fast->next!=NULL && fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow; // slow will be middle (odd) OR second middle (even)
}
