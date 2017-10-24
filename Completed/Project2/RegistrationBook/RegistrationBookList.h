#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "RegistrationBookEntry.h"

class RegistrationBookList
{
public:
    RegistrationBookList(const std::string & file_name0);

    void add(const std::string & name, const std::string & birthyear, const std::string & status);
    void add(const RegistrationBookEntry & NewEntry);
    void display_current_entry() const;
    void edit_current(const std::string & new_name, const std::string & new_birthyear, const std::string & new_status);
    bool find_player(const std::string & name);
    bool empty() const { return m_entries.empty(); }
    void clear_players() { m_entries.clear(); }
    bool read_file( const std::string & file_name );
    bool write_file( const std::string & file_name ) const;
    bool write_cat(const std::string & category, const std::string & file_name ) const;
    const std::string season_year() { return season_year_; }
    void set_season_year(std::string season_year0) { season_year_ = season_year0; }

private:
    std::map<std::string, RegistrationBookEntry> m_entries;
    std::string season_year_;
    std::map<std::string, RegistrationBookEntry>::iterator itr_current_entry;
};
inline RegistrationBookList::RegistrationBookList(const std::string & file_name0) {
    read_file(file_name0);
}

inline void RegistrationBookList::add(const std::string & name, const std::string & birthyear, const std::string & status) {
    RegistrationBookEntry NewEntry(name, birthyear, status, season_year_);
    auto result = m_entries.insert({name, NewEntry});
    itr_current_entry = result.first;
}

inline void RegistrationBookList::add(const RegistrationBookEntry & NewEntry) {
    auto result = m_entries.insert({NewEntry.name, NewEntry});
    itr_current_entry = result.first;
}

inline void RegistrationBookList::display_current_entry() const {
    if (m_entries.empty()) return;
    std::cout << itr_current_entry->second;
}

inline void RegistrationBookList::edit_current(const std::string & new_name, const std::string & new_birthyear, const std::string & new_status) {
    RegistrationBookEntry EditedEntry(new_name, new_birthyear, new_status, season_year_);
    m_entries.erase(itr_current_entry);
    add(EditedEntry);
}

inline bool RegistrationBookList::find_player(const std::string & name)
{
    auto found = m_entries.find(name);
    if (found != m_entries.end()) {
        itr_current_entry = found;
        return true;
    }
    return false;
}
