#include<iostream>

using namespace std;
//this can be done by operator overloading
class complex {
   public:
      int real, imaginary;

   complex add(complex c1, complex c2) {
      complex x1;
      x1.real = c1.real + c2.real;
      x1.imaginary = c1.imaginary + c2.imaginary;
      return x1;
   }

   complex multiply(complex c1, complex c2) {
      complex x1;
      x1.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
      x1.imaginary = c1.imaginary * c2.real + c2.imaginary * c1.real;
      return x1;
   }
};

int main() {
   complex c1, c2, c3, c4;
   cout << "Enter 1st Complex Number:\n";
   cin >> c1.real >> c1.imaginary;
   cout << "Enter 2nd Complex Number:\n";
   cin >> c2.real >> c2.imaginary;

   c3 = c3.add(c1, c2);
   c4 = c4.multiply(c1, c2);

   cout << "Addition Of Two Complex Number = " << c3.real << "+(" << c3.imaginary << ")i " << endl;
   cout << "Multiplication Of Two Complex Number = " << c4.real << "+(" << c4.imaginary << ")i ";

   return 0;
}
