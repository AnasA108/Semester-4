#include<iostream>
#include "linklist.h"
using namespace std;
void countEvenOdd(Node<int>* head, int& even, int& odd) {
    even = 0;
    odd = 0;

    Node<int>* curr = head;
    while (curr != nullptr) {
        if (curr->data % 2 == 0)
            even++;
        else
            odd++;
        curr = curr->next;
    }
}

int main() {
    LinkedList<int> list;

    list.insertEnd(3);
    list.insertEnd(8);
    list.insertEnd(15);
    list.insertEnd(22);
    list.insertEnd(7);
    list.insertEnd(14);
    list.insertEnd(9);
    list.insertEnd(6);

    list.display();

    int even, odd;
    countEvenOdd(list.getHead(), even, odd);

    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
}