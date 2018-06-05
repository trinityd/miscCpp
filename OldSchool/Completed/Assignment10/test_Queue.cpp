#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

#include "Queue.h"

template <typename T>
void println(Queue<T> & q)
{
    while(q.size() != 0)
    {
        int x = q.pop();
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    Queue<int> q;
    q.push(6);
    q.push(17);
    q.push(12);
    Queue<int> q2 = q;
    println(q);
    q = q2;
    cout << "Size: " << q.size() << '\n';
    cout << "Front: " << q.front() << '\n';
    int x = q.pop();
    cout << "Pop Returns: " << x << '\n' << "After-pop Front: " << q.front() << '\n';
    return 0;
}
