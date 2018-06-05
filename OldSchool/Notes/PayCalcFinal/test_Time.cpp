// test-Time.cpp
//
// Pay calculator
// Version 1
//
// Test driver for the Time data type (and its operations)

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

// Time code goes here
struct Time { int hours, minutes; };

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
    in.get(); // colon
    in >> t.minutes;
}

void print(const Time & t, ostream & out)
{
    out << t.hours << ':';
    if (t.minutes < 10) out << '0';
    out << t.minutes;
}

double difference(const Time & t1, const Time & t2)
{
    return (t1.hours + t1.minutes/60.0) -
        (t2.hours + t2.minutes/60.0);
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
    Time t1, t2;
    initialize(t1, 20, 00);
    initialize(t2, 13, 37);
    cout << "Initial values: ";
    print( t1, cout );
    cout << ' ';
    print( t2, cout );
    cout << endl;

    while (true) {
        cout << "Enter two times: ";
        read( t1, cin );
        read( t2, cin );
        cout << "The difference between ";
        print( t1, cout );
        cout << " and ";
        print( t2, cout );
        cout << " is " << difference( t2, t1 ) << " hours\n";
        cout << "Time 1 is later than Time 2: " << is_later_than(t1, t2) << "\n";
        cout << "Add how much time to Time 1? ";
        add_minutes(t1, -301);
        cout << "\nNew Time 1: ";
        print(t1, cout);
        cout << "\n";
    }

    return 0;
}
