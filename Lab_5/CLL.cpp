#include<iostream>
 //Author-SABVA JAY DILIPBHAI
//
//CircularLinkLists
using namespace std;
class node {
   public:
      int data;
   node * next;
   node(int data) {
      this -> data = data;
      next = NULL;
   }
};
void display(node * head) {
   node * temp = head;
   do {
      cout << temp -> data << " ";
      temp = temp -> next;
   } while (temp != head);
}
void insertatfront(node * & head, int val) {
   node * n = new node(val);
   if (head == NULL) {
      n -> next = n;
      head = n;
      return;
   }
   node * temp = head;
   while (temp -> next != head) {
      temp = temp -> next;
   }
   temp -> next = n;
   n -> next = head;
   head = n;
}
void insertatend(node * & head, int data) {
   if (head == NULL) {
      insertatfront(head, data);
      return;
   }
   node * n = new node(data);
   node * temp = head;

   while (temp -> next != head) {
      temp = temp -> next;
   }
   temp -> next = n;
   n -> next = head;
}
void insertatpos(node * & head, int data, int pos) {
   if (pos == 0) {
      insertatfront(head, data);
      return;
   }
   node * n = new node(data);
   node * temp = head;
   int i = 0;
   while (i < pos - 1) {
      temp = temp -> next;
      i++;
   }
   n -> next = temp -> next;
   temp -> next = n;
}
void deleteathead(node * & head) {
   node * temp = head;
   while (temp -> next != head) {
      temp = temp -> next;
   }
   node * temp1 = head;
   temp -> next = head -> next;
   head = head -> next;
   delete temp1;

}
void deletion(node * & head, int pos) {
   if (pos == 1) {
      deleteathead(head);
      return;
   }
   node * temp = head;
   int count = 1;
   while (count != pos - 1) {
      temp = temp -> next;
      count++;
   }
   node * temp1 = temp -> next;
   temp -> next = temp1 -> next;
   delete temp1;

}
int main() {
   node * head = NULL;
   int choice;
   do {
      cout << "1.Insert at front" << endl;
      cout << "2.Insert at end" << endl;
      cout << "3.Insert at position" << endl;
      cout << "4.Delete at front" << endl;
      cout << "5.Delete at position" << endl;
      cout << "6.Display" << endl;
      cout << "7.Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
      case 1: {
         int val;
         cout << "Enter the value: ";
         cin >> val;
         insertatfront(head, val);
         break;
      }
      case 2: {
         int val;
         cout << "Enter the value: ";
         cin >> val;
         insertatend(head, val);
         break;
      }
      case 3: {
         int val, pos;
         cout << "Enter the value: ";
         cin >> val;
         cout << "Enter the position: ";
         cin >> pos;
         insertatpos(head, val, pos);
         break;
      }
      case 4: {
         deleteathead(head);
         break;
      }
      case 5: {
         int pos;
         cout << "Enter the position: ";
         cin >> pos;
         deletion(head, pos);
         break;
      }
      case 6: {
         display(head);
         break;
      }
      case 7: {
         break;
      }
      default: {
         cout << "Invalid choice" << endl;
      }
      }
   } while (choice != 7);
   return 0;
}
