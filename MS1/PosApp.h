#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H


const int cstrlen = 255;
namespace sdds
{
	class PosApp
	{
		char m_filename[cstrlen + 1] = {};
		void menu() const;
		//adds an item to the pos List
		void addItem() const; //*
		//removes an item from the pos list
		void removeItem() const; //*
		//adjusts the stock of the item
		void stockItem() const; //*
		//lists all items
		void listItems() const;
		//**
		void POS() const; //*
		//**
		void saveRecs() const;
		//**
		void loadRecs() const;
		//calls utility display function
		void display() const;
		int read() const;
	public:
		//* - const until further functionality is added
		//** - not sure what it does yet
		//create object using filename
		PosApp(const char* filename = "datafile.csv");
		//prevent copying
		PosApp(PosApp&) = delete;
		PosApp& operator=(PosApp&) = delete;
		//print menu and receive users choice
		void run() const;
	};

	
}
#endif // !SDDS_POSAPP_H

