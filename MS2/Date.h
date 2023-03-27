/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "POS.h"
#include "Error.h"
#include "Utils.h"
namespace sdds
{
	using std::ostream;
	using std::istream;
	using std::endl;
	
	class Date
	{
		int m_year = 0;
		int m_month = 0;
		int m_day = 0;
		int m_hour = 0;
		int m_min = 0;
		bool m_dateOnly = false;
		sdds::Error m_err;
		Date& validate(Date&);
	public:
		inline Date() { getSystemDate(m_year, m_month, m_day, m_hour, m_min, m_dateOnly); }

		inline Date(int year, int month, int day) :m_year(year), m_month(month), m_day(day), m_hour(0), m_min(0), m_dateOnly(true){validate(*this); }

		inline Date(int year, int month, int day, int hour, int min = 0) : m_year(year), m_month(month), m_day(day), m_hour(hour), m_min(min), m_dateOnly(false) { validate(*this); }

		

		bool operator==(const Date& right) const;
		bool operator!=(const Date& right) const;
		bool operator>(const Date& right) const;
		bool operator<(const Date& right) const;
		bool operator>=(const Date& right) const;
		bool operator<=(const Date& right) const;

		inline Date& dateOnly(bool dateOnly)
		{
			m_dateOnly = dateOnly;
			if (m_dateOnly) {
				m_hour = 0;
				m_min = 0;
			}
			return *this;
		}

		inline operator bool() const
		{
			return !bool(m_err);
		}

		inline const char* error() const { return m_err.getError(); }
		ostream& display(ostream&) const;
		istream& read(istream&);
	};

	inline ostream& operator<<(ostream& os, const Date& date){ date.display(os); return os; }
	inline istream& operator>>(istream& in, Date& date) { date.read(in); return in; }
	
}
#endif // !SDDS_DATE_H