/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>
namespace sdds
{
	using std::istream; using std::ostream; using std::ifstream; using std::ofstream;
	class PosIO
	{
	public:

		virtual istream& read(istream& i) = 0;
		virtual ostream& write(ostream& o) const = 0;
		virtual ofstream& save(ofstream& of) const = 0;
		virtual ifstream& load(ifstream& fi) = 0;
		~PosIO() {};

	};
	inline ostream& operator<<(ostream& o, PosIO& p) { p.write(o); return o; }
	inline ofstream& operator<<(ofstream& of, PosIO& p) { p.save(of); return of; }
	inline istream& operator>>(istream& i, PosIO& p) { p.read(i); return i; }
	inline ifstream& operator>>(ifstream& fi, PosIO& p) { p.load(fi); return fi; }


}
#endif // !SDDS_POSIO_H
