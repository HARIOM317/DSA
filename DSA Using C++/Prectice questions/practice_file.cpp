#include <iostream>

using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *prev;

     Node(int val)
     {
          data = val;
          prev = next = nullptr;
     }

     ~Node()
     {
          cout << "Deleted: " << this->data << endl;
     }
};

class DoublyList
{
     Node *head;
     Node *tail;

public:
     DoublyList()
     {
          head = tail = nullptr;
     }

     void push_front(int val)
     {
          Node *newNode = new Node(val);

          if (head == nullptr)
          {
               head = tail = newNode;
          }
          else
          {
               newNode->next = head;
               head->prev = newNode;
               head = newNode;
          }
     }

     void push_back(int val)
     {
          Node *newNode = new Node(val);

          if (head == nullptr)
          {
               head = tail = newNode;
          }
          else
          {
               tail->next = newNode;
               newNode->prev = tail;
               tail = newNode;
          }
     }

     void pop_front()
     {
          if (head == nullptr)
          {
               return;
          }
          else if (head->next == nullptr)
          {
               delete head;
               head = tail = nullptr;
          }
          else
          {
               Node *temp = head;
               head = head->next;
               head->prev = temp->next = nullptr;
               delete temp;
          }
     }

     void pop_back()
     {
          if (head == nullptr)
          {
               return;
          }
          else if (head->next == nullptr)
          {
               delete head;
               head = tail = nullptr;
          }
          else
          {
               Node *temp = head;
               while (temp->next != tail)
               {
                    temp = temp->next;
               }
               temp->next = tail->prev = nullptr;
               delete tail;
               tail = temp;
          }
     }

     void print() const
     {
          if (head == nullptr)
               return;

          Node *temp = head;
          cout << "NULL <= ";
          while (temp != nullptr)
          {
               cout << temp->data << ((temp->next == nullptr) ? " => " : " <=> ");
               temp = temp->next;
          }
          cout << " NULL\n\n";
     }
};

int main()
{
     DoublyList dll;

     dll.push_front(30);
     dll.push_front(20);
     dll.push_front(10);

     dll.push_back(40);
     dll.push_back(50);
     dll.push_back(60);

     dll.print();

     dll.pop_front();
     dll.pop_front();

     dll.pop_back();
     dll.pop_back();

     dll.print();

     return 0;
}