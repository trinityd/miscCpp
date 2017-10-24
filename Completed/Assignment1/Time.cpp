#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <iomanip>
using std::fixed;
using std::setprecision;

//using namespace std;

struct Time
{
    int hours;
    int minutes;
};

const double kPayRate = 12;

void initialize(Time & t)
{
    t.hours = t.minutes = 99;
}

void initialize(Time & t, int h, int m)
{
    t.hours = h;
    t.minutes = m;
}

void read(Time & t, istream & in)
{
    in >> t.hours;
    in.get();
    in >> t.minutes;
}

void print(const Time & t, ostream & out)
{
    out << t.hours << ":";
    if (t.minutes < 10) out << 0;
    out << t.minutes;
}

double difference(const Time & t1, const Time & t2)
{
    return (t1.hours + t1.minutes/60.0)-(t2.hours + t2.minutes/60.0);
}

bool is_later_than(Time & t1, Time & t2)
{
    if (t1.hours + t1.minutes/60.0 > t2.hours + t2.minutes/60.0) {
        return true;
    }
    return false;
}

void add_minutes(Time & t, int num_minutes)
{
    int added_minutes = (t.hours * 60) + t.minutes + num_minutes;
    if (added_minutes < 0) {
        added_minutes = added_minutes * -1;
    }
    t.hours = added_minutes / 60;
    t.minutes = added_minutes % 60;
}

int main()
{
    //Let's test initialize(t, h, m).
    Time t;
    int h = 22;
    int m = 30;
    initialize(t, h, m);
    cout << "Initialized time: " << t.hours << ":";
    if (t.minutes > 9) {
        cout << t.minutes << "\n\n";
    }
    else {
        cout << 0 << t.minutes << "\n\n";
    }
    //End testing

    cout << "Name of input file: ";
    string input_file_name;
    getline(cin, input_file_name);

    ifstream ifs_input (input_file_name);
    if (!ifs_input) {
        cout << "Could not open file.\n";
        return 1;
    }

    cout << "Name of output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ofstream ofs_output (output_file_name);
    if (!ofs_output) {
        cout << "Could not open output file.\n";
        return 1;
    }

    int employee_number;
    while (ifs_input >> employee_number) {
        Time start_time;
        read(start_time, ifs_input);

        Time stop_time;
        read(stop_time, ifs_input);

        double pay = difference(stop_time, start_time) * kPayRate;

        ofs_output << employee_number << ' ';
        print(start_time, ofs_output);
        ofs_output << ' ';
        print(stop_time, ofs_output);
        ofs_output << " $" << fixed << setprecision(2) << pay << '\n';
    }

    return 0;
}
