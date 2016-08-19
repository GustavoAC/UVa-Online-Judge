#include <iostream>
#include <cstring>
#include <vector>

int main(int argc, char const *argv[]) {
	
	int numSoldiers, reports, deathsStart, deathsEnd;

	while (std::cin >> numSoldiers >> reports and numSoldiers and reports) {

		std::vector<int> leftAlive(100001);
		std::vector<int> rightAlive(100001);

		for (int i = 1; i < numSoldiers; ++i) {
			leftAlive[i] = i-1;
			rightAlive[i] = i+1;
		}
		rightAlive[numSoldiers+1] = 0;

		for (int i = 0; i < reports; ++i) {
			std::cin >> deathsStart >> deathsEnd;

			rightAlive[leftAlive[deathsStart]] = rightAlive[deathsEnd];
			leftAlive[rightAlive[deathsEnd]] = leftAlive[deathsStart];

			if (leftAlive[deathsStart]) std::cout << leftAlive[deathsStart];
			else std::cout << "*";

			if (rightAlive[deathsEnd]) std::cout << " " << rightAlive[deathsEnd] << "\n";
			else std::cout << " *\n";			
		}
		std::cout << "-\n";
	}

	return 0;
}
