////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       @ Author- Sabva Jay Dilipbhai                                                //
//                                       $ ID-202101224                                                               //
//                                       % Implementation of red black tree                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
class node;
class Red_Black_Tree;

class quenode{
    public:
        node* data;
        quenode* next;
        quenode(node* data){
            this->data = data;
            next = NULL;
        }
};

class queue{
    public:
        quenode* head;
        quenode* tail;
        queue(){
            head = NULL;
            tail = NULL;
        }
        void push(node* data){
            quenode* new_node = new quenode(data);
            if(head == NULL){
                head = new_node;
                tail = new_node;
            }
            else{
                tail->next = new_node;
                tail = new_node;
            }
        }
        node* pop(){
            if(head == NULL)
                return NULL;
            quenode* temp = head;
            head = head->next;
            return temp->data;
        }
};

class node{
    public:
        int data;
        node* left;
        node* right;
        char color;
        node(int key){
            color='R';
            data = key;
            left = NULL;
            right = NULL;
        }
        node(){
            color='R';
            left = NULL;
            right = NULL;
        }
};

class Red_Black_Tree{
    public:
        node* root;
        Red_Black_Tree(){
            cout<<"Enter Root Data: ";
            int key;
            cin >> key;
            root = new node(key);
            root->color='B';
        }  
        void insert(node* root,int key);
        void balance_tree(node* curr);
        void checkroot(node *curr);
        void node_split(node* curr);
        node* find_parent(node* curr,node* child);
};

void inorder(node* curr){
    if(curr == NULL)
        return;
    inorder(curr->left);
    cout<<curr->data<<curr->color<<" ";
    inorder(curr->right);
}

void preorder(node* curr){
    if(curr == NULL)
        return;
    cout<<curr->data<<curr->color<<" ";
    preorder(curr->left);
    preorder(curr->right);
}

void postorder(node* curr){
    if(curr == NULL)
        return;
    postorder(curr->left);
    postorder(curr->right);
    cout<<curr->data<<curr->color<<" ";
}

void levelorder(node* curr){
    queue q;
    if(curr==NULL){
        cout<<"Tree is Empty\n";
        return;
    }
        
    q.push(curr);
    while(q.head!=NULL){
        node* temp = q.pop();
        cout<<temp->data<<temp->color<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}	

node* Red_Black_Tree::find_parent(node* curr,node* child){
    if(curr == NULL)
        return NULL;
    if(curr->data<child->data){
        if(curr->right==NULL)
            return NULL;
        else if(curr->right == child)
            return curr;
        else
            return find_parent(curr->right,child);
    }
    else{
        if(curr->left==NULL)
            return NULL;
        else if(curr->left == child)
            return curr;
        else
            return find_parent(curr->left,child);
    }
}

void Red_Black_Tree::node_split(node* curr){
    cout<<"Node Split At "<<curr->data<<" "<<curr->left->data<<" "<<curr->right->data<<"\n";
    cout << "Color Flip From Red To Black At " << curr->left->data << "\n";
    curr->left->color='B';
    checkroot(curr);
}

void Red_Black_Tree::checkroot(node* curr){
    node* parent=find_parent(root,curr);
    //root node case
    if(parent==NULL)
        return;
    //3-node parent case
    if(parent->left->color=='R')
        node_split(parent);
    else
        parent->left->color='R';
}

void Red_Black_Tree::insert(node* curr,int key){
        
        if(curr->data < key)
        {
            if(curr->right==NULL){
                curr->right=new node(key);
                curr->right->color='B';
                if(curr->left!=NULL){
                    node_split(curr);
                }
                else{
                    cout<<"2-node at "<<curr->data<<" to 3-node with "<<curr->right->data<<"\n";
                    curr->left=new node(curr->data);
                    curr->data = curr->right->data;
                    node* temp=curr->right;
                    curr->right = NULL;
                    delete temp;
                }
            }
            else
                insert(curr->right,key);
        }
        else{
            if(curr->left==NULL){
                
                curr->left=new node(key);
                cout<<"2-node at "<<curr->data<<" to 3-node with "<<curr->left->data<<"\n";
                curr->left->color = 'R';
                if(curr->color=='R'){
                    
                    node *parent = find_parent(root,curr);
                    //root cannot be red
                    cout<<"Rotation at "<<parent->data<<endl;
                    int p_data = parent->data;
                    parent->data = curr->data;
                    parent->left = curr->left;
                    insert(root, p_data);
                }
            }
            else
                insert(curr->left,key);
        }
}

int main(){
        Red_Black_Tree rbt;
        int choice=0;
        while(choice!=6){
            cout<<"\n";
            levelorder(rbt.root);
            cout<<"\n";
            cout<<"\nchoose option: \n";
            cout<<"1.Insertion\n";
            cout<<"2.Levelorder Traversal\n";
            cout<<"3.Preorder Traversal\n";
            cout<<"4.Inorder Traversal\n";
            cout<<"5.Postorder Traversal\n";
            cout<<"6.Exit\n";
            cin>>choice;
            switch(choice){
                case 1: { 
                    int key;
                    cout<<"Enter The Data:";
                    cin>>key;
                    rbt.insert(rbt.root,key);
                    break;
                }
                case 2: 
                    cout<<"Levelorder Traversal: ";
                    levelorder(rbt.root);
                    break;
                case 3:
                    cout<<"Preorder Traversal: ";
                    preorder(rbt.root);
                    break;
                case 4:
                    cout<<"Inorder Traversal: ";
                    inorder(rbt.root);
                    break;
                case 5:
                    cout<<"Postorder Traversal: ";
                    postorder(rbt.root);
                    break;
                default:
                    return 0;
            }
        }
        return 0;
    }