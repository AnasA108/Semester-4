#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    void insertEnd(T val);
    void insertFront(T val);
    void insertBefore(T val, int node_no);
    void removeFront();
    void removeAny(int node_no);
    bool search(T val);
    void display();
    bool isEmpty();
    Node<T>* getHead();
    int size();
};

// ─────────────────────────────────────────────
// Constructor
// ─────────────────────────────────────────────
template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

// ─────────────────────────────────────────────
// isEmpty : returns true if list has no nodes
// ─────────────────────────────────────────────
template <class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

// ─────────────────────────────────────────────
// getHead : returns the head pointer
// ─────────────────────────────────────────────
template <class T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

// ─────────────────────────────────────────────
// size : counts and returns total nodes
// ─────────────────────────────────────────────
template <class T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T>* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// ─────────────────────────────────────────────
// display : prints all node values
// e.g.  10 -> 20 -> 30 -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::display() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// ─────────────────────────────────────────────
// insertFront : creates new node and places it
//               before the current head
//
//   NEW -> [old head] -> ... -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertFront(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;   // point new node to old head
    head = newNode;         // update head to new node
}

// ─────────────────────────────────────────────
// insertEnd : walks to the last node and links
//             the new node after it
//
//   head -> ... -> [old last] -> NEW -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertEnd(T val) {
    Node<T>* newNode = new Node<T>(val);

    if (isEmpty()) {            // empty list: new node becomes head
        head = newNode;
        return;
    }

    Node<T>* curr = head;
    while (curr->next != nullptr)   // walk to last node
        curr = curr->next;

    curr->next = newNode;           // link new node at the end
}

// ─────────────────────────────────────────────
// insertBefore : inserts a new node BEFORE the
//                node at position node_no
//                (1-based index)
//
//   Example  node_no = 3:
//   head -> 1 -> 2 -> NEW -> [old 3] -> 4 -> NULL
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::insertBefore(T val, int node_no) {
    if (node_no < 1 || node_no > size() + 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (node_no == 1) {         // inserting before head is just insertFront
        insertFront(val);
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    Node<T>* curr = head;

    // walk to the node just BEFORE the target position
    for (int i = 1; i < node_no - 1; i++)
        curr = curr->next;

    newNode->next = curr->next; // new node points to the target node
    curr->next = newNode;       // previous node points to new node
}

// ─────────────────────────────────────────────
// removeFront : unlinks and deletes the head
//               node, advancing head forward
//
//   [head] -> 2 -> 3 -> NULL
//    DELETE      new head = 2
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::removeFront() {
    if (isEmpty()) {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    Node<T>* temp = head;   // save current head
    head = head->next;      // move head forward
    delete temp;            // free old head
}

// ─────────────────────────────────────────────
// removeAny : removes the node at position
//             node_no (1-based index)
//
//   Example  node_no = 3:
//   head -> 1 -> 2 -> [DELETE] -> 4 -> NULL
//                 ^               ^
//                 prev->next  =  curr->next
// ─────────────────────────────────────────────
template <class T>
void LinkedList<T>::removeAny(int node_no) {
    if (isEmpty()) {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    if (node_no < 1 || node_no > size()) {
        cout << "Invalid position." << endl;
        return;
    }

    if (node_no == 1) {     // removing head is just removeFront
        removeFront();
        return;
    }

    Node<T>* prev = head;

    // walk prev to the node just BEFORE the target
    for (int i = 1; i < node_no - 1; i++)
        prev = prev->next;

    Node<T>* target = prev->next;   // node to delete
    prev->next = target->next;      // bypass the target
    delete target;                  // free memory
}

// ─────────────────────────────────────────────
// search : traverses the list looking for val
//          returns true if found, false if not
// ─────────────────────────────────────────────
template <class T>
bool LinkedList<T>::search(T val) {
    Node<T>* curr = head;
    while (curr != nullptr) {
        if (curr->data == val)
            return true;
        curr = curr->next;
    }
    return false;
}

// ─────────────────────────────────────────────
// main : quick test of all functions
// ─────────────────────────────────────────────
/*int main() {
    LinkedList<int> list;

    // insertEnd
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    cout << "After insertEnd (10,20,30,40)  : "; list.display();

    // insertFront
    list.insertFront(5);
    cout << "After insertFront (5)          : "; list.display();

    // insertBefore position 3
    list.insertBefore(15, 3);
    cout << "After insertBefore (15, pos 3) : "; list.display();

    // removeFront
    list.removeFront();
    cout << "After removeFront              : "; list.display();

    // removeAny position 3
    list.removeAny(3);
    cout << "After removeAny (pos 3)        : "; list.display();

    // search
    cout << "Search 20 : " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 99 : " << (list.search(99) ? "Found" : "Not Found") << endl;

    // size
    cout << "Size : " << list.size() << endl;

    return 0;
}*/