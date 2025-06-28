#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Statement : You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

struct Activity
{
    int start, end;
};

// custom comparator
bool compare(Activity a, Activity b)
{
    return a.end < b.end;
}

int maxActivity(vector<Activity> activities)
{
    // sort activities on the basis of end time
    sort(activities.begin(), activities.end(), compare);

    int count = 1; // to track no of activities
    int lastEnd = activities[0].end;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start > lastEnd)
        {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main()
{
    // activity {start time, end time}
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {8, 9}};

    cout << "Max activities = " << maxActivity(activities) << endl;

    return 0;
}