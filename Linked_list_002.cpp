// write a program to demonastrate SLL.
#include <iostream>
using namespace std;
 class Node
 {
     public :
          int data;
          Node* next;

          // constructor
          Node(int d)
          {
               this -> data = d;
               this -> next = NULL;
          }

          // destructor
          ~Node()
          {
               int value = this -> data;
               if(this -> next != NULL)
               {
                    delete next;
                    this -> next = next;
               }
          }
 };

 // insert at head
 void InsertAtHead ( Node* &head , int d ) {
    Node* temp = new Node(d);
    temp -> next = head ;
    head -> next = NULL ;
     head = temp  ;
}

// print the linked list
 void print ( Node* head) 
 {

    if (head == NULL) {
        cout << "list is empty!"<< endl;
        return;
    }
    Node* temp = head ;
    while ( temp != NULL ) {
        cout << temp -> data <<" ";
        temp = temp -> next ;
    }
     cout<<endl;
}

// insert at last
void InsertAtLast(Node* tail,int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// insert at a posotion
void InsertAtPosition(Node* head,Node* tail,int position,int d)
{
    // if first position
    if(position == 1)
    {
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position -1)
    {
       temp = temp -> next;
       cnt++;
    }

    //  insert at last
    if(temp -> next == NULL)
    {
        InsertAtLast(tail,d);
        return;
    }

    // insert at a middle position
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


// delete a node from the linked list
void deletion(int position,Node* head)
{
   // delete first node or starting node
   if(position == 1)
   {
    Node* temp = head;
    head = head -> next;

    // memory free from the first node
    temp -> next = NULL;
    delete temp;
   }
   else 
   {
   // delete last or middle node
   Node* curr = head;
   Node* prev = NULL;
   int cnt = 1;
   while(cnt < position)
   {
    prev = curr;
    curr = curr -> next;
    cnt++;
   }
   prev -> next = curr -> next;
   curr -> next = NULL ;
   delete curr ;
   }
}

int main()
 {
     Node* node1 = new Node(12);
     cout<<node1 -> data<<" ";
     cout<<node1 -> next<<endl;
     Node* head = node1;
     print(head);

     InsertAtHead(head,13);
     print(head);

     Node* tail = node1;
     print(tail);
     InsertAtLast(tail,16);
     print(tail);

     InsertAtPosition(head,tail,2,18);
     print(head);

     InsertAtPosition(head,tail,4,27);
     print(head);

     deletion(2,head);
     print(head);
     return 0;
 }