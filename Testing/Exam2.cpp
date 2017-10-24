#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
using std::endl;
#include <list>
using std::list;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;

class FractionInputError {
public:
    FractionInputError(const std::string & d) : description_(d) {}
    const std::string & what() const { return description_; }
private:
    std::string description_;
};

template <class T>
class IsLarge
{
public:
    IsLarge(T t0) : t(t0) {};
    bool operator () (T x) { return x > t; }

private:
    T t;
};

void read_fraction(int & a, int & b)
{
    int tempa;
    int tempb;
    if (!(cin >> tempa))
    {
        throw FractionInputError("Error: fraction could not be read.");
    }
    cin.get();
    if (!(cin >> tempb))
    {
        throw FractionInputError("Error: fraction could not be read.");
    }
    if (tempb == 0)
    {
        throw FractionInputError("Error: den = 0.");
    }
    a = tempa;
    b = tempb;
}

ifstream & read(ifstream & in, vector<int> & v)
{
    v.clear();
    int n;
    while (in >> n)
    {
        v.push_back(n);
    }
    return in;
}

namespace my
{
template <typename Iterator, typename T>
void fill(Iterator start, Iterator stop, T e)
{
    for (Iterator itr = start; itr != stop; ++itr)
    {
        *itr = e;
    }
}

template <typename Iterator, typename UnaryPredicate>
Iterator & find_if(Iterator start, Iterator stop, UnaryPredicate condition)
{
    for (Iterator itr = start; itr != stop; ++itr)
    {
        if (condition(*itr))
            return itr;
    }
    return stop;
}
}

template <typename T>
void append(int n, const T & e, list<T> & ls)
{
    for (int i = 0; i < n; i++)
    {
        ls.push_back(e);
    }
}

class PeopleEntry
{
public:
    PeopleEntry() : age(999), state("No State") {}
    PeopleEntry(const int age0, const string & state0) : age(age0), state(state0) {}

    int age;
    string state;
};

int main()
{
//    int * c;
//    c = nullptr;
//    cout << *c;

    int a = 7;
    int b = 10;

    try { read_fraction(a,b); }
    catch (const FractionInputError & e) { cout << e.what() << endl; }
    cout << a << '/' << b << endl;

    ifstream in("inputint.txt");
    vector<int> v;
    read(in, v);
    for (int n : v) cout << n << ' ';
    cout << endl;

    vector<int> v1 = {1, 2, 3, 4, 5};
    my::fill(v1.begin(), v1.end(), 9);
    for (int n : v1) cout << n << ' ';
    cout << endl;

    IsLarge<int> is_large(27);
    vector<int> v2 = {1, 2, 8, 3, 2, 27, 8};
    auto itr = my::find_if(v2.begin(), v2.end(), is_large);
    cout << *itr << endl;

    list<int> ls = {1, 2, 3};
    append(5, 10, ls);
    for (int n : ls) cout << n << ' ';
    cout << endl;

    map<string, PeopleEntry> m;
    ifstream in2("people.txt");
    string name;
    while (getline(in2, name))
    {
        int age;
        string state;
        in2 >> age;
        in2 >> state;
        m[name] = PeopleEntry(age, state);
        in2.get();
    }
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        cout << itr->first << endl << itr->second.age << endl << itr->second.state << endl;
    }

    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second.age < 18)
            cout << itr->first << endl;
    }

    string line;
    cin >> line;
    int test = 0;
    int flag = 0;
    istringstream iss_line(line);
    while (iss_line >> test)
        if (!iss_line >> test)
            flag = 1;
    if (flag == 0 && line.size() == 3)
    {
        cout << "Contains 3 ints and nothing else.";
    }

    return 0;
}
