#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "POS.h"
#include "PosIO.h"
#include "Error.h"
#include "Utils.h"
/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
namespace sdds
{
	class Item : public PosIO
	{
		char m_sku[MAX_SKU_LEN]{};
		char* m_name{};
		double m_price{};
		bool m_taxed{};
		int m_qty{};
	protected:
		int m_displayType = 0;
		Error m_err;
		Item() {};
		Item(const Item& item);
		Item& operator= (const Item& item);
		~Item() { ~*this; }
		void operator~();
		inline bool validate(Item& item) { return item.m_name && item.m_name[0] && item.m_sku[0] && item.m_price >= 0 && strlen(item.m_sku) > 0 && item.m_qty >= 0 && bool(item) && (m_displayType == POS_FORM || m_displayType == POS_LIST); }
	public:
		inline bool operator==(const char* sku)
		{
			return strcmp(m_sku, sku) == 0;
		}

		inline bool operator>(Item& item)
		{
			if (m_name && m_name[0] && item.m_name && item.m_name[0])
			{
				return strcmp(m_name, item.m_name) > 0;
			}
			return false;
		}

		inline int operator+=(int qty)
		{
			m_qty += qty;
			if (m_qty > MAX_STOCK_NUMBER) {
				m_qty = MAX_STOCK_NUMBER;
				m_err = ERROR_POS_QTY;
			}
			return m_qty;
		}

		inline int operator-=(int qty)
		{
			m_qty -= qty;
			if (m_qty < 0)
			{
				m_qty = 0;
				m_err = ERROR_POS_STOCK;
			}
			return m_qty;
		}

		inline operator bool() const
		{
			return !bool(m_err);
		}

		virtual char itemType() const = 0;
		Item& displayType(int display) { m_displayType = display; if (m_displayType != POS_FORM && m_displayType != POS_LIST) { m_displayType = 0; } return *this; }

		inline double cost() const { if (m_taxed) { double price = m_price * TAX; double subtotal = m_price + price; return subtotal; } else { return m_price; } }
		inline int quantity() const { return m_qty; }

		inline Item& clear() { m_err.clear(); return *this; }

		virtual istream& read(istream& i) override;
		virtual ostream& write(ostream& o) const override;
		virtual ofstream& save(ofstream& o) const override;
		virtual ifstream& load(ifstream& fi) override;
		ostream& bprint(ostream& o);
		
	};
	double operator+=(double& cost, const Item& item);
	
}
#endif // !SDDS_ITEM_H
