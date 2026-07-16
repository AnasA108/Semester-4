#include<iostream>
#include "linklist.h"
#include "Stack.h"
using namespace std;
int findMiddle(Node<int>* head) {
    int count = 0;
    Node<int>* curr = head;

    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    Stack<int> s(count);

    curr = head;
    while (curr != nullptr) {
        s.push(curr->data);
        curr = curr->next;
    }

    int mid = count / 2;

    for (int i = 0; i < mid; i++)
        s.pop();

    return s.peek();
}

int main() {
    LinkedList<int> list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);

    list.display();

    cout << "Middle: " << findMiddle(list.getHead()) << endl;
}