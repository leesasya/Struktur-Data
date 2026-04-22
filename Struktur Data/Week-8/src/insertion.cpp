#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    head->data = 20;
    head->next = new Node();
    head->next->data = 30;
    head->next->next = NULL;

    Node* newNode = new Node();
    newNode->data = 5;
    newNode->next = head;
    head = newNode; 

    Node* current = head;
    cout << "Setelah Insertion: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}