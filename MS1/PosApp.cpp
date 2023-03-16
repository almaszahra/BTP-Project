//PosApp.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "PosApp.h"

namespace sdds
{
	void PosApp::display() const
	{
		std::cout << "The Sene-Store" << std::endl << "1- List items" << std::endl << "2- Add item" << std::endl << "3- Remove item" << std::endl << "4- Stock item" << std::endl << "5- Point of Sale" << std::endl << "0- exit program" << std::endl;
		std::cout << "> ";
	}

	int PosApp::read() const
	{
		int value;
		bool stop = true;

		do
		{
			std::cin >> value;
			//check for invalid character
			if (std::cin.fail())
			{
				std::cerr << "Invalid Integer, try again: ";
				std::cin.clear();
				std::cin.ignore(2000, '\n');
			}
			else if (value > 5 || value < 0)
			{
				std::cerr << "[0<=value<=5], retry: ";
				std::cin.ignore(2000, '\n');
				std::cout << "> ";
			}
			else
			{
				stop = false;
			}
		} while (stop);
		return value;
	}

	void PosApp::menu() const
	{
		int value;
		bool restart = true;
		do
		{
			display();
			value = read();
			switch (value)
			{
			case 1:
				std::cout << ">>>> Listing Items..........................................................." << std::endl;
				listItems();
				break;
			case 2:

				std::cout << ">>>> Adding Item to the store................................................" << std::endl;
				addItem();
				break;
			case 3:
				std::cout << ">>>> Remove Item............................................................." << std::endl;
				removeItem();
				break;
			case 4:
				std::cout << ">>>> Select an item to stock................................................." << std::endl;
				stockItem();
				break;
			case 5:
				std::cout << ">>>> Starting Point of Sale.................................................." << std::endl;
				POS();
				break;
			case 0:
				saveRecs();
				restart = false;
				break;
			default:
				std::cout << "In Switch..." << std::endl;
				break;
			}
		} while (restart);
		std::cout << "Goodbye!" << std::endl;;
	}
	void PosApp::addItem() const
	{
		std::cout << "Running addItem()" << std::endl;
	}

	void PosApp::removeItem() const
	{
		std::cout << "Running removeItem()" << std::endl;
	}

	void PosApp::stockItem() const
	{
		std::cout << "Running stockItem()" << std::endl;
	}

	void PosApp::listItems() const
	{
		std::cout << "Running listItems()" << std::endl;
	}

	void PosApp::POS() const
	{
		std::cout << "Running POS()" << std::endl;
	}

	void PosApp::saveRecs() const
	{
		std::cout << ">>>> Saving Data............................................................." << std::endl;
		std::cout << "Saving data in " << m_filename << std::endl;
	}

	void PosApp::loadRecs() const
	{
		std::cout << ">>>> Loading Items..........................................................." << std::endl;
		std::cout << "Loading data from " << m_filename << std::endl;
	}

	PosApp::PosApp(const char* filename)
	{
		strcpy(m_filename, filename);
	}

	void PosApp::run() const
	{
		loadRecs();
		menu();
	}
	


}