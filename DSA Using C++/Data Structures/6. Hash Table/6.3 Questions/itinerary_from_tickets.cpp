#include <bits/stdc++.h>

using namespace std;

/*
    Given, Plane ticket pairs <from, to>

    i.e.    Chennai -> Bengaluru
            Mumbai -> Delhi
            Goa -> Chennai
            Delhi -> Goa

    Reconstruct it in order to initial source -> final destination

    Output: Mumbai -> Delhi -> Goa -> Chennai -> Bengaluru

*/

void printItinerary(unordered_map<string, string> &tickets)
{
    // find start point
    unordered_set<string> s;
    for (auto p : tickets)
        s.insert(p.second);

    string start = "";
    for (auto p : tickets)
    {
        string source = p.first;
        if (s.find(source) == s.end())
        {
            start = source;
            break;
        }
    }

    // print trip
    cout << start;
    for (auto p : tickets)
    {
        cout << " -> " << tickets[start];
        start = tickets[start];
    }
}

int main()
{
    unordered_map<string, string> tickets;

    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0;
}