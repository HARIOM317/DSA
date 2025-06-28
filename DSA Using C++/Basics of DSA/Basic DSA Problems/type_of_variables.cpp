#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int *p1, a = 10;
    float *p2, b = 2.5;
    char *p3, c = 'A';
    double *p4, d = 10.503;
    long long *p5, e = 100000;
    string *p6, f = "Hello!";

    cout << typeid(p1).name() << " & " << typeid(a).name() << endl;
    cout << typeid(p2).name() << " & " << typeid(b).name() << endl;
    cout << typeid(p3).name() << " & " << typeid(c).name() << endl;
    cout << typeid(p4).name() << " & " << typeid(d).name() << endl;
    cout << typeid(p5).name() << " & " << typeid(e).name() << endl;
    cout << typeid(p6).name() << " & " << typeid(f).name() << endl;

    return 0;
}