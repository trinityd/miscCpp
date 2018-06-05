// FileViewer.cpp

#include "FileViewer.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

void FileViewer::display()
{
    const string long_separator(50, '-');
    const string short_separator(8, '-');

    if (!error_message.empty()) {
        cout << "ERROR: " + error_message << endl;
        error_message.clear();
    }

    string file_name = buffer.get_file_name();
    if (file_name.empty())
        cout << "<no file opened>\n";
    else
        cout << file_name << endl;

    cout << long_separator << endl;
    buffer.display();
    cout << long_separator << endl;
    cout << "  next  previous  open  go  back  quit\n";
    cout << short_separator << endl;
}

void FileViewer::run()
{
    cout << "Window height? ";
    cin >> window_height;
    cin.get();  // '\n'
    cout << "Maximum line length? ";
    cin >> max_line_length;
    cin.get();  // '\n'
    cout << '\n';
    buffer.set_window_height(window_height);
    buffer.set_max_line_length(max_line_length);

    bool done = false;
    while (!done) {
        display();

        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // '\n'

        switch (command) {
            case 'n': {
                buffer.move_to_next_page();
                break;
             }

            case 'o': {
                cout << "file name: ";
                string file_name;
                getline(cin, file_name);
                if (!buffer.open(file_name))
                    error_message = "Could not open " + file_name;
                else
                    buffer.push_back_v_file_names(file_name);
            }

            case 'p': {
                buffer.move_to_previous_page();
                break;
            }

            case 'q': {
                done = true;
                break;
            }

            case 'g': {
                cout << "link number: ";
                int link_number;
                cin >> link_number;
                string file_name = buffer.go_to_anchor(link_number);
                if (!buffer.open(file_name))
                    error_message = "Could not open " + file_name;
                else
                    buffer.push_back_v_file_names(file_name);
                break;
            }

            case 'b': {
                buffer.pop_back_v_file_names();
                std::vector<string> temp_file_names = buffer.v_file_names();
                string last_file = temp_file_names[temp_file_names.size()-1];
                buffer.open(last_file);
                break;
            }
        };
        cout << endl;
    } // while

    return;
}


