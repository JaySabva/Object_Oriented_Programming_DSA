////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       @ Author- Sabva Jay Dilipbhai                                                //
//                                       $ ID-202101224                                                               //
//                                       % Implementation of binary search tree                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;
class node;
class bst;
class binarytree;
class queue {
   public:
      int front, rear;
   int size = 1000;
   node * arr[1000];
   queue() {
      front = -1;
      rear = -1;
   }
   void push(node * temp) {
      if (front == -1) {
         front = 0;
      }
      rear++;
      arr[rear] = temp;
   }
   void pop() {
      if (front == rear) {
         front = rear = -1;
         return;
      }
      front++;
   }
   int empty() {
      if (front == -1)
         return 1;
      else
         return 0;
   }
   node * front1() {
      return arr[front];
   }

};
class node {
   public:
      node * left;
   node * right;
   int data;
   node(int d) {
      left = NULL;
      right = NULL;
      data = d;
   }
};
class bst {

   public:
      node * root1;
   bst() {
      root1 = NULL;
   }
   node * insertion(node * root1, int data) {
      if (root1 == NULL) {
         node * temp = new node(data);
         return temp;
      }
      if (data < root1 -> data) {
         root1 -> left = insertion(root1 -> left, data);
      } else {
         root1 -> right = insertion(root1 -> right, data);
      }
      return root1;
   }
   node * minValue(node * root1) {
      if (root1 -> left == NULL) {
         return root1;
      } else {
         return minValue(root1 -> left);
      }
   }
   node * maxValue(node * root1) {
      if (root1 -> right == NULL) {
         return root1;
      } else {
         return maxValue(root1 -> right);
      }
   }
   node * deletion(node * root1, int data) {
      if (root1 == NULL) {
         return root1;
      }
      if (root1 -> data == data) {
         if (root1 -> left == NULL && root1 -> right == NULL) {
            delete root1;
            return NULL;

         }
         if (root1 -> left != NULL && root1 -> right == NULL) {
            node * temp = root1 -> left;
            delete root1;
            return temp;
         }
         if (root1 -> left == NULL && root1 -> right != NULL) {
            node * temp = root1 -> right;
            delete root1;
            return temp;
         }
         if (root1 -> left != NULL && root1 -> right != NULL) {
            node * temp = minValue(root1 -> right);
            root1 -> data = temp -> data;
            root1 -> right = deletion(root1 -> right, temp -> data);
            return root1;
         }

      } else if (root1 -> data > data) {
         root1 -> left = deletion(root1 -> left, data);
      } else {
         root1 -> right = deletion(root1 -> right, data);
      }
   }
   void search(node * root1, int data) {
      if (root1 == NULL) {
         cout << "Element is not present in the tree\n";
         return;
      }
      if (data == root1 -> data) {
         cout << "Element is present in the tree\n";
         return;
      }
      if (data < root1 -> data) {
         search(root1 -> left, data);
      } else {
         search(root1 -> right, data);
      }
   }
   void inorder(node * root1) {
      if (root1 == NULL) {
         return;
      }
      inorder(root1 -> left);
      cout << root1 -> data << " ";
      inorder(root1 -> right);
   }
   void preorder(node * root1) {
      if (root1 == NULL) {
         return;
      }
      cout << root1 -> data << " ";
      preorder(root1 -> left);
      preorder(root1 -> right);
   }
   void postorder(node * root1) {
      if (root1 == NULL) {
         return;
      }
      postorder(root1 -> left);
      postorder(root1 -> right);
      cout << root1 -> data << " ";
   }
   void levelorder(node * root1) {
      queue q;
      q.push(root1);
      while (!q.empty()) {
         node * temp = q.front1();
         q.pop();
         cout << temp -> data << " ";
         if (temp -> left != NULL) {
            q.push(temp -> left);
         }
         if (temp -> right != NULL) {
            q.push(temp -> right);
         }
      }
   }

};
class binarytree {
   public:
      node * root;
   binarytree() {
      root = NULL;
   }
   queue q;
   void levelorderinsertion(int d) {
      node * temp1 = new node(d);
      if (root == NULL) {
         root = temp1;
         return;
      }
      q.push(root);
      while (!q.empty()) {
         node * temp = q.front1();
         q.pop();
         if (temp -> left == NULL) {
            temp -> left = new node(d);
            return;
         } else {
            q.push(temp -> left);
         }

         if (temp -> right == NULL) {
            temp -> right = new node(d);
            return;
         } else {
            q.push(temp -> right);
         }
      }
   }
   void inorder(node * root) {
      if (root == NULL)
         return;
      inorder(root -> left);
      cout << root -> data << " ";
      inorder(root -> right);
   }
   void preorder(node * root) {
      if (root == NULL)
         return;
      cout << root -> data << " ";
      preorder(root -> left);
      preorder(root -> right);
   }
   void postorder(node * root) {
      if (root == NULL)
         return;
      postorder(root -> left);
      postorder(root -> right);
      cout << root -> data << " ";
   }
   void levelordertraversal(node * root) {
      if (root == NULL)
         return;
      queue q;
      q.push(root);
      while (!q.empty()) {
         node * temp = q.front1();
         q.pop();
         cout << temp -> data << " ";
         if (temp -> left != NULL) {
            q.push(temp -> left);
         }
         if (temp -> right != NULL) {
            q.push(temp -> right);
         }
      }
   }
   void deletDeepest(node * temp) {
      q.push(root);
      node * temp2;
      while (!q.empty()) {
         temp2 = q.front1();
         q.pop();
         if (temp2 == temp) {
            temp2 = NULL;
            delete temp;
            return;
         }
         if (temp2 -> right != NULL) {
            if (temp2 -> right == temp) {
               temp2 -> right = NULL;
               delete temp;
               return;
            } else {
               q.push(temp2 -> right);
            }
         }
         if (temp2 -> left != NULL) {
            if (temp2 -> left == temp) {
               temp2 -> left = NULL;
               delete temp;
               return;
            } else {
               q.push(temp2 -> left);
            }
         }
      }
   }

   void deletions(int data) {
      if (root == NULL) {
         cout << "Tree is empty" << endl;
         return;
      }
      queue q;
      q.push(root);
      node * temp;
      node * data_node = NULL;
      while (!q.empty()) {
         temp = q.front1();
         q.pop();
         if (temp -> data == data) {
            data_node = temp;
         }
         if (temp -> left != NULL) {
            q.push(temp -> left);
         }
         if (temp -> right != NULL) {
            q.push(temp -> right);
         }
      }
      if (data_node == NULL) {
         cout << "Data not found" << endl;
         return;
      }
      if (data_node == root && data_node -> left == NULL && data_node -> right == NULL) {
         root = NULL;
         delete data_node;
         return;
      }
      int x = temp -> data;
      deletDeepest(temp);
      data_node -> data = x;

   }
   bool isBST(node * root, node * min, node * max) {
      if (root == NULL) {
         return true;
      }
      if (min != NULL && root -> data <= min -> data) {
         return false;
      }
      if (max != NULL && root -> data >= max -> data) {
         return false;
      }
      bool leftvalid = isBST(root -> left, min, root);
      bool rightvalid = isBST(root -> right, root, max);
      return leftvalid && rightvalid;
   }
};
int main() {
   bst b;
   binarytree bt;
   int choice = 0;
   while (choice != 9) {
      cout << "----------------------------------------------------" << endl;
      cout << "1.Insert Into Binary Tree" << endl;
      cout << "2.Insert Into Binary Search Tree" << endl;
      cout << "3.Delete From Binary Tree" << endl;
      cout << "4.Delete From Binary Search Tree" << endl;
      cout << "5.Search In Binary Search Tree" << endl;
      cout << "6.Check If Binary Tree Is BST" << endl;
      cout << "7.Traverse In Binary Tree" << endl;
      cout << "8.Traverse In Binary Search Tree" << endl;
      cout << "9.Exit" << endl;
      cout << "----------------------------------------------------" << endl;
      cout << "Enter your choice:";
      cin >> choice;
      switch (choice) {
      case 1: {
         int data;
         cout << "Enter the data:";
         cin >> data;
         bt.levelorderinsertion(data);
         break;
      }
      case 2: {
         int data;
         cout << "Enter the data:";
         cin >> data;
         b.root1 = b.insertion(b.root1, data);
         break;
      }
      case 3: {
         if (bt.root == NULL) {
            cout << "Tree is empty" << endl;
            break;
         } else {
            int data;
            cout << "Enter the data:";
            cin >> data;
            bt.deletions(data);
         }
         break;
      }
      case 4: {
         if (b.root1 == NULL) {
            cout << "Tree is empty" << endl;
            break;
         } else {
            int data;
            cout << "Enter the data:";
            cin >> data;
            b.root1 = b.deletion(b.root1, data);
         }
         break;
      }
      case 5: {
         if (b.root1 == NULL) {
            cout << "Tree is empty" << endl;
            break;
         }
         int data;
         cout << "Enter the data:";
         cin >> data;
         b.search(b.root1, data);
         break;
      }
      case 6: {
         if (bt.root == NULL) {
            cout << "Tree is empty" << endl;
            break;
         } else if (bt.isBST(bt.root, NULL, NULL)) {
            cout << "Tree is Binary Search Tree" << endl;
         } else {
            cout << "Tree is not Binary Search Tree" << endl;
         }
         break;
      }
      case 7: {
         if (bt.root == NULL) {
            cout << "Tree is empty" << endl;

         } else {
            cout << "Inorder Traversal:" << endl;
            bt.inorder(bt.root);
            cout << endl;
            cout << "Preorder Traversal:" << endl;
            bt.preorder(bt.root);
            cout << endl;
            cout << "Postorder Traversal:" << endl;
            bt.postorder(bt.root);
            cout << endl;
            cout << "Levelorder Traversal:" << endl;
            bt.levelordertraversal(bt.root);
            cout << endl;
         }
         break;
      }
      case 8: {
         if (b.root1 == NULL) {
            cout << "Tree is empty" << endl;

         } else {
            cout << "Inorder Traversal:" << endl;
            b.inorder(b.root1);
            cout << endl;
            cout << "Preorder Traversal:" << endl;
            b.preorder(b.root1);
            cout << endl;
            cout << "Postorder Traversal:" << endl;
            b.postorder(b.root1);
            cout << endl;
            cout << "Levelorder Traversal:" << endl;
            b.levelorder(b.root1);
            cout << endl;
         }
         break;
      }
      case 9: {
         cout << "Exiting..." << endl;
         return 0;
      }
      default: {
         cout << "Invalid choice" << endl;
      }
      }
   }
   return 0;
}
