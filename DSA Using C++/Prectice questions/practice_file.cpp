#include <iostream>

using namespace std;

class Node
{
public:
     int data;
     Node *next;

     Node(int val)
     {
          data = val;
          next = nullptr;
     }
};

int main()
{
     Node *h1 = nullptr;
     Node *h2 = nullptr;

     cout << (h1 == h2) << endl;

     return 0;
}