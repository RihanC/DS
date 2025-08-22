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
    Node* head;

public:
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

    // Sort using Bubble Sort
    void sortList() {
        if (head == NULL) return;

        bool swapped;
        Node* ptr;
        Node* last = NULL;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != last) {
                if (ptr->data > ptr->next->data) {
                    // swap values
                    int temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            last = ptr;
        } while (swapped);
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
    DoublyLinkedList dll;
    dll.insertAtEnd(40);
    dll.insertAtEnd(10);
    dll.insertAtEnd(30);
    dll.insertAtEnd(20);

    cout << "Original List:\n";
    dll.display();

    dll.sortList();

    cout << "Sorted List:\n";
    dll.display();

    return 0;
}
