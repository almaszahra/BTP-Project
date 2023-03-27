/*
Joshua Dinham
121572226
BTP200NAA
All work completed by me
*/
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
namespace sdds
{
	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);

	int uniqueDateValue(int year, int mon, int day, int hour, int min);

	int daysOfMonth(int year, int month);
}