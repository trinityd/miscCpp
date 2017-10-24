#include "RegistrationBookList.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

bool RegistrationBookList::read_file(const std::string & file_name) {
    m_entries.clear();
    ifstream ifs(file_name);
    if (!ifs) return false;
    ifs >> season_year_;
    int num_entries;
    ifs >> num_entries;
    ifs.get(); // \n
    for (int i = 0; i < num_entries; i++) {
        RegistrationBookEntry NewEntry;
        NewEntry.season_year_ = season_year();
        ifs >> NewEntry;
        add(NewEntry);
    }
    itr_current_entry = m_entries.begin();
    return true;
}

bool RegistrationBookList::write_file(const std::string & file_name) const {
    ofstream ofs(file_name);
    if (!ofs) return false;

    ofs << season_year_ << std::endl;
    ofs << m_entries.size() << std::endl;
    for (auto e : m_entries) {
        ofs << e.second;
    }
}

bool RegistrationBookList::write_cat(const std::string & category, const std::string & file_name) const {
    ofstream ofs(file_name);
    if (!ofs) return false;
    int amt = 0;
    for (auto e : m_entries) {
        if (e.second.category_.compare(category) == 0) amt++;
    }
    ofs << amt << std::endl;
    for (auto e : m_entries) {
        if (e.second.category_.compare(category) == 0) ofs << e.second;
    }
    return true;
}
