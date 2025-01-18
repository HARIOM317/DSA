#include <iostream>

using namespace std;

// Celsius to Fahrenheit
int main()
{
    float temperature;
    cout << "Enter the temperature in Celsius: ";
    cin >> temperature;

    float fahrenheit = ((9.0 / 5) * temperature) + 32;
    cout << temperature << "°C = " << fahrenheit << "°F" << endl;

    return 0;
}