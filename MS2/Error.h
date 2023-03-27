/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <cstring>
#include <iostream>
namespace sdds
{
	using std::ostream; using std::endl;
	class Error
	{
		char* m_err = nullptr;
	public:
		Error() = default;
		inline Error(const char* err)
		{
			m_err = new char[std::strlen(err) + 1]; std::strcpy(m_err, err);
		}
		inline Error(const Error& err) 
		{ 
			m_err = nullptr;
			*this = err;
		}
		Error& operator= (const Error& err);
		inline ~Error() { delete[] m_err; }

		inline Error& operator=(const char* err)
		{
			Error error(err);
			*this = error;
			return *this;
		}

		inline operator bool() const { return m_err != nullptr; }

		inline Error& clear()  { if (m_err != nullptr) { delete[] m_err; m_err = nullptr; } return *this; }
		inline const char* getError() const { return m_err; } 
		inline ostream& display(ostream& out) 
		{ 
			if (m_err == nullptr)
			{
				out << "";
				return out;
			}
			else
			{
				out << m_err; return out; }

			}
	};
	
	inline ostream& operator<<(ostream& out, Error& err) { err.display(out); return out; }
}
#endif // !SDDS_ERROR_H
