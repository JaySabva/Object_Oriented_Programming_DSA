#include<bits/stdc++.h>
using namespace std;

class Point;
int compareX(const void *a, const void *b);
int compareY(const void *a, const void *b);
float distance(Point, Point);
float ErrorTrial(Point, int);
float min(float, float);
float stripSearch(Point, int, float);
float PairFinder(Point, int);
float sortX(Point, int);

// SABVA JAY DILIPBHAI-202101224

class Point
{
public:
    int x, y;
};

int strip1 = 0, strip2 = 0, brute1 = 0, brute2 = 0;
float bd=FLT_MAX,sd=FLT_MAX;
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float distance(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

float ErrorTrial(Point P[], int n)
{
    float min = FLT_MAX;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (distance(P[i], P[j]) < min)
            {
                min = distance(P[i], P[j]);
                if(bd>min)
                {
                    brute1 = i;
                    brute2 = j;
                    bd=min;
                }
            }
        }
    }

    return min;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

float stripSearch(Point strip[], int size, float d)
{
    float min = d;

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {
            if (distance(strip[i], strip[j]) < min)
            {
                min = distance(strip[i], strip[j]);
                if(sd>min)
                {
                    strip1 = i;
                    strip2 = j;
                    sd=min;
                }
            }
        }
    }

    return min;
}

float PairFinder(Point P[], int n)
{

    if (n <= 3)
        return ErrorTrial(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    float dl = PairFinder(P, mid);
    float dr = PairFinder(P + mid, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;

    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    if (min(d, stripSearch(strip, j, d) ) == d)
    {
        cout << "The Closest Point Pairs Are :";
        cout << "(" << P[brute1].x << "," << " " << P[brute1].y << ") and (" << P[brute2].x << "," << P[brute2].y << ")";
    }
    else
    {
        cout << "The Closest Point Pairs are :";
        cout << "(" << P[strip1].x << "," << P[strip1].y << ") and (" << P[strip2].x << " " << P[strip2].y << ")";
    }

    return min(d, stripSearch(strip, j, d));
}

float sortX(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return PairFinder(P, n);
}

int main()
{
    int n;
    cout << "--------------------------------------------------\n";
    cout << "Enter How Many Pairs Do You Have(n>3) ?\n";
    cout << "--> ";
    cin >> n;
    cout << "--------------------------------------------------\n";
    Point P[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter x of " << i + 1 << " th pair : ";
        cin >> P[i].x;
        cout << "Enter y of " << i + 1 << " th pair : ";
        cin >> P[i].y;
        cout << "--------------------------------------------------\n";
    }
    sortX(P, n);
    return 0;
}
