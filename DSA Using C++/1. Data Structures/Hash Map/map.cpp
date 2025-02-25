#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> m; // map<key, value> map_name

    // __________ INSERTION __________
    // 1. using key name
    m["Welcome"] = 1;
    m["Welcome"] = 2; // update value of key Welcome (key will always be unique)

    // 2. using pair
    pair<string, int> p1 = make_pair("Hariom", 3);
    m.insert(p1);
    pair<string, int> p2("Singh", 4);
    m.insert(p2);
    m.insert({"Rajput", 5});

    // __________ SEARCHING __________
    // 1. using at() method
    cout << "Hariom : " << m.at("Hariom") << endl;
    // cout << "Unknown : " << m.at("Unknown") << endl; // terminate

    // 2. using key name
    cout << "Welcome : " << m["Welcome"] << endl;
    cout << "Unknown : " << m["Unknown"] << endl; // create a new entry for key "Unknown" with value 0 and print them

    // __________ CHECK PRESENCE __________
    // using count(key_name) method
    cout << "\nIs key Hariom present : " << m.count("Hariom") << endl;
    cout << "Is key Unknown present : " << m.count("Unknown") << endl;

    // __________ ERASE __________
    m.erase("Unknown");
    cout << "Is key Unknown present (After erasing) : " << m.count("Unknown") << endl;

    // __________ ITERATION __________
    // 1. using for-each loop
    cout << "\nUsing for-each loop-" << endl;
    for (auto item : m)
    {
        cout << item.first << " : " << item.second << endl;
    }

    // 2. using iteration
    cout << "\nUsing iterator-" << endl;
    unordered_map<string, int>::iterator itr = m.begin();
    while (itr != m.end())
    {
        cout << itr->first << " : " << itr->second << endl;
        itr++;
    }

    return 0;
}