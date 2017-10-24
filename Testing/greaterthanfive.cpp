#include <iostream>

using namespace std;

void greaterthanfive()
{
    int i;
    cout << "Please enter a number, and I'll tell you if it's greater than 5." << endl;
    cin >> i;
    if (i > 5)
    {
        cout << "It is greater than 5!" << endl;
    }
    else
    {
        cout << "It's not greater than 5." << endl;
    }
}
