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
Node* deleteAllOccurrences(Node* head, int val) {
    if (head == NULL) 
	return NULL;

    int cnt = 0;

    // Delete occurrences from head
    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cnt++;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Delete occurrences in rest of the list
    while (temp != NULL) {
        if (temp->data == val) {
            prev->next = temp->next;
            Node* delNode = temp;
            temp = temp->next;
            delete delNode;
            cnt++;
        } 
		else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Count: " << cnt << endl;
    return head;
}
