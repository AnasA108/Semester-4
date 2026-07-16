#include <iostream>
#include"Stack.h"
#include "linklist.h"
using namespace std;


bool isPalindrome(LinkedList<char>& list) {
    Stack<char> st(list.size());

    Node<char>* temp = list.getHead();

    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = list.getHead();

    while (temp != nullptr) {
        if (temp->data != st.pop())
            return false;
        temp = temp->next;
    }

    return true;
}

int main() {
    LinkedList<char> list;

    string str = "racecar";

    int length = 0;
    for (int i = 0;str[i] != '\0';i++)
    {
        length++;
    }
    for (int i = 0; i <length; i++)
        list.insertEnd(str[i]);

    if (isPalindrome(list))
        cout << "PALINDROME";
    else
        cout << "NOT A PALINDROME";
}