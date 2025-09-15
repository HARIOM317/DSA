#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char word[] = {'H', 'e', 'L', 'L', 'o', '!', '\0'};
    
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 'a' + 'A';
        }
    }

    cout << word << endl;

    return 0;
}