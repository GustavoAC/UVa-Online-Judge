#include <iostream>
#include <vector>
#include <sstream>

int matryoshka(const std::vector<int> &vec, int &index, bool &stillgoing) {
	if (index >= vec.size()) stillgoing = false;
	if (!stillgoing) return 0;
	
	int current = index++, ownSize = vec[current]*-1, inSize = 0;
	while (stillgoing and ownSize != vec[index] and inSize < ownSize) {
		if (vec[index] >= 0) stillgoing = false;
		else inSize += matryoshka(vec, index, stillgoing);
	}

	// ownSize == vec[index] é fato, mas permanece por entendimento
	if (stillgoing and inSize < ownSize and ownSize == vec[index]) {
		index++;
		return ownSize;
	} else {
		stillgoing = false;
		return 0;
	}
}

int main(int argc, char const *argv[]) {
	std::string readLine;
	std::vector<int> input;

	while (std::getline(std::cin, readLine)) {
		std::stringstream ss(readLine);
		int temp, index = 0;
		bool isValid = true;
		while (ss >> temp)
			input.push_back(temp);

		matryoshka(input, index, isValid);

		if (isValid and index == input.size())
			std::cout << ":-) Matrioshka!\n";
		else
			std::cout << ":-( Try again.\n";

		input.clear();
	}

	return 0;
}