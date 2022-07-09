#include<iostream>
using namespace std;
class node;
class AVLT;

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
        quenode* front;
        quenode* rear;
        queue(){
            front = NULL;
            rear = NULL;
        }
        void push(node* data){
            quenode* new_node = new quenode(data);
            if(front == NULL){
                front = new_node;
                rear = new_node;
            }
            else{
                rear->next = new_node;
                rear = new_node;
            }
        }
        node* pop(){
            if(front == NULL)
                return NULL;
            quenode* temp = front;
            front = front->next;
            return temp->data;
        }
};

class node{
    public:
        int data;
        node* left;
        node* right;
        int height;
        node(int key){
            height = 0;
            data = key;
            left = NULL;
            right = NULL;
        }
        node(){
            height = 0;
            left = NULL;
            right = NULL;
        }
};

class AVLT{
    public:
        node* root;
        AVLT(){
            cout<<"Enter root node: ";
            int key;
            cin >> key;
            root = new node(key);
        }  
        void insert(node* root,int key);
        int delete_node(node* curr,int key);
        void BalanceTree(node* curr);
        void height(node* curr);
};

void inorder(node* curr){
    if(curr == NULL)
        return;
    inorder(curr->left);
    cout<<curr->data<<" ";
    inorder(curr->right);
}

void preorder(node* curr){
    if(curr == NULL)
        return;
    cout<<curr->data<<" ";
    preorder(curr->left);
    preorder(curr->right);
}

void postorder(node* curr){
    if(curr == NULL)
        return;
    postorder(curr->left);
    postorder(curr->right);
    cout<<curr->data<<" ";
}

void levelorder(node* curr){
    queue q;
    if(curr==NULL){
        cout<<"Empty\n";
        return;
    }
        
    q.push(curr);
    while(q.front!=NULL){
        node* temp = q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}	
	
void AVLT::insert(node* curr,int key){
        
        if (curr->data < key)
        {
            if(curr->right==NULL)
                curr->right=new node(key);
            else
                insert(curr->right,key);
        }
        else{
            if(curr->left==NULL)
                curr->left=new node(key);
            else
                insert(curr->left,key);
        }
}

void swap(node* curr){
    if(curr->left!=NULL){
        if(curr->left->data==-1){
            node* temp=curr->left;
            delete(temp);
            curr->left=NULL;
        }
        else
            swap(curr->left);
    }
    if(curr->right!=NULL){
        if(curr->right->data==-1){
            node* temp=curr->right;
            delete(temp);
            curr->right=NULL;
        }
        else
            swap(curr->right);
    }
}

int AVLT::delete_node(node* curr,int key){
    if(curr==NULL)
        return 1;
    else if(curr->data>key){
        return delete_node(curr->left,key);
    }
    else if(curr->data<key){
        return delete_node(curr->right,key);
    }
    else{
        if(curr->left==NULL){
            if(curr->right==NULL){
                curr->data=-1;
                swap(root);
            }
            else{
                node* temp = curr->right;
                curr->data = temp->data;
                curr->right = temp->right;
                curr->left = temp->left;
                delete temp;
            }
        }
        else if(curr->right==NULL){
            node* temp = curr->left;
            curr->data = temp->data;
            curr->right = temp->right;
            curr->left = temp->left;
            delete temp;
        }
        else{
            if(curr->right->left==NULL){
                node* temp = curr->right;
                curr->data = temp->data;
                curr->right = temp->right;
                delete temp;
            }
            else{
            for(node* temp = curr->right;temp->left!=NULL;temp=temp->left)
            {
                if(temp->left->left==NULL){
                    node *erase = temp->left;
                    curr->data = temp->left->data;
                    temp->left = NULL;
                    delete erase;
                    
                    break;
                }
            }
            }
        }
        return 0;
    }
}

void AVLT::height(node* curr){
    if(curr->left==NULL&&curr->right==NULL)
    {
        curr->height=0;
        return;
    }
    if(curr->left==NULL){
        curr->height = 1+curr->right->height;
        return;
    }
    else
        height(curr->left);

    if(curr->right==NULL){
        curr->height = 1+curr->left->height;
        return;
    }
    else
        height(curr->right);

    curr->height = max(curr->left->height,curr->right->height)+1;
}

void LeftRotation(node* curr){
    cout<<"\nleft rotate at "<<curr->data<<endl;
    node *b = curr;
    node* a = curr->right;

    //data exchange
    int temp=a->data;
    a->data=b->data;
    b->data=temp;

    //childern exchange
    b->right = a->right;
    a->right = a->left;
    a->left = b->left;
    b->left = a;
}

void RightRotation(node* curr){
    cout<<"\nright rotate at "<<curr->data<<endl;
    node* a=curr;
    node* b=curr->left;

    //data exchange
    int temp=a->data;
    a->data=b->data;
    b->data=temp;

    //childern exchange
    a->left = b->left;
    b->left= b->right;
    b->right = a->right;
    a->right = b;
}

void AVLT::BalanceTree(node* curr){
    if(curr==NULL)
        return;
    BalanceTree(curr->left);
    BalanceTree(curr->right);
    height(curr);
    int lh = curr->left==NULL?-1:curr->left->height;
    int rh = curr->right==NULL?-1:curr->right->height;
    if(abs(lh-rh)>1){
        cout<<"\nRebalanced at "<<curr->data<<endl;
        if(lh>rh){
            int llh=curr->left->left==NULL?-1:curr->left->left->height;
            int lrh=curr->left->right==NULL?-1:curr->left->right->height;
            if(llh>lrh){
                RightRotation(curr);
            }
            else{
                LeftRotation(curr->left);
                RightRotation(curr);
            }
        }
        else{
            int rlh=curr->right->left==NULL?0:curr->right->left->height;
            int rrh=curr->right->right==NULL?0:curr->right->right->height;
            if(rlh>=rrh){
                LeftRotation(curr);
            }
            else{
                RightRotation(curr->right);
                LeftRotation(curr);
            }
        }
    }
}

int main(){
        AVLT at;
        int choice=0;
        while(choice!=7){
            cout<<"\n";
            int choice;
            cout << "-------------------------------------" << endl;
             cout << "1.Insertion" << endl;
             cout << "2.Deletion" << endl;
            cout<<"3.Preorder\n";
            cout<<"4.Inorder\n";
            cout<<"5.Postorder\n";
            cout<<"6.Levelorder\n";
            cout<<"7.Exit\n";
            cout<<"Enter Your choice"<<endl;
            cout << "-------------------------------------" << endl;
            cin>>choice;
            switch(choice){
                case 1: { 
                    int key;
                    cout<<"Enter the data";
                    cin>>key;
                    at.insert(at.root,key);
                    break;
                }
                case 2: {
                    int key;
                    cout<<"Enter the data to be deleted\n";
                    cin>>key;
                    if(at.delete_node(at.root,key)==1)
                            cout<<"Key not found\n";
                    else if(at.root->data==-1){
                        cout<<"root: ";
                        cin>>key;
                        at.root=new node(key);
                    }
                    break;
                }
                case 3:
                    cout<<"Preorder Traversal: \n";
                    preorder(at.root);
                    break;
                case 4:
                    cout<<"Inorder Traversal: \n";
                    inorder(at.root);
                    break;
                case 5:
                    cout<<"Postorder Traversal: \n";
                    postorder(at.root);
                    break;
                case 6:
                    cout<<"Levelorder Traversal: \n";
                    levelorder(at.root);
                    break;
                default:
                    return 0;
            }
            at.height(at.root);
            at.BalanceTree(at.root);
        }
        return 0;
    }
