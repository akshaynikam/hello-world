#ifndef __SALES_ITEM__
#define __SALES_ITEM__

#include <string>

using namespace std;

class Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	friend istream& operator >> (istream&, Sales_data&);
	friend ostream& operator << (ostream&, const Sales_data&);
	Sales_data operator + (const Sales_data& obj);

	string isbn() {
		return bookNo;
	}
};

#endif
