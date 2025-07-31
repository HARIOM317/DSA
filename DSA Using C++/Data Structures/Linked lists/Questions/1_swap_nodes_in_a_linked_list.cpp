/*
    Swapping Nodes in a Linked List

    We have a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when the data contains many fields. It may be assumed that all keys in the linked list are distinct.

    Sample Input 1: 1->2->3->4,  x = 2, y = 4
    Sample Output 1: 1->4->3->2
*/

#include <iostream>

using namespace std;

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
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// function to swap nodes without changing data
Node *swapNodes(Node *head, int x, int y)
{
    // edge cases
    if (x == y) // no need to swap
        return head;

    Node *prevX = nullptr, *currX = head;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = nullptr, *currY = head;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // if either x or y is not present, do nothing
    if (!currX || !currY)
        return head;

    // if x is not head
    if (prevX)
        prevX->next = currY;
    else
        head = currY;

    // if y is not present
    if (prevY)
        prevY->next = currX;
    else
        head = currX;

    // swap next pointers
    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

int main()
{
    // Constructed linked list:
    // 1->2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);

    head = swapNodes(head, 2, 4);

    printList(head);

    return 0;
}