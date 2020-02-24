#include <iostream>
#include "sales_item.h"

istream& operator >> (istream& is, Sales_data& obj) {
	is >> obj.bookNo >> obj.units_sold >> obj.revenue;

	return is;
}

ostream& operator << (ostream& os, const Sales_data& obj) {
	os << obj.bookNo << " "
	   << obj.units_sold << " "
	   << obj.units_sold * obj.revenue << " "
	   << obj.revenue;
	
	return os;
}

Sales_data Sales_data::operator + (const Sales_data& obj) {
	Sales_data res;

	res.bookNo = obj.bookNo;
	res.units_sold = obj.units_sold + this->units_sold;
	res.revenue = ((obj.units_sold * obj.revenue) + (this->units_sold * this->revenue)) / res.units_sold;

	return res;
}
