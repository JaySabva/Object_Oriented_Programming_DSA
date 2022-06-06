#include<iostream>
using namespace std;
class doublylinkedlist
{
    class node
    {
        public:
        int data;
        node *next;
        node *prev;
        node(int d)
        {
            data=d;
            next=NULL;
            prev=NULL;
        }
    };
    node *head;
    public:
    doublylinkedlist()
    {
        head=NULL;
    }
    void insertatfront(int d)
    {
        node *temp=new node(d);
        temp->next=head;
        if(head!=NULL)
        {
            head->prev=temp;
        }
        head=temp;
    }
    void insertatend(int d)
    {
        node *temp=new node(d);
        if(head==NULL)
        {
            head=temp;
            return;
        }
        node *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
    void insertafter(int d,int x)
    {
        node *temp=new node(d);
        node *temp1=head;
        while(temp1!=NULL)
        {
            if(temp1->data==x)
            {
                temp->next=temp1->next;
                temp1->next=temp;
                temp->prev=temp1;
                if(temp->next!=NULL)
                {
                    temp->next->prev=temp;
                }
                return;
            }
            temp1=temp1->next;
        }
    }
    void insertbefore(int d,int x)
    {
        node *temp=new node(d);
        node *temp1=head;
        while(temp1!=NULL)
        {
            if(temp1->data==x)
            {
                temp->next=temp1;
                temp->prev=temp1->prev;
                temp1->prev=temp;
                if(temp->prev!=NULL)
                {
                    temp->prev->next=temp;
                }
                else
                {
                    head=temp;
                }
                return;
            }
            temp1=temp1->next;
        }
    }

    void deleteelement(int d)
    {
        if(head==NULL)
        {
            return;
        }
        node *temp=head;
        while(temp->data!=d)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                cout<<"Not found"<<endl;
                return;
            }
        }
        if(temp==head)
        {
            head=temp->next;
            head->prev=NULL;
            return;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
            return;
        }
    
    }
    void traverseforward()
    {
        node *temp=head;
        cout<<"head->";
        while(temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void traversebackward()
    {
        node *temp=head;
        cout<<"NULL<=>";
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->prev;
        }
        cout<<"head";
    }
};
int main()
{
    doublylinkedlist dl;
    int choice=0;
    while(choice!=8)
    {
        cout<<"------------------------------------"<<endl;
        cout<<"1.Insert at front\n2.Insert at end\n3.Insert after\n4.Insert before\n5.Delete element\n6.Traverse forward\n7.Traverse backward\n8.Exit\n";
        cin>>choice;
        cout<<"------------------------------------"<<endl;
        switch(choice)
        {
            case 1:
            {
                int d;
                cout<<"Enter the data to be inserted at front\n";
                cin>>d;
                dl.insertatfront(d);
                break;
            }
            case 2:
            {
                int d;
                cout<<"Enter the data to be inserted at end\n";
                cin>>d;
                dl.insertatend(d);
                break;
            }
            case 3:
            {
                int d,x;
                cout<<"Enter the data to be inserted after\n";
                cin>>d;
                cout<<"Enter the element after which data is to be inserted\n";
                cin>>x;
                dl.insertafter(d,x);
                break;
            }
            case 4:
            {
                int d,x;
                cout<<"Enter the data to be inserted before\n";
                cin>>d;
                cout<<"Enter the element before which data is to be inserted\n";
                cin>>x;
                dl.insertbefore(d,x);
                break;
            }
            case 5:
            {
                int d;
                cout<<"Enter the data to be deleted\n";
                cin>>d;
                dl.deleteelement(d);
                break;
            }
            case 6:
            {
                dl.traverseforward();
                cout<<endl;
                break;
            }
            case 7:
            {
                dl.traversebackward();
                cout<<endl;
                break;
            }
            case 8:
            {
                break;
            }
            default:
            {
                cout<<"Invalid choice\n";
            }
        }
    }
    return 0;
}
