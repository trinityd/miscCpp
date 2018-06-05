// Buffer.h

#include <vector>
#include <string>


class Buffer
{
public:
    void display();
    const std::string & get_file_name() const { return file_name; }
    void move_to_next_page();
    void move_to_previous_page();
    bool open(const std::string & file_name);
    void set_window_height(int h) { window_height = h; }
    void set_max_line_length(int m) { max_line_length = m; }
    std::string go_to_anchor(int a);
    void set_anchors(std::vector<std::string> a) { v_anchors = a; }
    void push_back_v_file_names(std::string fn) { v_file_names_.push_back(fn); }
    void pop_back_v_file_names() { v_file_names_.pop_back(); }
    std::vector<std::string> v_file_names() { return v_file_names_; }

private:
    std::vector<std::string> v_lines;
    std::vector<std::string> v_anchors;
    std::vector<std::string> v_file_names_;
    int ix_top_line = 0;
    std::string file_name;
    int window_height;
    int max_line_length;
};

inline void Buffer::move_to_next_page()
{
    if (ix_top_line + window_height < v_lines.size())
        ix_top_line += window_height;
}

inline void Buffer::move_to_previous_page()
{
    if (ix_top_line > 0) ix_top_line -= window_height;
}

