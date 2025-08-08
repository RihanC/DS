#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node{value, nullptr};
    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of bounds. Inserting at the end.\n";
        insertAtEnd(head, value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value, position;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1) Insert at the Beginning\n";
        cout << "2) Insert at a Position (Middle)\n";
        cout << "3) Insert at the End\n";
        cout << "4) Display List\n";
        cout << "5) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAtPosition(head, value, position);
                break;

            case 3:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 4:
                printList(head);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
