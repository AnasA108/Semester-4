#include <iostream>
#include"Stack.h"
#include "linklist.h"
using namespace std;

template <class T>
Node<T>* reverseK(Node<T>* head, int k) {
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (head != nullptr)
        head->next = curr;

    return prev;
}

int main() {
    LinkedList<int> list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    list.insertEnd(7);

    list.display();

   
    Node<int>* newHead = reverseK(list.getHead(),3);

    Node<int>* temp = newHead;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}