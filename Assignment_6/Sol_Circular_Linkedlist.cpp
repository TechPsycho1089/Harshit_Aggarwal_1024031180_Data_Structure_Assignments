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
    
};

int main(){

    return 0;
}