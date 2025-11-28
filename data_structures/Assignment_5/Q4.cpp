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
Node* reverse(Node* head)
{
	if(head==NULL)
	return NULL;
	
	Node* prev=NULL;
	Node* current=head;
	Node* nextt=NULL;
	
	while(current!=NULL)
	{
		nextt=current->next;   	//save next node
		current->next=prev;		//reverse current node's pointer
		prev=current;			//move prev forward
		current=nextt;			//move current forward
	}
	return prev;	//new head after reversal
}
