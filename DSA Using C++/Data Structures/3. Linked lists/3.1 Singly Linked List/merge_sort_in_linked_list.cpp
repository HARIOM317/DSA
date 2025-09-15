#include <iostream>

using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

// Linked List
class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    // to print linked list
    void print()
    {
        Node *temp = head;
        cout << "\n";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << "\n\n";
        delete temp;
    }

    // _____ INSERTION OPERATION _____
    // 1. to insert at front
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // 2. to insert at end
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

// to split list at mid
Node *splitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = head; // to track prev node of slow

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    return slow;
}

// to merge two sorted linked lists
Node *merge(Node *leftHead, Node *rightHead)
{
    List ans;
    Node *i = leftHead;
    Node *j = rightHead;

    while (i != nullptr && j != nullptr)
    {
        if (i->data < j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != nullptr)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != nullptr)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *rightHead = splitAtMid(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);

    return merge(left, right);
}

int main()
{
    List ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);

    ll.push_back(60);
    ll.push_back(70);
    ll.push_back(100);
    ll.push_back(80);
    ll.push_back(90);

    ll.print();

    ll.head = mergeSort(ll.head); // return sorted list head

    ll.print();

    return 0;
}