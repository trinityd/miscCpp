#include <iostream>
using std::cout;
using std::cin;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
using std::endl;
#include <cstring>
#include <map>
using std::map;

class BookEntry
{
public:
    BookEntry() : author("no author"), year(0) {}
    BookEntry(const string & author0, const int year0) : author(author0), year(year0) {}

    string author;
    int year;
};

int main()
{
    ifstream in("books.txt");
    map<string, BookEntry> m;
    string title;
    while (getline(in, title))
    {
        string author;
        getline(in, author);
        int year;
        in >> year;
        m[title] = BookEntry(author, year);
        in.get();
    }

    for (auto b : m)
    {
        if (b.second.year > 2005) cout << b.first << endl;
    }

    return 0;
}
