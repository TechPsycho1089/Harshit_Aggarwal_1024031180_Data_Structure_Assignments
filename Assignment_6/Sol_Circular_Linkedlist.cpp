#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node():data(0),next(nullptr){}
    Node(int a):data(a),next(nullptr){}
};

class Linkedlist{
    Node* head;
    public:
    Linkedlist():head(nullptr){}

    void insert_at_beginning(int num){
        Node* newNode = new Node(num);
        if (!head){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        
        while(temp->next != head){
            temp=temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insert_at_end(int num){
        Node* newNode = new Node(num);
        if (!head){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        do{
            temp=temp->next;
        }while(temp->next != head);
        temp->next = newNode;
    }
    void insert_after(int num,int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }
        Node* temp = head;
        do{
            if (temp->data == ref){
                Node* newNode = new Node(num);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void insert_before(int num, int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        if (head->data == ref) {
            insert_at_beginning(num);
            return;
        }

        Node* temp = head;

        do{
            if (temp->next->data == ref){
                Node* newNode = new Node(num);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp=temp->next;
        }while(temp->next != head);

        cout<<"Error: Reference node not found."<<endl;
    }
    void delete_from_beginning(){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;
        if (head->next == head){
            delete temp;
            head = nullptr;
            return;
        }

        while(temp->next != head) temp = temp->next;
        head = head->next;
        delete temp->next;
        temp->next = head;
    }
    void delete_from_end(){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;
        if (head->next == head){
            delete temp;
            head = nullptr;
            return;
        }
        
        while (temp->next->next != head) temp = temp->next;
        delete temp->next;
        temp->next = head;
    }
    void delete_node(int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        if (head->data == ref){
            delete_from_beginning();
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->data == ref){
                if (temp->next == head) {
                    delete_from_end();
                    return;
                }
                Node* to_delete = temp->next;
                temp->next = to_delete->next;
                delete to_delete; 
                return;
            }
            temp = temp->next;
        }while(temp != head);

        
        cout<<"Error: reference node not found."<<endl;
    }
};

int main(){

    return 0;
}