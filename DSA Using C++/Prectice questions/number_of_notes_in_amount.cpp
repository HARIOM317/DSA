#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter Amount: ";
    cin >> n;

    int thousands, fiveHundreds, twoHundreds, hundreds, fifties, twenties, tens, fives, twos, ones;

    thousands = fiveHundreds = twoHundreds = hundreds = fifties = twenties = tens = fives = twos = ones = 0;

    if (n >= 1000)
    {
        thousands = n / 1000;
        n = n % 1000;
    }
    if (n >= 500)
    {
        fiveHundreds = n / 500;
        n = n % 500;
    }
    if (n >= 200)
    {
        twoHundreds = n / 200;
        n = n % 200;
    }
    if (n >= 100)
    {
        hundreds = n / 100;
        n = n % 100;
    }
    if (n >= 50)
    {
        fifties = n / 50;
        n = n % 50;
    }
    if (n >= 20)
    {
        twenties = n / 20;
        n = n % 20;
    }
    if (n >= 10)
    {
        tens = n / 10;
        n = n % 10;
    }
    if (n >= 5)
    {
        fives = n / 5;
        n = n % 5;
    }
    if (n >= 2)
    {
        twos = n / 2;
        n = n % 2;
    }
    if (n >= 1)
    {
        ones = n;
    }

    cout << "\nThousand's Note = " << thousands << endl;
    cout << "Five Hundred's Note = " << fiveHundreds << endl;
    cout << "Two Hundred's Note = " << twoHundreds << endl;
    cout << "Hundred's Note = " << hundreds << endl;
    cout << "Fifty's Note = " << fifties << endl;
    cout << "Twenty's Note = " << twenties << endl;
    cout << "Ten's Note = " << tens << endl;
    cout << "Five's Note = " << fives << endl;
    cout << "Two's Note = " << twos << endl;
    cout << "One's Note = " << ones << endl
         << endl;

    return 0;
}