#include <iostream>

using namespace std;

void removeDuplicates(string str, int i, string &ans, bool map[26])
{
    // base case
    if (i == str.size())
        return;

    if (map[str[i] - 'a'] == 0)
    {
        ans += str[i];
        map[str[i] - 'a'] = true;
    }

    removeDuplicates(str, i + 1, ans, map);
}

int main()
{
    string str = "hariomsinghrajput";
    string ans = "";
    bool map[26] = {false};

    removeDuplicates(str, 0, ans, map);
    cout << "Output: " << ans << endl;

    return 0;
}