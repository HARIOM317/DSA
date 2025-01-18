#include <iostream>
#include <string>

using namespace std;

int main()
{
     string s = "###01###";
     cout << "Before: " << s << endl;

     int i = 0;
     while (i < s.size())
     {
          int j = i + 1;
          if (j < s.size() && s[i] == '0' && s[j] == '#')
          {
               // Remove # after 0
               s.erase(j, 1);
          }
          else if (j < s.size() && s[i] == '1' && s[j] == '#')
          {
               // Remove # before 1
               s.erase(j, 1);
          }
          else
          {
               i++; // Increment only if no erase occurs
          }
     }

     cout << "After: " << s << endl;

     return 0;
}
