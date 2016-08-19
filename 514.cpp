#include <iostream>
#include <sstream>
#include <stack>

int main(int argc, char const *argv[]) {
	std::stack<int> station;
	int numBlocks, incoming, expectedExiter;
	bool possibleOutcome;
	std::string endOrder;

	while (std::cin >> numBlocks and numBlocks) {
		std::cin.ignore();

		while (std::getline(std::cin, endOrder) and endOrder != "0"){
			incoming = 1;
			std::stringstream ss(endOrder);
			possibleOutcome = true;

			while (ss >> expectedExiter and expectedExiter and possibleOutcome) {
				if (expectedExiter < incoming) {
				
					if(station.top() == expectedExiter)
						station.pop();
					else
						possibleOutcome = false;
				} else if (expectedExiter == incoming) {
					incoming++;
				} else if (expectedExiter > incoming) {
					while (expectedExiter > incoming and incoming <= numBlocks)
						station.push(incoming++);
					incoming++;
				}
			}

			if (possibleOutcome)
				std::cout << "Yes\n";
			else {
				while (!station.empty()) station.pop();
				std::cout << "No\n";
			}
		}
		std::cout << "\n";
	}

	return 0;
}