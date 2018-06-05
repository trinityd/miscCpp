#ifndef _Song_s_
#define _Song_s_

#include <iostream>

class Song
{
public:
    friend std::ostream & operator<<(std::ostream & out, const Song & s);
    friend std::istream & operator>>(std::istream & in, Song & s);
    friend bool operator==(const Song s1, const Song s2);

    Song() : Song("invalid", "none") {}
    Song(std::string title) : Song(title, "unknown") {}
    Song(std::string title, std::string artist) : title_(title), artist_(artist) {}

    std::string title() const { return title_; }
    std::string artist() const { return artist_; }

    void set(std::string title, std::string artist);

private:
    std::string title_;
    std::string artist_;
};

inline std::ostream & operator<<(std::ostream & out, const Song & s)
{
    out << s.title_ << "\n";
    out << s.artist_ << "\n";
    return out;
}

inline std::istream & operator>>(std::istream & in, Song & s)
{
    getline(in, s.title_);
    getline(in, s.artist_);
    return in;
}

inline bool operator==(const Song s1, const Song s2)
{
    return ((s1.title_ == s2.title_) && (s1.artist_ == s2.artist_));
}

inline void Song::set(const std::string title, const std::string artist)
{
    title_ = title;
    artist_ = artist;
}

#endif // _Song_s_
