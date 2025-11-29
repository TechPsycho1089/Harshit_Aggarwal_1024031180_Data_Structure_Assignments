#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(): next(nullptr),data(0) {}
    Node(int a){ data = a; next = nullptr; }
};

class Linkedlist{
    Node* head;
    public:
    Linkedlist(){
        head = nullptr;
    }
    void insert_at_beginning(int num){
        Node* newNode = new Node(num); 
        newNode->next = head;
        head = newNode;
    }
    void insert_at_end(int num){
        Node* newNode = new Node(num);

        if (!head){         //if head is null.
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next){    //temp->next is not null
           temp = temp->next; 
        }
        temp->next = newNode;
    }
    void insert_after(int num, int ref){
        Node* newNode = new Node(num);

        if (!head){         //if head is null
            cout<<"Error: Linked list is empty."<<endl;
            return;
        }

        Node* temp = head;

        while (temp->data != ref && temp->next){   // while pointer is not found and end of the list is not reached.
            temp = temp->next;
        }
        if (temp->data == ref){
            newNode->next = temp->next;
            temp->next = newNode;
            cout<<"New node inserted at correct at place."<<endl;
            return;
        }
        cout<<"Error: reference not found."<<endl;
        delete newNode;
    }
    void delete_from_beginning(){
        if (!head){
            cout<<"Error: Linked list empty, no node to delete."<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void delete_from_end(){
        if (!head){
            cout<<"Error: Linked list empty, no node to delete"<<endl;
            return;
        }

        Node* temp = head;
        
        if (!head->next){
            cout<<"Node deleted successfully"<<endl;
            head = nullptr;
            delete temp;
            return;   
        }

        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout<<"Node deleted successfully."<<endl;
    }
    void delete_node(int ref){
        if (!head){
            cout<<"Error: Linked list empty, no node to delete"<<endl;
            return;
        }
        Node* temp = head;

        if (temp->data == ref){
            cout<<"Refernce node found and deleted."<<endl;
            head = head->next;
            delete temp;
            return;
        } 

        Node* prev = nullptr;

        while (temp->data != ref && temp->next){
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == ref){
            cout<<"Reference node found and deleted."<<endl;
            prev->next = temp->next;
            delete temp;
            return;
        }
        cout<<"Error: Reference node not found."<<endl;
    }
    int search(int ref){
        int count = 0;
        Node* temp = head;
        
        while (temp && temp->data != ref){
            temp = temp->next;
            count++;
        }
        if (!temp){
            cout<<"Error: Reference not found."<<endl;
            return -1;
        }
        cout<<"Reference found."<<endl;
        return count;
    }

    void display(){
        cout<<"head ";
        
        Node* temp = head;

        while (temp){
            cout<<" -> "<<temp->data;
            temp = temp->next;
        }
        cout<<" -> NULL"<<endl;
    }

    void count_delete_occurences(int ref){
        if (!head) {                            // checks if the linked list is empty.
            cout<<"Error: linked list empty."<<endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        
        while (head && head->data == ref){              // checks if the head points to the reference.
            head = head->next;
            delete temp;
            temp = head;
            count++;
        }

        // If all nodes deleted
        if (!temp) {
            cout << "No of occurences of the reference integer is " << count << endl;
            return;
        }

        Node* prev = temp;
        temp = temp->next;

        while (temp){                           // checks if end of linked is reached.
            if (temp->data == ref){
                count++;
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        cout<<"No of occurences of the reference integer is "<<count<<endl;
    }

    void find_middle(){
        if (!head) {
            cout << "Error: linked list is empty." << endl;
            return;
        }
        Node* fast = head;
        Node* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"Middle element of the linked list is: "<<slow->data<<endl;
    }
    void reverse(){
        if (!head) {
            cout << "Error: linked list is empty." << endl;
            return;
        }
        Node* next = nullptr;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    Linkedlist list;
    int choice, num, ref, pos;

    while (true) {
        cout << "\n------ LINKED LIST MENU ------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search a value\n";
        cout << "8. Display list\n";
        cout << "9. Count & delete occurrences of a value\n";
        cout << "10. Find middle element\n";
        cout << "11. Reverse the list\n";
        cout << "12. Exit\n";
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
                list.delete_from_beginning();
                break;

            case 5:
                list.delete_from_end();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> ref;
                list.delete_node(ref);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> ref;
                pos = list.search(ref);
                if (pos != -1)
                    cout << "Element found at index: " << pos << endl;
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Enter value to count & delete: ";
                cin >> ref;
                list.count_delete_occurences(ref);
                break;

            case 10:
                list.find_middle();
                break;

            case 11:
                list.reverse();
                cout << "List reversed.\n";
                break;

            case 12:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

