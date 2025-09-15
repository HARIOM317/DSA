#include <iostream>
#include <queue>

using namespace std;

class Student
{
public:
    string name;
    int marks;

    Student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }

    // overload < operator (comparator)
    bool operator<(const Student &obj) const
    {
        return this->marks < obj.marks;
    }
};

int main()
{
    priority_queue<Student> pq;

    pq.push(Student("Hariom", 490));
    pq.push(Student("Aman", 250));
    pq.push(Student("Ankit", 440));
    pq.push(Student("Harsh", 500));
    pq.push(Student("Pooja", 495));

    while (!pq.empty())
    {
        cout << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}