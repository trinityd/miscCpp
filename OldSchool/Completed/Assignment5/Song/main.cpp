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
    try { run_song(); }

    catch (const SongError & e) {
        cout << "Song class could not complete (" << e.what() << ")\n";
    }
}
