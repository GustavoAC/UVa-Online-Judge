#include <iostream>
#include <queue>

int main(int argc, char const *argv[]) {
	int numCards;
	std::queue<int> deck;

	while(std::cin >> numCards and numCards) {
		for (int i = 1; i <= numCards; i++)
			deck.push(i);

		std::cout << "Discarded cards:";
		while (deck.size() != 1) {
			std::cout << " " << deck.front();
			deck.pop();
			deck.push(deck.front());
			deck.pop();
			if (deck.size() != 1) std::cout << ",";
		}

		std::cout << "\nRemaining card: " << deck.front() << "\n";
		deck.pop();
	}

	return 0;
}