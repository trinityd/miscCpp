#ifndef _run_song_s_
#define _run_song_s_

#include <string>

class SongError {
public:
    SongError(const std::string & d) : description_(d) {}
    const std::string & what() const { return description_; }
private:
    std::string description_;
};

void run_song();

#endif
