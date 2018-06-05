#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>

void append(const vector<int> & v1, vector<int> & v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        v2.push_back(v1[i]);
    }
}

int main()
{
    vector<int> v1 = {4, 5, 6};
    vector<int> v2 = {1, 2, 3};
    append(v1, v2);
    for (int x : v2) cout << x << ' ';
    cout << '\n';

    //testing replace(start, stop, x, y)
    vector<int> v3 = {1, 2, 2, 7, 9, 5, 2};
    vector<char> v4 = {'a', 'b', 'c', 'b', 'd'};
    replace(v3.begin(), v3.end(), 2, 17);
    for (int x : v3) cout << x << ' ';
    cout << '\n';
    replace(v4.begin(), v4.end(), 'b', 'q');
    for (char x : v4) cout << x << ' ';
    cout << '\n';

    //testing max_element(start, stop)
    vector<int> v5 = {1, 2, 2, 7, 9, 5, 2};
    vector<char> v6 = {'a', 'b', 'c', 'b', 'd'};
    *max_element(v5.begin(), v5.end()) = 15;
    for (int x : v5) cout << x << ' ';
    cout << '\n';
    *max_element(v6.begin(), v6.end()) = 't';
    for (char x : v6) cout << x << ' ';
    cout << '\n';

    return 0;
}
