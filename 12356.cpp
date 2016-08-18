#include <iostream>
#include <cstring>

int kindaBinarySearch(const char &aliveSoldiers, int left, int right) {
	int mid = (left + right)/2;
	while (left <= right) {
		if (aliveSoldiers[mid]) left = mid + 1;
		else {
		}
	}
}

int main(int argc, char const *argv[]) {
	char aliveSoldiers[100001];
	int numSoldiers, reports, deathsStart, deathsEnd, numCases = 0;

	while (std::cin >> numSoldiers >> reports and numSoldiers and reports) {
		std::memset(aliveSoldiers, 1, sizeof(aliveSoldiers));
		if (numCases++) std::cout << "\n";

		for (int i = 0; i < reports; ++i) {
			std::cin >> deathsStart >> deathsEnd;
			std::memset(aliveSoldiers + deathsStart, 0, deathsEnd - deathsStart + 1);

			// busca meio que binaria aqui em baixo
			// int j;
			// for (j = deathsStart-1; !aliveSoldiers[j] and j > 0; j--);
			// if (j > 0) std::cout << j;
			// else std::cout << "*";

			int left, right, mid;
			for (left = 1, right = deathsStart-1; left <= right; ) {
				mid =(left + right)/2;
				if (aliveSoldiers[mid]) left = mid + 1;
				else {

				}
			}



			for (j = deathsEnd+1; !aliveSoldiers[j] and j <= numSoldiers; j++);
			if (j <= numSoldiers) std::cout << " " << j;
			else std::cout << " *";

			std::cout << "\n";
		}
		std::cout << "-";
	}

	return 0;
}
