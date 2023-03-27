/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/
#include "Error.h"
namespace sdds
{
    Error& Error::operator=(const Error& err)
    {
        bool same = this != &err;
        if (same)
        {
            delete[] m_err;
            if (err.m_err != nullptr)
            {
                m_err = new char[std::strlen(err.m_err) + 1];
                std::strcpy(m_err, err.m_err);
            }
            else
            {
                m_err = nullptr;
            }

        }
        return *this;

    }
}


