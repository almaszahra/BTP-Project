#include <iostream>
#include <iomanip>
using std::istream; using std::cin;
using std::ostream; using std::setw; using std::setfill; using std::cout; using std::endl;
void print(const char* message);
bool read();
bool read(int&, int&, int&);
void print(const char* message)
{
	cout << message;
}

void print(int, int, int);

void print(int year, int month, int day)
{
	
	cout << year << "/" << setw(2) << setfill('0')  << month << "/" << setw(2) << day;
}

void print(int, int, int, bool);
void print(int year, int month, int day, bool error)
{
	if (!error)
	{
		cout << "(";
		print(year, month, day);
		cout << ")" << endl;
	}
	else
	{
		print(year, month, day);
	}
}

bool read(int& year, int& month, int& day)
{

	cin >> year;
	if (cin.fail())
	{
		print("Cannot read year");
		cin.clear();
		cin.ignore(1, '\n');
		return false;
	}
	cin.ignore(1, '\n');

	cin >> month;
	if (cin.fail())
	{
		print("Cannot read month");
		cin.clear();
		cin.ignore(1, '\n');
		return false;
	}
	cin.ignore(1, '\n');

	cin >> day;
	if (cin.fail())
	{
		print("Cannot read day");
		cin.clear();
		cin.ignore(1, '\n');
		return false;
	}
	cin.ignore(1, '\n');
	return true;
}

int main()
{
	print("Please enter your birthday - YYYY/MM/DD");
	int year = 0;
	int month = 0;
	int day = 0;
	bool good = read(year, month, day);

	print(year, month, day, good);
	
	return 0;
}