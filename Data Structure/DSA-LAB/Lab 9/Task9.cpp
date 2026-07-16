#include<iostream>
#include "linkedlist.h"
using namespace std;
void LinkedList::delete_list(Node *head)
{
    if(head == nullptr)
    {
        this->head = nullptr;
        return;
    }

    delete_list(head->next);

    delete head;
}
int main()
{
   LinkedList l1;
   l1.insert(10);
   l1.insert(11);
   l1.insert(12);
   l1.insert(14);
   l1.insert(20);
   l1.insert(21);
   l1.insert(22);
   cout<<"List before deletion: ";
   l1.display();
   l1.delete_list(l1.gethead());
   cout<<endl<<endl<<"List after deletion: ";
   l1.display();
   return 0;
}