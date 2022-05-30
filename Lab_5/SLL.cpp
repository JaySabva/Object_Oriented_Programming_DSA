#include<iostream>

using namespace std;
//Author-SABVA JAY DILIPBHAI
//ID_202101224
//Date-25/05/2022
//Description-Singly Linked List
class node {
   public:
      int data;
   node * next;
};
void insertatfront(node * & head, int val) //node* &head is a reference to head
{
   node * temp = new node; //creating a new node
   temp -> data = val; //assigning the value to the node
   temp -> next = head; //assigning the address of head to the next of the new node
   head = temp; //assigning the address of the new node to head
}
void insertatlast(node * & head, int val) {
   node * temp = new node; //creating a new node
   temp -> data = val; //assigning the value to the node
   temp -> next = NULL; //assigning the address of NULL to the next of the new node
   if (head == NULL) {
      head = temp; //assigning the address of the new node to head
      return;
   }

   node * temp1 = head; //creating a new node
   while (temp1 -> next != NULL) {
      temp1 = temp1 -> next; //assigning the address of the next node to temp1
   }
   temp1 -> next = temp; //assigning the address of the new node to the next of the last node
}
void insertatpos(node * & head, int val, int pos) {
   node * temp = new node; //creating a new node
   temp -> data = val; //assingning the value to the node
   temp -> next = NULL; //assigning the address of NULL to the next of the new node
   if (head == NULL) {
      head = temp; //assigning the address of the new node to head
      return;
   }
   if (pos == 1) {
      temp -> next = head; //assigning the address of the new node to the next of the head
      head = temp; //assigning the address of the new node to head
      return;
   }
   node * temp1 = head; //creating a new node
   int i = 1;
   while (i < pos - 1) {
      temp1 = temp1 -> next;
      i++;
   }
   temp -> next = temp1 -> next; //assigning the address of the new node to the next of the node at the position
   temp1 -> next = temp; //assigning the address of the new node to the next of the node at the position

}
void deletion(node * & head, int val) {
   if (head == NULL) {
      cout << "List is empty" << endl;
      return;
   }
   if (head -> data == val) {
      node * temp = head; //creating a new node
      head = head -> next;
      delete temp; //deleting the node
      return;
   }
   node * temp1 = head; //creating a new node
   while (temp1 -> next != NULL) {
      if (temp1 -> next -> data == val) {
         node * temp = temp1 -> next; //creating a new node
         temp1 -> next = temp -> next; //assigning the address of the next of the node to the next of the node at the position
         delete temp;
         return;
      }
      temp1 = temp1 -> next; //assigning the address of the next node to temp1
   }
   cout << "Element not found" << endl;
}
void traverse(node * head) {
   if (head == NULL) {
      cout << "List is empty" << endl;
      return;
   }
   node * temp = head;
   while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next; //assigning the address of the next node to temp
   }
   cout << endl;
}
int main() {
   node * head = NULL;
   int choice = 0;
   while (choice != 6) {
      cout << "1.Insert at beginning" << endl;
      cout << "2.Insert at end" << endl;
      cout << "3.Insert at position" << endl;
      cout << "4.Delete an element" << endl;
      cout << "5.Traverse The Linkedlist" << endl;
      cout << "6.Exit" << endl;
      cin >> choice;
      switch (choice) {
      case 1: {
         int data;
         cout << "Enter the element" << endl;
         cin >> data;
         insertatfront(head, data);
         break;
      }
      case 2: {
         int data;
         cout << "Enter the element" << endl;
         cin >> data;
         insertatlast(head, data);
         break;
      }
      case 3: {
         int data, pos;
         cout << "Enter the element" << endl;
         cin >> data;
         cout << "Enter the position" << endl;
         cin >> pos;
         insertatpos(head, data, pos);
         break;
      }
      case 4: {
         int data;
         cout << "Enter the element" << endl;
         cin >> data;
         deletion(head, data);
         break;
      }
      case 5: {
         traverse(head);
         break;
      }
      case 6: {
         break;
      }
      default: {
         cout << "Invalid choice" << endl;
      }

      }
   }
   return 0;
}
