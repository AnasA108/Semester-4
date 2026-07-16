#include<iostream>
#include "linkedlist.h"
using namespace std;
bool search_list(Node *head,int v)
{
    if(head->data==v)
    return true;
    else if(head->next==nullptr)
    return false;
    else
    {
        Node *curr=head->next;
        return search_list(curr,v);
    }
    return false;
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
   cout<<"List: "<<endl;
   l1.display();
   cout<<endl<<"Searching for 14:\t";
   if(search_list(l1.gethead(),14))
   cout<<"Found in list";
   else
   cout<<"Not found!";
   cout<<endl<<"Searching for 17:\t";
   if(search_list(l1.gethead(),17))
   cout<<"Found in list";
   else
   cout<<"Not found!";
   cout<<endl<<"Searching for 20:\t";
   if(search_list(l1.gethead(),20))
   cout<<"Found in list";
   else
   cout<<"Not found!";
   return 0;
}