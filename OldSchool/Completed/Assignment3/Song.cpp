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

class Song
{
public:
    Song() : Song("invalid", "none") {}
    Song(string title) : Song(title, "unknown") {}
    Song(string title, string artist) : title_(title), artist_(artist) {}

    const string& title() { return title_; }
    const string& artist() { return artist_; }

    void print(ostream & out);
    void read(istream & in);

    const bool is_equal(const Song song2) { return ((title_ == song2.title_) && (artist_ == song2.artist_)); }

private:
    string title_;
    string artist_;
};

inline void Song::print(ostream & out)
{
    out << title_ << "\n";
    out << artist_ << "\n";
}

inline void Song::read(istream & in)
{
    getline(in, title_);
    getline(in, artist_);
}

int main()
{
    Song s;
    s.print(cout);

    Song s1("Still D.R.E.");
    s1.print(cout);

    Song s2("California Girls", "Katy Perry");
    s2.print(cout);

    cout << s2.title() << " by " << s2.artist() << ". Great choice.\n";

    Song s3;
    s3.read(cin);
    s3.print(cout);

    if(s3.is_equal(s2)) {
        cout << "The song you entered was California Girls by Katy Perry.";
    }
    else {
        cout << "The song you entered was not California Girls by Katy Perry.";
    }
}
