#ifndef _RegistrationBookEntry_h_
#define _RegistrationBookEntry_h_

#include <fstream>
#include <string>
#include <sstream>

template <typename T>
T StringToNumber (const std::string & text)
{
    std::istringstream ss(text);
    T result;
    return ss >> result ? result : 0;
}

template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

class RegistrationBookEntry
{
public:
    friend std::istream & operator>>(std::istream & in, RegistrationBookEntry & e);
    friend std::ostream & operator<<(std::ostream & out, const RegistrationBookEntry & e);

    RegistrationBookEntry() : name("no name"), birthyear("no year of birth"), category_("no category"), status("no status"), season_year_("no season") {}
    RegistrationBookEntry(const std::string & name0, const std::string & birthyear0, const std::string & status0, const std::string & season_year0);

    std::string category(int season_year, int birthyear);


    std::string name;
    std::string birthyear;
    std::string category_;
    std::string status;
    std::string season_year_;
};

// error checking has already been performed
inline RegistrationBookEntry::RegistrationBookEntry(const std::string & name0, const std::string & birthyear0, const std::string & status0, const std::string & season_year0) {
    name = name0;
    birthyear = birthyear0;
    status = status0;
    season_year_ = season_year0;
    category_ = category(StringToNumber<int>(season_year_), StringToNumber<int>(birthyear));
}

inline std::string RegistrationBookEntry::category(int season_year, int birthyear)
{
    int age = season_year-birthyear;
    if (age < 6) {
        return "U6";
    } else if (age < 8) {
        return "U8";
    } else if (age < 10) {
        return "U10";
    } else if (age < 12) {
        return "U12";
    } else if (age < 14) {
        return "U14";
    } else {
        return "U17";
    }
}

inline std::istream & operator>>(std::istream & in, RegistrationBookEntry & e) {
    getline(in, e.name);
    getline(in, e.birthyear);
    std::string dummy_cat;
    getline(in, dummy_cat);
    getline(in, e.status);
    e.category_ = e.category(StringToNumber<int>(e.season_year_), StringToNumber<int>(e.birthyear));
//    std::cout << e.season_year_ << ":" << e.category_;
    return in;
}

inline std::ostream & operator<<(std::ostream & out, const RegistrationBookEntry & e) {
    out << e.name << std::endl << e.birthyear << std::endl << e.category_ << std::endl << e.status << std::endl;
    return out;
}

#endif
