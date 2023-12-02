/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/



#include "Date.h"
#include <iomanip>
using std::ostream; using std::cout; using std::istream;  using std::endl;
namespace sdds
{


	Date& Date::validate(Date& date)
	{
		if (date.m_year > MAX_YEAR || MIN_YEAR > date.m_year)
		{
			m_err = "Invalid Year";

		}
		else if (date.m_month > 12 || 1 > date.m_month)
		{
			m_err = "Invalid Month";

		}
		else if (date.m_day > daysOfMonth(m_year, m_month) || 1 > date.m_day)
		{
			m_err = "Invalid Day";
		}
		if (!date.m_dateOnly)
		{
			if (date.m_hour > 23 || 0 > date.m_hour)
			{

				m_err = "Invalid Hour";

			}
			else if (date.m_min > 59 || 0 > date.m_min)
			{
				m_err = "Invlid Minute";
			}
			return *this;
		}
		else
		{
			return *this;
		}
	}

	ostream& Date::display(ostream& os) const
	{
		using std::setw; using std::setfill;
		if (*this)
		{
			if (m_dateOnly)
			{
				os << setfill('0') << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day;
			}
			else
			{
				os << setfill('0') << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day << ", " << setw(2) << m_hour << ":" << setw(2) << m_min ;
			}
		}
		else
		{
			if (m_dateOnly)
			{
				os << setfill('0') <<  m_err.getError() << "(" << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day << ")";
			}
			else
			{
				os << setfill('0') << m_err.getError() << "(" << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day << ", " << setw(2) << m_hour << ":" << setw(2) << m_min << ")";
			}
		}
		return os;
	}



	istream& Date::read(istream& in)
	{
		
		in >> m_year;
		if (in.fail())
		{
			in.clear();
			in.ignore(1, '\n');
			Date A(0, 0, 0, 0, 0);
			*this = A;
			m_err = "Cannot read year entry";
			return in;
		}
		in.ignore(1, '\n');

		in >> m_month;
		if (in.fail())
		{

			in.clear();
			in.ignore(1, '\n');
			Date A(m_year, 0, 0, 0, 0);
			*this = A;
			m_err = "Cannot read month entry";
			return in;
		}
		in.ignore(1, '\n');

		in >> m_day;
		if (in.fail())
		{
			in.clear();
			in.ignore(1, '\n');
			Date A(m_year, m_month, 0, 0, 0);
			*this = A;
			m_err = "Cannot read day entry";
			return in;
		}

		if (!m_dateOnly)
		{
			in.ignore(1, '\n');
			in >> m_hour;
			if (in.fail())
			{
				in.clear();
				in.ignore(1, '\n');
				Date A(m_year, m_month, m_day, 0, 0);
				*this = A;
				m_err = "Cannot read hour entry";
				return in;
			}
			in.ignore(1, '\n');
			in >> m_min;
			if (in.fail())
			{
				in.clear();
				in.ignore(1, '\n');
				Date A(m_year, m_month, m_day, m_hour);
				*this = A;
				m_err = "Cannot read minute entry";
				return in;
			}
		}
		validate(*this);
		return in;
	}

	bool Date::operator==(const Date& right) const
	{

		return (m_year == right.m_year && m_month == right.m_month && m_day == right.m_day && m_hour == right.m_hour && m_min == right.m_min);
	}

	bool Date::operator!=(const Date& right) const
	{
		return m_year != right.m_year || m_month != right.m_month || m_day != right.m_day || m_hour != right.m_hour || m_min != right.m_min;
	}

	bool Date::operator>(const Date& right) const
	{
		if (m_year > right.m_year)
		{
			return true;
		}
		else if (m_year == right.m_year)
		{
			if (m_month > right.m_month)
			{
				return true;
			}
			else if (m_month == right.m_month)
			{
				if (m_day > right.m_day)
				{
					return true;
				}
				else if (m_day == right.m_day)
				{
					if (m_hour > right.m_hour)
					{
						return true;
					}
					else if (m_hour == right.m_hour)
					{
						if (m_min > right.m_min)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}

	bool Date::operator<(const Date& right) const
	{
		if (m_year < right.m_year)
		{
			return true;
		}
		else if (m_year == right.m_year)
		{
			if (m_month < right.m_month)
			{
				return true;
			}
			else if (m_month == right.m_month)
			{
				if (m_day < right.m_day)
				{
					return true;
				}
				else if (m_day == right.m_day)
				{
					if (m_hour < right.m_hour)
					{
						return true;
					}
					else if (m_hour == right.m_hour)
					{
						if (m_min < right.m_min)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}

	bool Date::operator>=(const Date& right) const
	{
		if (m_year > right.m_year)
		{
			return true;
		}
		else if (m_year == right.m_year)
		{
			if (m_month > right.m_month)
			{
				return true;
			}
			else if (m_month == right.m_month)
			{
				if (m_day > right.m_day)
				{
					return true;
				}
				else if (m_day == right.m_day)
				{
					if (m_hour > right.m_hour)
					{
						return true;
					}
					else if (m_hour == right.m_hour)
					{
						if (m_min > right.m_min)
						{
							return true;
						}
						else if (m_min == right.m_min)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(const Date& right) const
	{
		if (m_year < right.m_year)
		{
			return true;
		}
		else if (m_year == right.m_year)
		{
			if (m_month < right.m_month)
			{
				return true;
			}
			else if (m_month == right.m_month)
			{
				if (m_day < right.m_day)
				{
					return true;
				}
				else if (m_day == right.m_day)
				{
					if (m_hour < right.m_hour)
					{
						return true;
					}
					else if (m_hour == right.m_hour)
					{
						if (m_min <= right.m_min)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}

}