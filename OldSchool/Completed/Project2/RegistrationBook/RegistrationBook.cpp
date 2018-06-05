#include "RegistrationBook.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;
using std::pair;

#include <string>
using std::string;

void RegistrationBook::run()
{
    ifstream test_ifs;
    test_ifs.open(kcsFileName);
    if (test_ifs.fail())
    {
        cout << "error opening file. closing... " << endl;
        return;
    }
    bool done = false;
    do {
        display_entry_and_menu();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    } while (!done);
}

void RegistrationBook::execute(char command, bool & done)
{
    switch (command) {
        case 'n': {
            cout << "current year: ";
            int season_year;
            cin >> season_year;
            while (cin.fail()) {
                cout << endl << "not an int. current year: ";
                cin.clear();
                cin >> season_year;
            }
            entry_list.set_season_year(NumberToString(season_year));
            cout << "delete existing players? (y/n) ";
            char delete_season;
            cin >> delete_season;
            switch (delete_season)
            {
                case 'y' : {
                    ofstream ofs;
                    ofs.open(kcsFileName.c_str());
                    ofs.close();
                    entry_list.clear_players();
                    break;
                }
                case 'n' : {
                    entry_list.write_file(kcsFileName);
                    entry_list.read_file(kcsFileName);
                    break;
                }
            }
            break;
        }
        case 'e': {
            if (entry_list.empty()) return;
            cout << "new name: ";
            string new_name;
            getline(cin, new_name);
            cout << "new year of birth: ";
            string new_birthyear;
            getline(cin, new_birthyear);
            cout << "new registration status: " ;
            string new_status;
            getline(cin, new_status);
            entry_list.edit_current(new_name, new_birthyear, new_status);
            break;
        }
        case 's': {
            cout << "name: ";
            string name;
            getline(cin, name);
            if (!entry_list.find_player(name)) {
                cout << "player not found." << endl;
            }
            break;
        }
        case 'a': {
            cout << "new name: ";
            string new_name;
            getline(cin, new_name);
            cout << "new year of birth: ";
            string new_birthyear;
            getline(cin, new_birthyear);
            int age = (StringToNumber<int>(entry_list.season_year()) - StringToNumber<int>(new_birthyear));
            if (age > 17 || age < 4)
            {
                cout << "player is not eligible to play in the summer league. " << endl;
                break;
            }
            cout << "new registration status: ";
            string new_status;
            getline(cin, new_status);
            entry_list.add(new_name, new_birthyear, new_status);
            break;
        }
        case 'c': {
            cout << "category to generate a list of: ";
            string category;
            getline(cin, category);
            cout << "file name: ";
            string file_name;
            getline(cin, file_name);
            entry_list.write_cat(category, file_name);
            break;
        }
        case 'q': {
            entry_list.write_file(kcsFileName);
            done = true;
            break;
        }
    };
}
