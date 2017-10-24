#include "run_song.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
//using std::to_string;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include "Song.h"


void run_song()
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
    if (cin.fail()) throw SongError("Either the title or artist was blank.");
    cout << s3;

    if(s2 == s3)
        throw SongError("ERROR: The song you entered was California Girls by Katy Perry. Be original.");

    cout << "Now to test initializing a blank Song.\n";
    Song sblank("","");
    cout << sblank;
}
