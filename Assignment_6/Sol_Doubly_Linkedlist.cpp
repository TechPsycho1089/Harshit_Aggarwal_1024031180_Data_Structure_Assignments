#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node():data(0),prev(nullptr),next(nullptr){}

    Node(int a){
        data = a;
        prev = nullptr;
        next = nullptr;
    }
};

class Linkedlist{
    Node* head;
    public:
    Linkedlist():head(nullptr){}
    void insert_at_beginning(int num){
        Node* newNode = new Node(num);

        if (head) head->prev = newNode;
        newNode->next = head;
        head = newNode;
        
    }
    void insert_at_end(int num){
        Node* newNode = new Node(num);
        if (!head) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insert_after(int num,int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;

        while (temp && temp->data != ref){
            temp = temp->next;
        }

        if (temp) {
            Node* newNode = new Node(num);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        cout<<"Error: reference number not found."<<endl;
    }
    void insert_before(int num, int ref){
        if (!head) {
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != ref){
            temp = temp->next;
        }

        if (temp) {
            Node* newNode = new Node(num);
            newNode->prev = temp->prev;

            if (temp->prev) 
                temp->prev->next = newNode;
            else 
                head = newNode;
                
            temp->prev = newNode;
            newNode->next = temp;
            return;
        }
        cout<<"Error: reference node not found."<<endl;
    }
    void delete_at_beginning(){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }
    void delete_at_end(){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;
        while (temp->next) temp = temp->next;

        if (temp->prev)
            temp->prev->next = nullptr;
        else
            head = nullptr;
        
        delete temp;
    }
    void delete_node(int ref){
        if (!head) {
            cout<<"Error: Linked list empty."<<endl;
            return;
        }

        Node* temp = head;

        while(temp && temp->data != ref) temp = temp->next;

        if (temp){

            if(temp->prev)                                  //if statement for checking if temp is not first node.
                temp->prev->next = temp->next;
            else 
                head = temp->next;

            if(temp->next) temp->next->prev = temp->prev;      //if statement for checking if temp in not last node.
        }
    }
    int search(int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return -1;
        }

        int count = 0;
        Node* temp = head;

        while(temp && temp->data != ref){ 
            temp = temp->next;
            count++;
        }

        if (temp){
            cout<<"Node found at index "<<count<<endl;
            return count;
        }

        cout<<"Error: Node not found."<<endl;
        return -1;
    }
    void display(){
        cout<<"head";
        
        Node* temp = head;

        while(temp){
            cout<<" -> "<<temp->data;
            temp = temp->next;
        }

        cout<<" -> NULL"<<endl;
    }
};


int main() {
    Linkedlist list;
    int choice, num, ref;

    while (true) {
        cout << "\n------ DOUBLY LINKED LIST MENU ------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> num;
                list.insert_at_beginning(num);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> num;
                list.insert_at_end(num);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> num;
                cout << "Insert after which value? ";
                cin >> ref;
                list.insert_after(num, ref);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> num;
                cout << "Insert before which value? ";
                cin >> ref;
                list.insert_before(num, ref);
                break;

            case 5:
                list.delete_at_beginning();
                break;

            case 6:
                list.delete_at_end();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> ref;
                list.delete_node(ref);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> ref;
                list.search(ref);
                break;

            case 9:
                cout << "Current list: ";
                list.display();
                break;

            case 10:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}