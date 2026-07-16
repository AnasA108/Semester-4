#include<iostream>
#include "linklist.h"
#include "Stack.h"
using namespace std;
#include <stack>
using namespace std;

void reverseList(Node<int>* head) {
    stack<int> s;
    Node<int>* curr = head;

    while (curr != nullptr) {
        s.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
        curr->data = s.top();
        s.pop();
        curr = curr->next;
    }
}

int main() {
    LinkedList<int> list;

    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(5);
    list.insertEnd(7);
    list.insertEnd(9);

    cout << "Original: ";
    list.display();

    reverseList(list.getHead());

    cout << "Reversed: ";
    list.display();
}