#include <fstream>
using std::ifstream;
#include <iomanip>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
#include <initializer_list>
using std::initializer_list;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <numeric> //std::accumulate for P3

namespace my {
template <typename T>
ifstream & read(ifstream & in, vector<T> & v)
{
    T x;
    while(in >> x)
    {
        v.push_back(x);
    }
    return in;
}

template <typename Iterator, typename T>
void increment(Iterator start, Iterator stop, const T & x)
{
    for (Iterator itr = start; itr != stop; ++itr) *itr += x;
}

template <typename T>
int total(const initializer_list<T> & init_list)
{
    int r = 0;
    for(T x : init_list) r += x;
    return r;
}
}

int main()
{
ifstream in("inputint.txt");
vector<int> v;
my::read(in, v);
for(int i : v) cout << i << ' ';
cout << endl;

ifstream in2("inputstring.txt");
vector<string> v2;
my::read(in2, v2);
for(string i : v2) cout << i << ' ';
cout << endl;

vector<int> v3({1, 2, 3, 4, 5});
my::increment(v3.begin(), v3.end(), 10);
for(int i : v3) cout << i << ' ';
cout << endl;

cout << my::total({1, 2, 3, 4, 5});

return 0;
}
