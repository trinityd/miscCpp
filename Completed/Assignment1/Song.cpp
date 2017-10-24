#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

struct Song
{
    string title;
    string artist;
};

void initialize(Song & s)
{
    s.title = "invalid";
    s.artist = "none";
}

void initialize(Song & s, const string t, const string a)
{
    s.title = t;
    s.artist = a;
}

void print(const Song & s, ostream & out)
{
    out << s.title << "\n";
    out << s.artist << "\n";
}

void read(Song & s, istream & in)
{
    getline(in, s.title);
    getline(in, s.artist);
}

bool is_equal(const Song s1, const Song s2)
{
    return ((s1.title == s2.title) && (s1.artist == s2.artist));
}

int main()
{
    Song s;
    initialize(s);
    print(s, cout);

    initialize(s, "Lean on Me", "Bill Withers");
    print(s, cout);

    read(s, cin);
    print(s, cout);

    Song s2;
    initialize(s2, "California Girls", "Katy Perry");

    if(is_equal(s, s2)) {
        cout << "The song you entered was California Girls by Katy Perry.";
    }
    else {
        cout << "The song you entered was not California Girls by Katy Perry.";
    }
}
