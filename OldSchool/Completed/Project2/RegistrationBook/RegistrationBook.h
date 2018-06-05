#ifndef _RegistrationBook_h_
#define _RegistrationBook_h_

#include <iostream>
#include <string>
#include <map>

#include "RegistrationBookList.h"

const std::string kcsFileName = "registrationbook.txt";

class RegistrationBook
{
public:
    RegistrationBook() : entry_list(kcsFileName) {}
    void run();

private:
    void display_entry_and_menu() const;
    void execute(char command, bool & done);

    RegistrationBookList entry_list;
};

inline void RegistrationBook::display_entry_and_menu() const {
    using std::cout;
    using std::endl;
    using std::string;

    string long_separator(50, '-');
    string short_separator(8, '-');

    entry_list.display_current_entry();

    cout << long_separator << endl
         << "  new_season   search   edit\n"
         << "  quit         add      category\n"
         << short_separator << endl;
}

#endif
