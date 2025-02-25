#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximize the total value in a knapsack by taking fractions of items. Items are sorted based on their value-to-weight ratio.

struct Item
{
    int value;
    int weight;
};

bool compare(Item a, Item b)
{
    double item1 = (double)a.value / a.weight;
    double item2 = (double)b.value / b.weight;

    return item1 > item2;
}

double fractionalKnapsack(vector<Item> &items, int capacity)
{
    // sort the items array
    sort(items.begin(), items.end(), compare);

    // calculate maximum total value
    double totalValue = 0.0;
    for (Item item : items)
    {
        if (capacity >= item.weight)
        {
            // take complete item
            totalValue += item.value;
            capacity -= item.weight;
        }
        else
        {
            // take fraction of item
            totalValue += item.value * (1.0 * capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    cout << "Maximum value: " << fractionalKnapsack(items, capacity) << endl;

    return 0;
}