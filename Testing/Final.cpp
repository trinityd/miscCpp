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

template <class T>
int occurs(const T a[], int start, int stop, const T & e)
{
    if(start < stop)
    {
        int c = occurs(a, start+1, stop, e);
        if (a[start] == e)
        {
            return c + 1;
        }
        else {
            return c;
        }
    }
    else {
        return 0;
    }
}

template <class T>
int maxin(const T a[], int start, int stop)
{
    if (start < stop)
    {
        const T & m = maxin(a, start+1, stop);
        if (a[start] > m)
        {
            return a[start];
        }
        else
        {
            return m;
        }
    }
    else {
        return a[start];
    }
}

void printrec(int n)
{
    if (n > 1)
    {
        cout << n << ' ';
        printrec(n-1);
        cout << n << ' ';
    }
    else if (n == 1)
    {
        cout << 1 << ' ';
    }
}

template <class T>
int binary_search(const T a[], int start, int stop, const T & e)
{
    while (stop - start >= 2)
    {
        int middle = (start+stop)/2;
        if (e < a[middle])
        {
            stop = middle;
        }
        else {
            start = middle;
        }
    }
    if (stop - start == 1)
    {
        if (e == a[start]) return start;
        else return -1;
    }
    return -1;
}

int main()
{
    int a[] = {1, 14, 3, 4, 3, 7};

    int o = occurs(a, 0, 6, 3);
    cout << o << endl;

    int m = maxin(a, 0, 5);
    cout << m << endl;

    printrec(5);
    cout << endl;

    int sa[] = {10, 20, 30, 40, 50, 60};
    int l = binary_search(sa, 0, 5, 30);
    cout << l << endl;

    return 0;
}
