#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

#include <cstring>

#include <string>
using std::string;

void print_double_spaced(const char cs[])
{
    for (int i = 0; cs[i] != '\0'; i++)
    {
        if (cs[i+1] != ' ' && cs[i+1] != '\0') cout << cs[i] << ' ';
        else cout << cs[i];
    }
}

int count_lines(const char file_name[], const char s[])
{
    int r = 0;
    string c;

    ifstream ifs_input(file_name);

    while (ifs_input >> c)
    {
        if (!(c.find(s) == string::npos)) r++;
    }

    return r;
}

int main()
{
    char cs[30] = "";
    print_double_spaced(cs);
    cout << "\n";
    char cs1[30] = "q";
    print_double_spaced(cs1);
    cout << "\n";
    char cs2[30] = "hello world";
    print_double_spaced(cs2);
    cout << "\n";

    char fn[30] = "cstringinput.txt";
    char s[30] = "bob";
    cout << count_lines(fn, s);
}
