#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

#include <cstring>

class Product
{
public:
	friend istream & operator>>(istream & in, Product & p);
	friend bool operator <(const Product & p1, const Product & p2);

	Product() : Product(0, "none", -1) {}
	Product(int number, std::string description, double price) : number_ (number), description_(description), price_(price) {}

	double price() const { return price_; }

	void set_description(std::string new_description) { description_ = new_description; }

	void print() const { cout << number_ << ", " << description_ << ": $" << price_; }

private:
	int number_;
	std::string description_;
	double price_;
};

inline istream & operator>>(istream & in, Product & p)
{
	in >> p.number_;
	in.get();
	getline(in, p.description_);
	in >> p.price_;

	return in;
}

inline bool operator <(const Product & p1, const Product & p2)
{
	return (p1.number_ < p2.number_);
}

void strconcat(char dest[], char source[])
{
	int destSize = strlen(dest);
	int sourceSize = strlen(source);

	for (int i = 0; i < sourceSize; i++)
	{

		dest[i+destSize] = source[i];
	}
}

main()
{
    Product p;
    p.print();
    cout << "\n";
    cin >> p;
    p.print();
    cout << "\n";
    cout << "The price is " << p.price() << ".\n";

    Product p1(1, "20-ply Toilet Paper", 19.99);
    p1.print();
    cout << "\n";
    p1.set_description("New and Improved: 21-ply");
    p1.print();
    cout << "\n";

    if (p < p1)
    {
        cout << "The first has a smaller number.\n";
    }

    char str[80] = "these ";
    strconcat (str, "strings ");
    strconcat (str, "are ");
    strconcat (str, "concatenated.");
    cout << str;
    return 0;
}
