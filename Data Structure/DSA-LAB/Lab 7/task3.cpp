#include<iostream>
#include "linklist.h"
#include "Stack.h"
using namespace std;
int findMiddleFastSlow(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    cout << "Middle: " << findMiddleFastSlow(list.getHead()) << endl;
}