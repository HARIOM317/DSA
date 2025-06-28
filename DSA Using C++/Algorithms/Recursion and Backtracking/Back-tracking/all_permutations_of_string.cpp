#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string str, int index, vector<string> &ans){
    // base case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        solve(str, index+1, ans);
        swap(str[index], str[i]); // backtracking
    }
    
}

vector<string> permutations(string str) {
    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    return ans;
}

int main()
{
    string str = "abc";

    vector<string> ans = permutations(str);

    // printing all permutations
    cout << "All permutations are:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            cout << (j >= ans[i].size() - 1 ? "" : ",");
        }
        cout << "}" << endl;
    }

    return 0;
}