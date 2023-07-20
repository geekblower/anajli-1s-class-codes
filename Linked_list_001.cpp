// write a program to demonstrate the concept of linked list.
#include <iostream>
using namespace std;

class Node
{
     public:
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
               this -> next = NULL;
          }
          cout<<"Memory is free !"<<endl;
         }
};


int main()
{
      Node* node1 = new Node(10);
      cout<<"The value of the first node is :"<<node1 -> data<<endl;
      cout<<"The value of the next node is :"<<node1 -> next<<endl;

      return 0;
}