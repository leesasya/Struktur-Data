#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = NULL;

    int key = 20;
    bool found = false;

    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Pencarian: Data " << key << " ditemukan!\n";
            found = true;
            break; 
        }
        current = current->next;
    }

    if (!found) cout << "Pencarian: Data tidak ditemukan.\n";

    return 0;
}