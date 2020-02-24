#include <iostream>
#include "sales_item.h"

int main() {
	Sales_data i1, i2;
	int rc = 0;

	std::cin >> i1 >> i2;

	if (i1.isbn() == i2.isbn()) {
		std::cout << i1 + i2 << std::endl;
	} else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		rc = -1;
	}

	return rc;
}
