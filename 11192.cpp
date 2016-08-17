#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
	int numGroups, charsPerGroup;
	std::string text;

	while (std::cin >> numGroups and numGroups) {
		std::cin >> text;
		std::cin.ignore();

		charsPerGroup = text.length() / numGroups;

		for (int i = 0; i < numGroups; i++)
			std::reverse(text.begin() + i*charsPerGroup, text.begin() + (i+1)*charsPerGroup);
		std::cout << text << "\n";
	}

	return 0;
}