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
Node* insertHead(Node* head,int val)
{
	Node* newNode=new Node(val,head);
	return newNode;
}
Node* insertTail(Node* head,int val)
{
	Node* newNode=new Node(val);
	if(head==NULL)
	{
		return newNode;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
	return head;
}
Node* insertBefore(Node* head,int val,int beforeVal) {
    if (head == NULL) return NULL;
    if (head->data == beforeVal) return new Node(val, head);
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeVal) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found\n";
        return head;
    }
    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}
Node* insertAfter(Node* head,int val,int data1)
{
	if(head==NULL)
	{
		cout<<"can't be inserted\n";
		return;
	}
	Node* newNode=new Node(val);
	Node* temp=head;
	while(temp!=NULL && temp->data==data1)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"can't be inserted\n";
		return;
	}
	else
	{
		newNode->next=temp->next;
		temp->next=newNode;
	}
	return head;
}
Node* deleteHead(Node* head)
{
	if(head==NULL || head->next==NULL)
	return NULL;
	
	Node*temp=head;
	head=head->next;
	delete temp;
	return head;
}
Node* deleteTail(Node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return NULL;
	}
	Node* temp=head;
	Node* prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	delete temp;
	return head;
}
Node* deleteFromNodeWithValue(Node* head,int val)
{
	if(head==NULL || head->data==val)
	{
		return NULL;
	}
	Node* temp=head;
	Node* prev=NULL;
	while(temp!=NULL && temp->data!=val)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"can't be deleted\n";
		return;
	}
	else
	{
		prev->next=temp->next;
	    delete temp;
	}
	return head;
}
Node* searchNode(Node* head,int val)
{
	if(head==NULL)
	{
		cout<<"element not found\n";
		return;
	}
	Node* temp=head;
	int cnt=0;
	while(temp!=NULL && temp->data!=val)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp==NULL)
	{
		cout<<"element not found\n";
		return;
	}
	else{
		cout<<"element found and its position from head is : "<<cnt;
	}
	return head;
}
Node* display(Node* head)
{
	if(head==NULL)
	{
		cout<<"nothing to display\n";
		return;
	}
	Node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return head;
}

int main() {
    Node* head = NULL;
    int choice, val, ref;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete by value\n";
        cout << "7. Search a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insertHead(head, val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = insertTail(head, val);
                break;
            case 3:
                cout << "Enter new value and value after which to insert: ";
                cin >> val >> ref;
                head = insertAfter(head, val, ref);
                break;
            case 4:
                head = deleteHead(head);
                break;
            case 5:
                head = deleteTail(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                head = deleteFromNodeWithValue(head, val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                head = searchNode(head, val);
                break;
            case 8:
                head = display(head);
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
