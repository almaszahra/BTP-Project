#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
namespace sdds
{
	using std::istream;
	void delAlloCopy(char*& des, const char* src);
	char* dynRead(istream& istr, char delimeter);


}
#endif // !SDDS_UTILS_H

