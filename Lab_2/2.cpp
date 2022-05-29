#include <iostream>
using namespace std;

class vector{
    public:
    int x[3];
    friend void matrixmulti(int*a,vector v,int*b,int col);
};

class matrix{
    public:
    int r=3,c;
    void matrixmulti(int *a,vector v,int *b,int col){
        for(int i=0;i<col;i++){
            int q=0;
            for(int j=0;j<3;j++){
            int p=v.x[j]*a[i+col*j];
            q+=p;
        }
        b[i]=q;
        }
    }
};


int col;
int main(){
    matrix m;
    vector v;
    
    cout<<"Enter The Size Of Column In Matrix: ";
    cin>>m.c;
    
    int t=3*m.c;
    col=m.c;
    int* a=(int*)calloc(t, sizeof(int));
    for(int i=0;i<t;i++){
        cout<<"Enter Matrix Value"<<" "<<i+1<<"\n";
        cin>>a[i];
    }
    
    cout<<"Enter X Projection: ";
    cin>>v.x[0];
    cout<<"Enter Y Projection: ";
    cin>>v.x[1];
    cout<<"Enter Z Projection: ";
    cin>>v.x[2];
    
    int* b=(int*)calloc(col, sizeof(int));
    m.matrixmulti(a,v,b,col);
    for(int i=0;i<col;i++){
        cout<<"\n"<<b[i];
    }

}
