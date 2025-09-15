#include <iostream>
#include <queue>

using namespace std;

// custom comparator
struct compare
{
    // overload () operator
    bool operator()(pair<string, int> &p1, pair<string, int> &p2)
    {
        return p1.second < p2.second;
    }
};

int main()
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;

    pq.push(make_pair("Hariom", 490));
    pq.push(make_pair("Aman", 250));
    pq.push(make_pair("Ankit", 440));
    pq.push(make_pair("Harsh", 500));
    pq.push(make_pair("Pooja", 495));

    while (!pq.empty())
    {
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}