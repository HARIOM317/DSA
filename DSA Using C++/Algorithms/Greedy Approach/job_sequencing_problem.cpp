#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Schedule jobs to maximize profit by choosing the jobs with the highest profit that can be done before their deadlines.

struct Job
{
    int id;
    int deadline;
    int profit;
};

pair<int, int> jobScheduling(vector<Job> jobs)
{
    int n = jobs.size();

    // sort jobs in decreasing order on the basis of profit
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b)
         { return a.profit > b.profit; }); // lambda compare function

    // get maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> slot(maxDeadline + 1, -1);
    int jobCount = 0, maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            // is slot is available
            if (slot[j] == -1)
            {
                slot[j] = jobs[i].id; // assign job in current slot
                jobCount++;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {jobCount, maxProfit};
}

int main()
{
    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};

    pair<int, int> ans = jobScheduling(jobs);
    cout << "Total Jobs = " << ans.first << ", " << "Total Profit = " << ans.second << endl;

    return 0;
}