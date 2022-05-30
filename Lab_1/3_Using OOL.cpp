#include<iostream>
using namespace std;
class complex
{
    int real,img;
    public:
    complex()
    {
        real=0;
        img=0;
    }
    complex(int r)
    {
        cout<<"Enter real part: ";
        cin>>real;
        cout<<"Enter imaginary part: ";
        cin>>img;
    }
    void display()
    {
        cout<<"("<<real<<","<<img<<")";
    }
    complex operator+(complex &c)
    {
        complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    complex operator-(complex &c)
    {
        complex temp;
        temp.real=real-c.real;
        temp.img=img-c.img;
        return temp;
    }
    complex operator*(complex &c)
    {
        complex temp;
        temp.real=real*c.real-img*c.img;
        temp.img=real*c.img+img*c.real;
        return temp;
    }
};
int main()
{
    complex c1(0),c2(0);
    complex c3;
    c1.display();
    cout<<"+";
    c2.display();
    cout<<"=";
    c3=c1+c2;
    c3.display();
    cout<<endl;
    c1.display();
    cout<<"+";
    c2.display();
    cout<<"=";
    c3=c1-c2;
    c3.display();
    cout<<endl;
    c1.display();
    cout<<"*";
    c2.display();
    cout<<"=";
    c3=c1*c2;
    c3.display();
    return 0;
}
