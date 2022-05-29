#include<iostream>
using namespace std;

class teacher;
class typist;
class officer;
class regular;
class casual;

class staff
{

    public:
    string name;
    string code_name;

};

class teacher : public staff
{
    public:
    string subject;
    string publication;

};

class typist : public staff
{
    public:
    float speed;
};

class officer : public staff
{
    public:
    string grade;
};

class regular : public typist
{
    public:
    long long int wages;
};

class casual : public typist
{
    public:
    long long int daily_wages;
};

teacher take_input_t(teacher t)
{
    cout<< "\n\nEnter Your Name : ";
    cin>>t.name;
    cout<< "\nEnter Your Code Name : ";
    cin>>t.code_name;
    cout<< "\nEnter Subject That You Teach : ";
    cin>>t.subject;
    cout<< "\nEnter The Name Of Your Publication : ";
    cin>>t.publication;
    cout<<"\n";

    return t;

}

officer take_input_o(officer o)
{
    cout<< "\n\nEnter Your Name : ";
    cin>>o.name;
    cout<< "\nEnter Your Code Name : ";
    cin>>o.code_name;
    cout<< "\nEnter Your Grade : ";
    cin>>o.grade;
    cout<<"\n";

    return o;

}

casual take_input_c(casual c)
{
    cout<< "\n\nEnter Your Name : ";
    cin>>c.name;
    cout<< "\nEnter Your Code Name : ";
    cin>>c.code_name;
    cout<<"\nEnter Your Typing Speed (Words Per Minute) : ";
    cin>>c.speed;
    cout<< "\nEnter Your Daily Wage : ";
    cin>>c.daily_wages;
    cout<<"\n";

    return c;
}

regular take_input_r(regular r)
{
    cout<< "\n\nEnter Your Name : ";
    cin>>r.name;
    cout<< "\nEnter Your Code Name : ";
    cin>>r.code_name;
    cout<<"\nEnter Your Typing Speed (Words Per Minute) : ";
    cin>>r.speed;
    cout<< "\nEnter Your Wage : ";
    cin>>r.wages;
    cout<<"\n";

    return r;

}

int main()
{
    int x;
    cout<< "Enter The Number Of Teacher's Data You Want To Add In The Database :\n";
    cin>>x;

    teacher database_t[x];

    for(long long int i=0;i<x;i++)
    database_t[i]=take_input_t(database_t[i]);

    int y;
    cout<< "\n\nEnter The Number Of Officer's Data You Want To Add In The Database :\n";
    cin>>y;

    officer database_o[y];

    for(long long int i=0;i<y;i++)
    database_o[i]=take_input_o(database_o[i]);

    int z;
    cout<< "\n\nEnter The Number Of Regular Typist's Data You Want To Add In The Database :\n";
    cin>>z;

    regular database_r[z];

    for(long long int i=0;i<z;i++)
    database_r[i]=take_input_r(database_r[i]);

    int p;
    cout<< "\n\nEnter The Number Of Casual Typist's Data You Want To Add In The Database :\n";
    cin>>p;

    casual database_c[p];

    for(long long int i=0;i<p;i++)
    database_c[i]=take_input_c(database_c[i]);

    cout<< "\n\nIf You Want To Search By Name, Press 0\nIf You Want To Search By Codename, Press 1\nIf You Want To Exit, Press Any Key Except 0 Or 1\n";
    int ch;
    cin>>ch;
    cout<<"\n";

    if(ch==0)
    {
        string s;
        int c=0;
        cout<<"Enter The Name You Want To Search :\n";
        cin>>s;
        cout<<"\n\n";

        long long int i;

        cout<<"Match In Teacher's Database :\n";

        for(i=0;i<x;i++)
        {
            

            if(database_t[i].name==s)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_t[i].name<<"\n"<<"    Codename : "<<database_t[i].code_name<<"\n"<<"    Subject : "<<database_t[i].subject<<"\n"<<"    Publication : "<<database_t[i].publication<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Teacher's Database !!\n\n";

        
        c=0;
        cout<<"Match In Officer's Database :\n";

        for(i=0;i<y;i++)
        {
            

            if(database_o[i].name==s)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_o[i].name<<"\n"<<"    Codename : "<<database_o[i].code_name<<"\n"<<"    Grade : "<<database_o[i].grade<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Officer's Database !!\n\n";


        c=0;
        cout<<"Match In Regular Typist's Database :\n";

        for(i=0;i<z;i++)
        {
            

            if(database_r[i].name==s)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_r[i].name<<"\n"<<"    Codename : "<<database_r[i].code_name<<"\n"<<"    Wage : "<<database_r[i].wages<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Regular Typist's Database !!\n\n";


        c=0;
        cout<<"Match In Casual Typist's Database :\n";

        for(i=0;i<p;i++)
        {
            

            if(database_c[i].name==s)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_c[i].name<<"\n"<<"    Codename : "<<database_c[i].code_name<<"\n"<<"    Daily Wage : "<<database_c[i].daily_wages<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Casual Typist's Database !!\n\n";


    }
    else if(ch==1)
    {

        string ss;
        int c=0;
        cout<<"Enter The Codename You Want To Search :\n";
        cin>>ss;
        cout<<"\n\n";

        long long int i;
        cout<<"Match In Teacher's Database :\n";

        for(i=0;i<x;i++)
        {
            

            if(database_t[i].code_name==ss)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_t[i].name<<"\n"<<"    Codename : "<<database_t[i].code_name<<"\n"<<"    Subject : "<<database_t[i].subject<<"\n"<<"    Publication : "<<database_t[i].publication<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Teacher's Database !!\n\n";

        
        c=0;
        cout<<"Match In Officer's Database :\n";

        for(i=0;i<y;i++)
        {
            

            if(database_o[i].code_name==ss)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_o[i].name<<"\n"<<"    Codename : "<<database_o[i].code_name<<"\n"<<"    Grade : "<<database_o[i].grade<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Officer's Database !!\n\n";


        c=0;
        cout<<"Match In Regular Typist's Database :\n";

        for(i=0;i<z;i++)
        {
            

            if(database_r[i].code_name==ss)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_r[i].name<<"\n"<<"    Codename : "<<database_r[i].code_name<<"\n"<<"    Wage : "<<database_r[i].wages<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Regular Typist's Database !!\n\n";


        c=0;
        cout<<"Match In Casual Typist's Database :\n";
        for(i=0;i<p;i++)
        {
            

            if(database_c[i].code_name==ss)
            {
                c++;
                cout<<"("<<c<<")"<<" Name : "<<database_c[i].name<<"\n"<<"    Codename : "<<database_c[i].code_name<<"\n"<<"    Daily Wage : "<<database_c[i].daily_wages<<"\n\n";
            }
            else
            continue;
        }

        if(c==0)
        cout<<"No Match Found In Casual Typist's Database !!\n\n";

    }
    else
    return 0;

    return 0;
}
