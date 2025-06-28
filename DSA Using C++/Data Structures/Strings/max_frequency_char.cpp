#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "i am coming back and i will help to everyone";

    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;
    }

    char ans = 'a';
    int maxFreq = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            ans = i + 'a';
        }
    }

    cout << "Frequency = " << maxFreq << " and character = " << ans << endl;

    return 0;
}