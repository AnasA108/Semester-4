#include <iostream>
#include"Stack.h"
#include "linklist.h"
using namespace std;

template <class T>
Node<T>* reverseList(Node<T>* head) {
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    LinkedList<int> list;

    list.insertEnd(2);
    list.insertEnd(4);
    list.insertEnd(6);
    list.insertEnd(8);
    list.insertEnd(10);

    cout << "Original: ";
    list.display();

    Node<int>* newHead = reverseList(list.getHead());

    cout << "Reversed: ";
    Node<int>* temp = newHead;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}