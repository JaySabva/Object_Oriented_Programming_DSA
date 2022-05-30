#include <iostream>

using namespace std;
int n;
class vector {
   public:
      float vec[50];

   void modify(vector v, int x, int y) {
      v.vec[x] = y;
      cout << "Array Value After Changes:\n";
      v.display(v);

   }

   void display(vector v) {
      cout << "[ ";
      for (int i = 0; i < n; i++) {
         cout << v.vec[i] << " ";
      }
      cout << "]";
   }

   vector() {
      for (int i = 0; i < n; i++) {
         vec[i] = 0;
      }
   }

   vector(float * b) {
      for (int i = 0; i < n; i++) {
         vec[i] = arr[i];
      }
   }

   vector(vector & v) {
      for (int i = 0; i < n; i++) {
         vec[i] = v.vec[i];
      }
   }

};

int main() {
   cout << "Enter Size Of Array\n";
   cin >> n;
   float arr[n];

   vector z; //constructor call
   cout << "\n**Void Constructor**\n";

   z.display(z); //displaying void constructor
   cout << "\n";

   for (int i = 0; i < n; i++) {
      cout << "\nEnter Value Of " << i + 1 << "th Element Value\n";
      cin >> arr[i];
   }

   vector v(b);

   int x, y;
   vector p = v; //copy constructor call
   cout << "\n**Copy Constructor**\n";
   p.display(p); //displaying copy constructor
   cout << "\n\nEnter The Index Of Element To Change:\n";
   cin >> x;
   cout << "Enter The Value To Change:\n";
   cin >> y;
   v.modify(v, x, y);

}
