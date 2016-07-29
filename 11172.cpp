#include <iostream>

int main(int argc, char const *argv[]) {

	int num, a, b;
	std::cin >> num;

	for (int i = 0; i < num; ++i) {
		std::cin >> a >> b;
		if (a > b)
			std::cout << ">\n";
		else if (a < b)
			std::cout << "<\n";
		else
			std::cout << "=\n";
	}

	return 0;
}