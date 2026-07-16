#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at end
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display list
    void display()
    {
        Node* temp = head;
     if(temp==nullptr)
     {
     cout<<"list is empty";
     return ;
     }
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Search value
    bool search(int value)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data == value)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // Delete node
    void remove(int value)
    {
        if(head == NULL)
            return;

        // delete first node
        if(head->data == value)
        {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL && temp->next->data != value)
        {
            temp = temp->next;
        }

        if(temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = temp->next->next;

        delete del;
    }
    Node *gethead()
    {
        return head;
    }
    void delete_list(Node *head);

};
