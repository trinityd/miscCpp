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

#include "Song.h"

int main()
{
    Song s;
    cout << s;

    Song s1("Still D.R.E.");
    cout << s1;

    s1.set("Don't Stop Believin'", "Journey");
    cout << s1;

    Song s2("California Girls", "Katy Perry");
    cout << s2;

    cout << s2.title() << " by " << s2.artist() << ". Great choice.\n";

    Song s3;
    cin >> s3;
    cout << s3;

    if(s2 == s3) {
        cout << "The song you entered was California Girls by Katy Perry.";
    }
    else {
        cout << "The song you entered was not California Girls by Katy Perry.";
    }
}
