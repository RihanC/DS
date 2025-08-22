#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Concatenate with another list
    void concatenate(DoublyLinkedList& other) {
        if (head == NULL) {  // If first list empty
            head = other.head;
            return;
        }
        if (other.head == NULL) return; // If second list empty

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        // Link last node of first list with head of second list
        temp->next = other.head;
        other.head->prev = temp;
    }

    // Display List
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll1, dll2;

    // First List
    dll1.insertAtEnd(1);
    dll1.insertAtEnd(2);
    dll1.insertAtEnd(3);

    // Second List
    dll2.insertAtEnd(4);
    dll2.insertAtEnd(5);
    dll2.insertAtEnd(6);

    cout << "List 1:\n";
    dll1.display();

    cout << "List 2:\n";
    dll2.display();

    // Concatenate
    dll1.concatenate(dll2);

    cout << "Concatenated List:\n";
    dll1.display();

    return 0;
}
