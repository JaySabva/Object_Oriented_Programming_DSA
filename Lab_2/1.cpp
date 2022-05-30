#include<iostream>

using namespace std;

int num;

class octal;

class binary {
   int decimal1;

   public:

   void display(int n1);
   void setdata_b(int num);
   friend int ans(binary & n, octal & m);
};

class octal {
   int decimal2;
   public:

   void display(int n2);
   void setdata_o(int num);
   friend int ans(binary & n, octal & m);
};

void binary::display(int n1) {
   decimal1 = n1;
}
void octal::display(int n2) {
   decimal2 = n2;
}

void binary::setdata_b(int num) {
   int sum = 0, i = 1, rem;
   while (num != 0) {
      rem = num % 2;
      num = num / 2;
      sum += rem * i;
      i = i * 10;
   }
   cout << "Binary Equivalence: " << sum;
}

void octal::setdata_o(int num) {
   int sum2 = 0, rem, i = 1;
   while (num != 0) {
      rem = num % 8;
      num /= 8;
      sum2 += rem * i;
      i *= 10;
   }
   cout << "Octal Equivalence: " << sum2;
}

int ans(binary & n, octal & m) {
   num = n.decimal1 + m.decimal2;
   return num;
}

int main() {
   int n1, n2;
   binary n;
   octal m;

   cout << "Enter 1st Number : ";
   cin >> n1;
   cout << "Enter 2nd Number : ";
   cin >> n2;

   n.display(n1);
   m.display(n2);
   num = ans(n, m);

   cout << "Sum of Two Number : " << num;
   cout << endl;

   n.setdata_b(num);
   cout << endl;
   m.setdata_o(num);

}
