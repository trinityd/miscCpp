#include "String.h"
#include <iostream>
using std::cout;

int main()
{
    char * cs = "hello mars";
    String s(cs);
    for (int i = 0; i < s.length(); i++) cout << s[i];
    cout << '\n';
    cout << s.length() << '\n';

    String s2(" goodbye earth");
    for (int i = 0; i < s2.length(); i++) cout << s2[i];
    cout << '\n';
    s = (s + s2);
    for (int i = 0; i < s.length(); i++) cout << s[i];
    cout << '\n';

    s = s.replace(0, 10, "hello moon");
    for (int i = 0; i < s.length(); i++) cout << s[i];
    cout << '\n';

    s.clear();
    for (int i = 0; i < s.length(); i++) cout << s[i];
    cout << '\n';

    return 0;
}
