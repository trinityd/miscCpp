// Pay calculator
// Version 2
//
// New in this version: Data abstraction is enforced by making
// Time's data private.

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iomanip>
using std::fixed;
using std::setprecision;
#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
#include <string>
using std::string;

class Time
{
    friend void initialize(Time & t);
    friend void read(Time & t, istream & in);
    friend void print(const Time & t, ostream & out);
    friend double difference(const Time & t1, const Time & t2);

private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
};

void initialize(Time & t)
{
    t.year = 9999;
    t.month = t.day = t.hours = t.minutes = 99;
}

void read(Time & t, istream & in)
{
    in >> t.year;
    in.get(); // dash
    in >> t.month;
    in.get(); // dash
    in >> t.day;
    in.get(); // dash
    in >> t.hours;
    in.get(); // colon
    in >> t.minutes;
}

void print(const Time & t, ostream & out)
{
    out << t.hours << ':';
    if (t.minutes < 10) out << 0;
    out << t.minutes;
}

double difference(const Time & t1, const Time & t2)
{
    return (t1.year*8640.0 + t1.month*720.0 + t1.day*24.0 + t1.hours + t1.minutes/60.0) -
        (t2.year*8640.0 + t2.month*720.0 + t2.day*24.0 + t2.hours + t2.minutes/60.0);
}

int main()
{
    cout << "Name of input file: ";
    string input_file_name;
    getline(cin, input_file_name);

    ifstream ifs_input(input_file_name);
    if (!ifs_input) {
        cout << "Could not open file.\n";
        return 1;
    }

    ifstream wages("wages.txt");

    cout << "Name of output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ofstream ofs_output(output_file_name);
    if (!ofs_output) {
        cout << "Could not open output file.\n";
        return 1;
    }

    int employee_number;
    while (ifs_input >> employee_number) {
        int n;
        ifs_input >> n;
        double total_hours = 0;
        for (int i = 0; i < n; i++)
        {
            Time start_time;
            read(start_time, ifs_input);

            Time stop_time;
            read(stop_time, ifs_input);

            total_hours += difference(stop_time, start_time);
        }

        double pay_rate;
        wages.ignore(256, ' ');
        wages >> pay_rate;

        double pay = total_hours * pay_rate;

        ofs_output << employee_number << ' ';
        ofs_output << fixed << setprecision(2) << total_hours;
        ofs_output << " $" << pay << '\n';
    }

    return 0;
}
