#ifndef _String_h_
#define _String_h_

#include <cstring>
#include <algorithm>

class String
{
public:
    String() : buffer_(""), length_(0) {}
    String(const char * cs);

    ~String() { delete [] buffer_; }

    int length() const { return length_; }

    char & operator[](int i) { return buffer_[i]; }
    const char & operator[](int i) const { return buffer_[i]; }

    void clear();

    String operator+(const String & s);

    String & replace(int i, int m, const String & s2);

    const char * c_str() const { return buffer_; }

private:
    char * buffer_;
    int length_;
};

inline String::String(const char * cs)
{
    length_ = strlen(cs);
    buffer_ = new char[length_];
    strcpy(buffer_, cs);
}

inline void String::clear()
{
    length_ = 0;
    buffer_ = "";
}

inline String String::operator+(const String & s)
{
    int new_length = length_ + s.length();
    char * new_buffer = new char[new_length];
    strcpy(new_buffer, buffer_);
    strcat(new_buffer, s.c_str());
    String new_string(new_buffer);
    return new_string;
}

inline String & String::replace(int i, int m, const String & s2)
{
    int new_length = length_ - m + s2.length();
    char * new_buffer = new char[new_length];
    for (int n = 0; n < i; n++) new_buffer[n] = buffer_[n];
    strcat(new_buffer, s2.c_str());
    char * after_buffer = new char[length_-i-m];
    int c = 0;
    for (int n = m+i; n < length_; n++)
    {
        after_buffer[c] = buffer_[n];
        c++;
    }
    strcat(new_buffer, after_buffer);
    String s(new_buffer);
    return s;
}

#endif
