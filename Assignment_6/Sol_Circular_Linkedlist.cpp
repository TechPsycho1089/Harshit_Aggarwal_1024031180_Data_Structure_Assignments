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
        newNode->next = head;
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
    int search(int ref){
        if (!head){
            cout<<"Error: Linked list empty."<<endl;
            return -1;
        }
        int count = 1;
        Node* temp = head;
        do{
            if (temp->data == ref){
                cout<<"Reference node found at index "<<count<<endl;
                return count;
            }
            count++;
            temp = temp->next;
        }while(temp!=head);
        cout<<"Error: Reference not found."<<endl;
        return -1;
    }
    void display(){
        if (!head){
            cout<<"Error: Linked list is empty."<<endl;
            return;
        }
        cout<<"Head";
        Node* temp = head;
        do{
            cout<<" -> "<<temp->data;
            temp = temp->next;
        } while (temp != head);
        cout<<" -> "<<head->data<<endl;
    }
    int get_size(){
        if (!head){
            cout<<"Size of the linked list is zero."<<endl;
            return 0;
        }
        int count = 0;
        Node* temp = head;
        do{
            temp=temp->next;
            count++;
        }while(temp!=head);
        cout<<"Size of the linked list is "<<count<<endl;
        return count;
    }
};

int main() {
    Linkedlist list;
    int choice, num, ref;

    while (true) {
        cout << "\n------- CIRCULAR LINKED LIST MENU -------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a value\n";
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
                list.delete_from_beginning();
                break;

            case 6:
                list.delete_from_end();
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
                list.display();
                break;

            case 10:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}