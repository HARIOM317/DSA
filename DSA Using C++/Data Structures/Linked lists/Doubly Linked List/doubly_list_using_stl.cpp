#include <iostream>
#include <list>
#include <iterator> // to use iterator

using namespace std;

void printList(list<int> &ll)
{
    cout << "\n";
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << *itr << " -> ";
    }
    cout << "NULL\n\n";
}

int main()
{
    list<int> ll;
    ll.assign(3, -1); // assign 3 times -1
    printList(ll);    // -1->-1->-1->NULL

    // _____ INSERTION _____
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10);

    ll.push_back(40);
    ll.push_back(50);
    ll.push_back(60);

    ll.insert(ll.begin(), 5);
    ll.insert(ll.end(), 65);

    list<int>::iterator itr = ll.begin(); // creating iterator
    advance(itr, 3);                      // move itr to pos 3
    ll.insert(itr, 25);                   // insert 25 at pos 3

    printList(ll); // 5->10->20->25->30->-1->-1->-1->40->50->60->65->NULL

    ll.insert(itr, 3, 100); // insert 3 time 100 after 25

    printList(ll); // 5->10->20->25->100->100->100->30->-1->-1->-1->40->50->60->65->NULL

    // _____ DELETION _____
    ll.pop_front(); // remove 5
    ll.pop_front(); // remove 10
    ll.pop_back();  // remove 65
    ll.pop_back();  // remove 60

    printList(ll); // 20->25->100->100->100->30->-1->-1->-1->40->50->NULL

    cout << "Front: " << ll.front() << endl;
    cout << "Back: " << ll.back() << endl;

    ll.remove(10); // element not found
    ll.remove(25); // remove 25

    auto itr2 = ll.begin(); // creating another iterator
    advance(itr2, 2);       // move itr at pos 2
    ll.erase(itr2);         // remove 100
    ll.erase(ll.begin());   // remove 20

    printList(ll); // 100->100->100->30->-1->-1->-1->40->50->NULL

    ll.sort();

    printList(ll); // -1->-1->-1->30->40->50->100->100->NULL

    return 0;
}