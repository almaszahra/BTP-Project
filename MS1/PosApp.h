#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
const int cstrlen = 255;
namespace sdds
{
	class PosApp
	{
		char m_filename[cstrlen + 1];
	public:
		//* - const until further functionality is added
		//** - not sure what it does yet
		//default constructor;
		PosApp() {};
		//create object using filename
		PosApp(const char* filename);
		//prevent copying
		PosApp(PosApp&) = delete;
		PosApp& operator=(PosApp&) = delete;
		//print menu and receive users choice
		void menu(std::istream & = std::cin, std::ostream & = std::cout);
		//adds an item to the pos List
		void addItem() const; //*
		//removes an item from the pos list
		void removeItem() const; //*
		//adjusts the stock of the item
		void stockItem() const; //*
		//**
		void POS() const; //*
		//**
		void saveRecs();
		//**
		void loadRecs();
	};
}
#endif // !SDDS_POSAPP_H

