#include <iostream>
#include <cstring>

int main() {

	std::string s;

	while(true) {
		getline(std::cin, s);
		if(s == "") break;

		std::cout << s << '\n';
	}

	return 0;
}