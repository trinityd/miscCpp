#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <list>
using std::list;

class StartsWith
{
public:
    StartsWith(const char & c0) : c(c0) {}
    bool operator()(const string & s) { return (s[0] == c); }

private:
    char c;
};

namespace my
{
template <typename Iterator, typename UnaryPredicate>
void print_if(Iterator start, Iterator stop, UnaryPredicate condition, ostream & out)
{
    for(Iterator itr = start; itr != stop; ++itr)
    {
        if(condition(*itr)) out << *itr << endl;
    }
}

template <typename T>
void print(const list<T> & ls, int n)
{
    if (ls.size() > n)
    {
        auto itr = ls.begin();
        for (int i = 0; i < n; i++)
        {
            cout << *itr << endl;
            advance(itr,1);
        }
    }
    else
    {
        for (T e : ls) cout << e << endl;
    }
}
}

bool is_positive(int x)
{
    return (x > 0);
}

int main()
{
    vector<int> v1 = {1, -4, 3, 0, -7, 2};
    my::print_if(v1.begin(), v1.end(), is_positive, cout);
    cout << endl;

    vector<string> v2 = {"apple", "orange", "animal", "xylophone", "angry"};
    cout << "There are " << std::count_if(v2.begin(), v2.end(), StartsWith('a')) << endl;
    cout << endl;

    list<int> ls1 = {7, 2, 12, 4, 5};
    my::print(ls1, 3);
    cout << endl;
    my::print(ls1, 7);

    return 0;
}
