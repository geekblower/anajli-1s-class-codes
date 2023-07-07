// write a program to demonastrate doubly linked list.
#include <iostream>
using namespace std;

class Node
{
   public :
          int data;
          Node* prev;
          Node* next;

          // constructor
          Node(int d)
          {
               this -> data = d;
               this -> prev = NULL;
               this -> next = NULL;
          }

};

// insert at head
void InsertAtHead(Node* head,int d)
{
     Node* temp = new Node(d);
     temp -> next = head;
     head -> prev = temp;
     head = temp;
}

// traverse the doubly linked list
void print(Node* head)
{
     Node* temp = head;
     while(temp != NULL)
     {
          cout<<temp -> data<<" ";
          temp = temp -> next;
     }
}

// insert at end
void InsertAtTail(Node* tail,int d)
{
      Node* temp = new Node(d);
      tail -> next = temp;
      temp -> prev = tail;
      tail = temp;
}

// insert At a position
void InsertAtPosition(Node* head,Node* tail,int d,int position)
{
     // insert at first position
     if(position == 1)
     {
          InsertAtHead(head,d);
          return;
     }
     Node* temp = head;
     int cnt = 1;
     while(cnt < position - 1)
     {
          temp = temp -> next;
          cnt++;
     }

     // insert at last position
     if(temp -> next == NULL)
     {
          InsertAtTail(tail,d);
          return;
     }

     // insert at a given position
     Node* nodeToInsert = new Node(d);
     nodeToInsert -> next = temp -> next;
     temp -> next = nodeToInsert;
}

int main()
{
     Node* node1 = new Node(10);
     cout<<node1 -> data<<" ";
     cout<<node1 -> prev<<" ";
     cout<<node1 -> next<<" ";
     
     Node* head = node1;
     InsertAtHead(head,14);
     print(head);
     
     
     Node* tail = node1;
     InsertAtTail(tail,15);
     print(tail);

     InsertAtPosition(head,tail,23,2);
     print(head);
     return 0;
}