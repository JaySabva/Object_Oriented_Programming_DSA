#include <iostream>

using namespace std;
void fun(int & x, int & y) {
   int temp;
   temp = x;
   x = y;
   y = temp;
}
int main() {
   int x, y;
   cout << "Enter value of x\n";
   cin >> x; //input x
   cout << "Enter value of y\n";
   cin >> y; //input y
   fun(x, y); //function calling
   cout << "Values after swaping\n";
   cout << "Value Of X=" << x << "\n" << "Value Of Y=" << y; //value after swaping

   return 0;
}
