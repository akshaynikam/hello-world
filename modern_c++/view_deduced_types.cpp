#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

int main() {
	int i = 10;
	const int* pi = &i;
	std::vector<int> v;

	std::cout << "decltype(i) : " << typeid(decltype(i)).name() << '\n';
	std::cout << "decltype(pi) : " << typeid(decltype(pi)).name() << '\n';

	std::cout << "boost (i) : " << boost::typeindex::type_id_with_cvr<decltype(i)>().pretty_name() << std::endl;
	std::cout << "boost (pi) : " << boost::typeindex::type_id_with_cvr<decltype(pi)>().pretty_name() << std::endl;
	std::cout << "boost (ri) : " << boost::typeindex::type_id_with_cvr<decltype((i))>().pretty_name() << std::endl;
	std::cout << "boost (v.size()) : " << boost::typeindex::type_id_with_cvr<decltype(v.size())>().pretty_name() << std::endl;
	std::cout << "sizeof(unsigned) : " << sizeof(unsigned) << std::endl;
	std::cout << "sizeof(unsigned long) : " << sizeof(unsigned long) << std::endl;

	return 0;
}
