#include<iostream>
using namespace std;
class account
{
    protected:
    string name;
    long long int accno;
    float balance;
    public:
    void create_account()
    {
        cout<<"Enter the name of the account holder: ";
        cin>>name;
        cout<<"Enter the account number: ";
        cin>>accno;
        cout<<"Enter the initial balance of the account: ";
        cin>>balance;
    }
    void show_account()
    {
        cout<<"Account holder name: "<<name<<endl;
        cout<<"Account number: "<<accno<<endl;
        cout<<"Balance amount: "<<balance<<endl;
    }
    void modify()
    {
        cout<<"Modify Account holder name: ";
        cin>>name;
        cout<<"Modify Account number: ";
        cin>>accno;
        cout<<"Modify balance amount: ";
        cin>>balance;
    }
};
class saving_account:public account
{
    public:
    void create_account()
    {
        account::create_account();
        cout<<"Enter the interest rate: ";
        cin>>rate;
    }
    void cheque_book()
    {
       cout<<"Sorry! Cheque book cannot be issued for saving account."<<endl;
    }
    void interest()
    {
        float interest;
        float rate;
        int year;
        cout<<"Enter the number of years: ";
        cin>>year;
        cout<<"Enter the interest rate: ";
        cin>>rate;
        interest=balance*rate*year;
        interest=rate*balance*year/100;
        cout<<"Interest earned in "<<year<<" years: "<<interest<<endl;
        while(year>0)
        {
            balance=balance+interest;
            year--;
        }
        cout<<"Final balance: "<<balance<<endl;
    }
    void withdraw()
    {
        float amount;
        cout<<"Enter the amount to be withdrawn: ";
        cin>>amount;
        if(amount>balance)
        {
            cout<<"Insufficient balance"<<endl;
        }
        else
        {
            balance=balance-amount;
            cout<<amount<<" is withdrawn from your account. Remaining balance is "<<balance<<endl;
        }
    }
    void show_account()
    {
        account::show_account();
        cout<<"Interest rate: "<<rate<<endl;
    }
    void deposit()
    {
        float amount;
        cout<<"Enter the amount to be deposited: ";
        cin>>amount;
        balance=balance+amount;
        cout<<"Remaining balance: "<<balance<<endl;
    }
    void modify()
    {
        account::modify();
        cout<<"Modify interest rate: ";
        cin>>rate;
    }
    private:
    float rate;
};
class current_account:public account
{
    public:
    float amount;
    void create_account()
    {
        account::create_account();
        cout<<"Enter the overdraft limit: ";
        cin>>limit;
    }
    void deposit()
    {
        cout<<"Enter the amount to be deposited: ";
        cin>>amount;
        balance=balance+amount;
        cout<<"Remaining balance: "<<balance<<endl;
    }
    void cheque_book()
    {   
        int cheque_no;
        cout<<"Enter the number of cheques: ";
        cin>>cheque_no;
        cout<<"Enter the amount of each cheque: ";
        cin>>amount;
        balance=balance-cheque_no*amount;
        cout<<"Remaining balance: "<<balance<<endl;
    }
    void interest()
    {
        cout<<"Sorry! Interest cannot be applied to current account."<<endl;
    }
    void withdraw()
    {
       
        cout<<"Enter the amount to be withdrawn: ";
        cin>>amount;
        if(amount<=balance-500)
        {
            balance-=amount;
        }
        else if(amount>=balance-500 && amount<=balance-100)
        {
           
            int choice;
            cout<<"Do you want to withdraw(18*Charge will be applied on amount):1.Yes 2.No: ";
            cin>>choice;
            if(choice==1)
            {
                balance=balance-amount-amount*18/100;
                if(balance<0)
                {
                    cout<<"Insufficient balance"<<endl;
                }
                else
                {
                    cout<<amount<<" withdrawn successfully. Remaining balance: "<<balance<<endl;
                }
            }
            else
            {
                cout<<"No charges is applied."<<endl;
            }
        }
        else
        {
            cout<<"Insufficient balance"<<endl;
        }
        cout<<"Remaining balance: "<<balance<<endl;
    }
    void show_account()
    {
        account::show_account();
        cout<<"Overdraft limit: "<<limit<<endl;
    }
    void modify()
    {
        account::modify();
        cout<<"Modify overdraft limit: ";
        cin>>limit;
    }
    private:
    float limit;
};
int main()
{
    int ch;
    saving_account s;
    current_account c;
    do
    {
        cout<<"\n1.Create Account\n";
        cout<<"2.Show Account\n";
        cout<<"3.Modify Account\n";
        cout<<"4.Deposit\n";
        cout<<"5.Withdraw\n";
        cout<<"6.Calculate Interest\n";
        cout<<"7.Cheque Book\n";
        cout<<"8.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.create_account();
                        break;
                    }
                    case 2:
                    {
                        c.create_account();
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.show_account();
                        break;
                    }
                    case 2:
                    {
                        c.show_account();
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.modify();
                        break;
                    }
                    case 2:
                    {
                        c.modify();
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.deposit();
                        break;
                    }
                    case 2:
                    {
                        c.deposit();
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.withdraw();
                        break;
                    }
                    case 2:
                    {
                        c.withdraw();
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.interest();
                        break;
                    }
                    case 2:
                    {
                        c.interest();
                        break;
                    }
                }
                break;
            }
            case 7:
            {
                cout<<"\n1.Savings Account\n";
                cout<<"2.Current Account\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        s.cheque_book();
                        break;
                    }
                    case 2:
                    {
                        c.cheque_book();
                        break;
                    }
                }
                break;
            }
        }
    }while(ch!=8);

    return 0;
}
