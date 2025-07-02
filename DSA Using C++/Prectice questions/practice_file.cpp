#include <iostream>

using namespace std;

void towerOfHanoi(int n, string src, string dest, string helper)
{
     if (n == 1)
     {
          cout << "Transfer plate " << n << " from " << src << " to " << dest << endl;
          return;
     }

     towerOfHanoi(n - 1, src, helper, dest);
     cout << "Transfer plate " << n << " from " << src << " to " << helper << endl;

     towerOfHanoi(n - 1, helper, dest, src);
}

int main()
{
     int n = 3;
     towerOfHanoi(n, "A", "C", "B");

     return 0;
}