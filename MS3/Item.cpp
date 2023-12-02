#include "Item.h"
#include <iomanip>
/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
using namespace sdds;
using std::cout; using std::endl;
using std::setw; using std::setfill; using std::setprecision; using std::right; using std::left; using std::string;
Item::Item(const Item& item)
{
	operator=(item);

}

Item& sdds::Item::operator=(const Item& item)
{
	if (this != &item)
	{
		sdds::delAlloCopy(m_name, item.m_name);
		std::strcpy(m_sku, item.m_sku);
		m_qty = item.m_qty;
		m_taxed = item.m_taxed;
		m_displayType = item.m_displayType;
		m_price = item.m_price;
		m_err = item.m_err;
	}

	return *this;

}

void sdds::Item::operator~()
{
	delete[] m_name;
	m_name = nullptr;
}

istream& sdds::Item::read(istream& i)
{

	~*this;
	bool stop = false;
	bool flag = false;
	char sku[MAX_SKU_LEN + 1]{};
	char name[MAX_NAME_LEN + 1]{};
	double price{};
	char taxed{};
	int qty{};
	while (!stop)
	{
		cout << "Sku" << endl << "> ";

		while (!flag) {
			i.get(sku, MAX_SKU_LEN +1,'\n');
			if (i.fail())
			{
				i.clear();
				i.ignore(2000, '\n');
			}
			else if (i.get() != '\n')
			{
				m_err = ERROR_POS_SKU;
				m_err.display(cout);
				i.ignore(2000, '\n');
				i.clear();
				cout << endl << "> ";
			}
			else
			{
				strcpy(m_sku, sku);
				i.clear();
				flag = true;
			}
		}
		flag = false;
		cout << "Name" << endl << "> ";
		while(!flag){

			i.get(name, MAX_NAME_LEN + 1);
			if (i.fail())
			{
				i.clear();
				i.ignore(2000, '\n');

			}
			else if (i.get() != '\n')
			{
				m_err = ERROR_POS_NAME;
				m_err.display(cout);
				i.ignore(2000, '\n');
				i.clear();
				cout << endl << "> ";
			}
			else
			{
				
				
				m_name = new char[MAX_NAME_LEN + 1];
				strcpy(m_name, name);
				flag = true;
			}
		}
		flag = false;
		cout << "Price" << endl << "> ";
		while (!flag)
		{
			i >> price;
			if (i.fail())
			{
				m_err = ERROR_POS_PRICE;
				m_err.display(cout);
				i.clear();
				i.ignore(2000, '\n');
				cout << endl << "> ";
			}
			else if (price < 0)
			{
				m_err = ERROR_POS_PRICE;
				m_err.display(cout);
				i.ignore(2000, '\n');
				i.clear();
				cout << endl << "> ";

			}
			else
			{
				m_price = price;
				flag = true;
				i.ignore(2000,'\n');
			}
		}
		flag = false; 
		cout << "Taxed?" << endl << "(Y)es/(N)o: ";
		while (!flag)
		{
			i.get(taxed);
			if (i.fail())
			{
				m_err = "Only 'y' and 'n' are acceptable: ";
				m_err.display(cout);
				i.ignore(2000, '\n');
				i.clear();
				

			}
			else if (taxed != 'y' && taxed != 'n')
			{
				m_err = "Only 'y' and 'n' are acceptable: ";
				m_err.display(cout);
				i.ignore(2000,'\n');
				i.clear();
				
			}
			else
			{
				if (taxed == 'y')
				{
					m_taxed = true;
				}
				else if(taxed == 'n')
				{
					m_taxed = false;
				}
				flag = true;
			}
		}
		flag = false;
		cout << "Quantity" << endl << "> ";
		while (!flag)
		{
			i >> qty;
			if (i.fail())
			{
				m_err = ERROR_POS_QTY;
				m_err.display(cout);
				i.clear();
				i.ignore(2000, '\n');
				cout << endl << "> ";


			}
			else if (qty > MAX_STOCK_NUMBER || qty <= 0)
			{
				m_err = ERROR_POS_QTY;
				m_err.display(cout);
				i.ignore(2000, '\n');
				i.clear();
				cout << endl << "> ";
			}
			else
			{
				m_qty = qty;
				flag = true;
			}
		}
		clear();
		stop = true;
	}

	return i;
}

ostream& sdds::Item::write(ostream& o) const
{
	
	double tPrice = cost() * quantity();
	
	if (*this)
	{
		string str{};
		if (strlen(m_name) > 20)
		{
			str.assign(m_name, 20);
		}
		else
		{
			str = m_name;
		}
		if (m_displayType == POS_LIST)
		{

			o << setfill(' ') << setw(7) << left << m_sku << "|" << setw(20) << str << "|" << setw(7) << right << std::fixed << setprecision(2) << m_price << "|" << setw(3) << (m_taxed ? " X " : " ") << "|" << setw(4) << right << m_qty << "|" << setw(9) << setprecision(2) << tPrice << "|";
		}
		else if (m_displayType == POS_FORM)
		{
			o << "=============v" << endl
				<< "Name:        " << m_name << endl
				<< "Sku:         " << m_sku << endl
				<< "Price:       " << setprecision(2) << std::fixed << m_price << endl
				<< "Price + tax: ";  if (m_taxed)  o << tPrice; else  o << "N/A"; o << endl
				<< "Stock Qty:   " << m_qty << endl;
		}
	}
	else
	{
		o << m_err.getError();
	}
	return o;
}

ofstream& sdds::Item::save(ofstream& o) const
{
	//cout << *this;
	if (*this)
	{

		o << itemType() << ',' << m_sku << ',' << m_name << ',' << setprecision(2) << std::fixed << m_price << ',' << m_taxed << ',' << m_qty;
	}
	else
	{
		o << m_err.getError();
	}

	return o;
}

ifstream& sdds::Item::load(ifstream& fi)
{
	~*this;
	clear();
	char sku[MAX_SKU_LEN + 1]{};
	char* name{};
	double price{};
	int qty{};
	int taxed{};

	//get SKU
	fi.get(sku, MAX_SKU_LEN + 1, ',');
	if (fi.fail())
	{
		~*this;
		m_err = ERROR_POS_SKU;
		fi.clear();
		fi.ignore(2000,'\n');
		return fi;
	}
	else if (fi.get() != ',')
	{
		m_err = ERROR_POS_SKU;
		fi.clear();
		return fi;
	}
	else
	{
		strcpy(m_sku, sku);
	}
	
	//Get Item Name
	name = dynRead(fi, ',');
	if (strlen(name) > MAX_NAME_LEN +1)
	{
		m_err = ERROR_POS_NAME;
		delete[] name;
		return fi;
	}
	else
	{
		delAlloCopy(m_name,name);
	}
		delete[] name;
	//Get Item Price
	fi >> price;
	if (fi.fail())
	{
		m_err = ERROR_POS_PRICE;
		fi.clear();
		return fi;
	}
	else if (price < 0)
	{
		m_err = ERROR_POS_PRICE;
		fi.clear();
		return fi;
	}
	else
	{
		m_price = price;
	}
	fi.ignore(2000, ',');
	//Get Taxed
	fi >> taxed;
	if (fi.fail())
	{
		m_err = "Invalid Display Type";
		fi.clear();
		fi.ignore(2000, '\n');
		return fi;
	}
	else if (taxed != 1 && taxed != 0)
	{
		m_err = "Invalid Display Type";
		fi.clear();
		fi.ignore(2000, '\n');
		return fi;
	}
	else
	{
		m_taxed = taxed;
	}
	fi.ignore(2000, ',');


	//Get Quantity
	fi >> qty;
	if (fi.fail())
	{
		m_err = ERROR_POS_QTY;
		fi.clear();
		return fi;
	}
	else if (qty > MAX_STOCK_NUMBER || qty <= 0)
	{
		m_err = ERROR_POS_QTY;
		fi.clear();
		return fi;
	}
	else
	{
		m_qty = qty;
	}
	return fi;
}

ostream& sdds::Item::bprint(ostream& o)
{
	if (*this)
	{
		string str{};
		if (strlen(m_name) > 20)
		{
			str.assign(m_name, 20);
		}
		else
		{
			str = m_name;
		}

		o << setfill(' ') << "| " << setw(20) << left << str << "|" << setw(10) << right <<  setprecision(2) << std::fixed << cost() << " |" << setw(5) << (m_taxed ? "  T  " : " ") << "|" << endl;

	}
	else
	{
		o << m_err.getError() << endl;
	}
	return o;
}

double sdds::operator+=(double& cost, const Item& item)
{
	double price = item.cost() * item.quantity();
	cost += price;

	return cost;
}



