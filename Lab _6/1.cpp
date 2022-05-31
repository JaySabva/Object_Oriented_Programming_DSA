#include<iostream>
using namespace std;
class linkedlist
{
    class node
    {
        public:
        int data;
        node *next;
        node(int d)
        {
            data=d;
            next=NULL;
        }
    };
    node *head;
    public:
    linkedlist()
    {
        head=NULL;
    }
    void insertatfront(int d)
    {
        node *temp=new node(d);
        temp->next=head;
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
    }
    void insertatpos(int d,int pos)
    {
        node *temp=new node(d);
        if(head==NULL)
        {
            head=temp;
            return;
        }
        node *temp1=head;
        int i=1;
        while(i<pos-1)
        {
            temp1=temp1->next;
            i++;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    void deleteelement(int d)
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node *temp1=head;
        if(temp1->data==d)
        {
            head=temp1->next;
            delete temp1;
            return;
        }
        while(temp1->next!=NULL)
        {
            if(temp1->next->data==d)
            {
                node *temp=temp1->next;
                temp1->next=temp->next;
                delete temp;
                return;
            }
            temp1=temp1->next;
        }
        cout<<"Element not found"<<endl;
    }
    void traverse()
    {
        node *temp=head;
        cout<<"List is: "<<endl;
        cout<<"Head->";
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void reverse()
    {
        node *prev=NULL;
        node *curr=head;
        node *next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
};
int main()
{
    linkedlist l;
    int choice=0;
    while(choice!=7)
    {   cout<<"-------------------------------------"<<endl;
        cout<<"1.insert at front"<<endl;
        cout<<"2.insert at end"<<endl;
        cout<<"3.insert at pos"<<endl;
        cout<<"4.delete element"<<endl;
        cout<<"5.display"<<endl;
        cout<<"6.reverse"<<endl;
        cout<<"7.exit"<<endl;
        cin>>choice;
        cout<<"-------------------------------------"<<endl;
        switch(choice)
        {
            case 1:
            {
                int d;
                cout<<"enter data"<<endl;
                cin>>d;
                l.insertatfront(d);
                break;
            }
            case 2:
            {
                int d;
                cout<<"enter data"<<endl;
                cin>>d;
                l.insertatend(d);
                break;
            }
            case 3:
            {
                int d,pos;
                cout<<"enter data"<<endl;
                cin>>d;
                cout<<"enter pos"<<endl;
                cin>>pos;
                l.insertatpos(d,pos);
                break;
            }
            case 4:
            {
                int d;
                cout<<"enter data"<<endl;
                cin>>d;
                l.deleteelement(d);
                break;
            }
            case 5:
            {
                l.traverse();
                break;
            }
            case 6:
            {
                l.reverse();
                break;
            }
            case 7:
            {
                break;
            }
            default:
            {
                cout<<"invalid choice"<<endl;
            }
        }
    }

    return 0;
}
