#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr;

// Function to insert a node at the start
void insertStart(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to insert a node after the nth node
void insertAfter(int val, int pos) {
    Node* temp = head;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (temp) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete the first node
void deleteStart() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to delete the last node
void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete the nth node
void deleteNth(int pos) {
    if (pos == 1) { deleteStart(); return; }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (temp && temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// Function to display the list
void display() {
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->data << (temp->next ? " -> " : "\n");
}

int main() {
    // Insert initial nodes
    insertEnd(20);
    insertEnd(30);

    // Insertion operations
    insertStart(10);   // List: 10 -> 20 -> 30
    cout << "After inserting start: "; 
    display();
    insertEnd(50);     // List: 10 -> 20 -> 30 -> 50
    cout << "After inserting end: "; 
    display();
    insertAfter(40, 3); // List: 10 -> 20 -> 30 -> 40 -> 50
    cout << "After insertions  3 nod: ";
    display();

    // Deletion operations
    deleteStart();     // List: 20 -> 30 -> 40 -> 50
    cout << "After deleting start: "; 
    display();

    deleteEnd();       // List: 20 -> 30 -> 40
    cout << "After deleting end: "; 
    display();

    insertEnd(60);     // List: 20 -> 30 -> 40 -> 60
    deleteNth(3);      // List: 20 -> 30 -> 60
    cout << "After deleting 3rd node: "; 
    display();

    return 0;
}