#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Determine the minimum number of platforms required at a railway station so that no train waits.

int findPlatforms(vector<int> &arrival, vector<int> &departure)
{
    // sort both arrays
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int paltforms = 1, maxPlatforms = 1;
    int i = 1, j = 0, n = arrival.size();

    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            paltforms++;
            i++;
        }
        else
        {
            paltforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, paltforms);
    }

    return maxPlatforms;
}

int main()
{
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};        // when train comes on paltform
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};        // when train moves from platform

    cout << "Minimum required platforms: " << findPlatforms(arrival, departure) << endl;

    return 0;
}