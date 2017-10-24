// Buffer.cpp
// formatting: cout << std::setw(6) << i+1 << "  "

#include "Buffer.h"

#include <fstream>
#include <iomanip>
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
#include <algorithm>

namespace my
{
template <typename T>
string to_string(T value)
{
    std::ostringstream os;
	os << value;
	return os.str();
}
}

void Buffer::display()
{
    int ix_stop_line = ix_top_line + window_height;
    for (int i = ix_top_line; i < ix_stop_line; i++)
    {
        if (i < v_lines.size())
            cout << std::setw(6) << i+1 << "  " << v_lines[i];
        cout << '\n';
    }
}

bool Buffer::open(const string & new_file_name)
{
    std::ifstream file(new_file_name);
    if (!file) return false;
    v_lines.clear();
    // Note: the vector is cleared only after we know the file
    // opened successfully.

    string line;
    while (getline(file, line)) v_lines.push_back(line);


    file_name = new_file_name;
    ix_top_line = 0;

    vector<string> temp_anchors;
    int anchor_count = 1;
    int anchor_loc;
    string s_all_text = "";
    vector<string> v_form_text;
    string full_line = " ";
    string full_line2 = "";

    for (int i = 0; i < max_line_length-2; i++)
    {
        full_line += "_";
        full_line2 += "_";
    }
    full_line += " ";
    full_line2 += " ";

    for (int i = 0; i < v_lines.size(); i++)
    {
        if (v_lines[i].find("<a ") != std::string::npos)
        {
            string temp = "";
            anchor_loc = v_lines[i].find("<a ");
            int j = anchor_loc + 3;
            while(!(isspace(v_lines[i][j]))) // adds filename
            {
                temp += my::to_string(v_lines[i][j]);
                j++;
            }
            j++;
            temp += " <<";
            while((v_lines[i][j]) != '>') // adds formatted anchor
            {
                temp += my::to_string(v_lines[i][j]);
                j++;
            }
            temp += ">>[";
            temp += my::to_string(anchor_count);
            temp += "]";
            temp_anchors.push_back(temp);
            anchor_count++;
        }
        else
        {
            temp_anchors.push_back("");
        }
        if (v_lines[i].size() == 0)
        {
            s_all_text += full_line;
        }
        else if (temp_anchors[i].find("<<") == std::string::npos)
        {
            s_all_text += v_lines[i];
        }
        else
        {
            for (int l = 0; l < v_lines[i].find("<a "); l++)
            {
                s_all_text += v_lines[i][l];
            }
            for (int l = temp_anchors[i].find("<<"); l < temp_anchors[i].size(); l++)
            {
                s_all_text += temp_anchors[i][l];
            }
            for (int l = v_lines[i].find(">")+1; l < v_lines[i].size(); l++)
            {
                s_all_text += v_lines[i][l];
            }
        }
    }
    set_anchors(temp_anchors);

    for (int i = s_all_text.size()-1; i >= 0; i--)
    {
        if (isspace(s_all_text[i]) && isspace(s_all_text[i+1])) s_all_text.erase(s_all_text.begin()+i+1);
    }
    while (s_all_text.size() >= max_line_length)
    {
        string search_area = s_all_text.substr(0, max_line_length+1);
        int loc = search_area.rfind(" ");
        v_form_text.push_back(s_all_text.substr(0, loc+1));
        s_all_text.erase(s_all_text.begin(), s_all_text.begin()+loc+1);
        if (s_all_text.substr(0, full_line2.size()) == full_line2)
        {
            v_form_text.push_back(" ");
            s_all_text.erase(s_all_text.begin(), s_all_text.begin()+full_line2.size());
        }
    }
    v_form_text.push_back(s_all_text);

    if (v_form_text.size() == 1 && v_form_text[0] == "") v_form_text.clear();

    v_lines = v_form_text;
    return true;
}

string Buffer::go_to_anchor(int a)
{
    string anchor_file;
    int anchor_count = 0;
    for(int i = 0; i < v_anchors.size(); i++)
    {
        if(v_anchors[i] != "") anchor_count++;
        if(anchor_count == a)
        {
            anchor_file = v_anchors[i].substr(0, v_anchors[i].find("<<")-1);
            break;
        }
    }
    return anchor_file;
}
