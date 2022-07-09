////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       @ Author- Sabva Jay Dilipbhai                                                //
//                                       $ ID-202101224                                                               //
//                                       % Implementation of maximum heap tree                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;
class heap
{
public:
    int n;
    int *arr;
    int N;
    heap()
    {
        cout << "Enter the size of heap: ";
        cin >> n;
        arr = new int[n];
        N = n;

        for (int i = 0; i < n; i++)
        {
            arr[i] = -32768; 
        }
    }
  void heapify_max(int *arr, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if (l < n && arr[l] > arr[max])
        max = l;

    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i)
    {
        swap(&arr[max], &arr[i]);
        heapify_max(arr, max, n);
    }
    return;
}
void heapify_min(int *arr, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int min = i;

    if (l < n && arr[l] < arr[min])
        min = l;

    if (r < n && arr[r] < arr[min])
        min = r;

    if (min != i)
    {
        swap(&arr[min], &arr[i]);
        heapify_min(arr, min, n);
    }
    return;
}
void heap_sort(int C, int n)
{
    if (n > 0)
    {
        if (arr[0] != -32768)
            cout << arr[0] << " ";
        swap(&arr[0], &arr[n - 1]);
        n = n - 1; // decreasing the size of the array
        if (C == 0)
        {
            for (int i = n / 2; i >= 0; i--)
            {
                heapify_min(arr, i, n);
            }
            heap_sort(C, n);
        }
        else if (C == 1)
        {
            for (int i = n / 2; i >= 0; i--)
            {
                heapify_max(arr, i, n);
            }
            heap_sort(C, n);
        }
    }
    else
        return;
}
void check(int C)
{
    if (C == 0)
    {
        for (int i = N / 2; i >= 0; i--)
        {
            heapify_min(arr, i, N);
        }
    }
    else if (C == 1)
    {
        for (int i = N / 2; i >= 0; i--)
        {
            heapify_max(arr, i, N);
        }
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int j = 0;
void insert(int k)
{
    if (j < N)
    {
        arr[j] = k;
        j++;
    }
    else
        cout << "Cannot exceed the size of heap" << endl;
}
void remove(int k, int *arr)
{
    int i = 0;
    if (arr[0] != -32768)
    {
        while (arr[i] != k && i<N)
            i++;
        if(i==N-1 && arr[i]!=k){
            cout<<"Element not Found"<<endl;
            i++;
            return;
        }
        else{
        int p;
        p=j-1;
        if (i != p){
            arr[i] = arr[p];
            arr[p] = -32768;
        }
        else
            arr[i] = -32768;
        j--;
        return;
        }
    }
    else
    {
        cout << "Heap is Empty" << endl;
        return;
    }

    cout<<"Element not found"<<endl;
    // check(C);
}
void display()
{
    int i = 0;
    for (i = 0; i < N; i++)
        if (arr[i] != -32768)
            cout << arr[i] << " ";

    cout << endl;
}
};

int main()
{
    heap h;
    int C;
    int s, k;
   
    while (s!=5)
    {   
         cout << "-------------------------------------" << endl;
         cout << "1.Insert\n2.Heapify\n3.Traverse\n4.Delete\n5.Exit" << endl;
         cout << "-------------------------------------" << endl;
         cin >> s;

        switch (s)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> k;
            h.insert(k);
            break;

        case 2:
            cout << "Which Heap You want to heapify? \n(0 for min heap/ 1 for Max heap):";
            cin >> C;
            h.check(C);
            if (C == 0)
            {
                cout << "Heap sorted in ascending order after heapsort: ";
                h.heap_sort(C, h.N);
                cout << endl;
            }
            else if (C == 1)
            {
                cout << "Heap sorted in descending order after heapsort: ";
                h.heap_sort(C, h.N);
                cout << endl;
            }
            else
                cout << "Enter a valid input" << endl;
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout << "Enter the element you wish to delete: ";
            cin >> k;
            h.remove(k, h.arr);
            break;
        }
    }
    return 0;
}