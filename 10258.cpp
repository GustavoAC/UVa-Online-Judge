#include <iostream>
#include <sstream>
#include <vector>

struct Team {
	int accepted = 0;
	int penalty = 0;
	bool participating = false;
	bool solvedQuestions[10] = {false};
};

bool compare(const Team &a, const Team &b) {
	return a.participating and (a.accepted > b.accepted or (a.accepted == b.accepted and a.penalty < b.penalty));
}

int main(int argc, char const *argv[]) {
	std::string textInfo;
	std::vector<Team> teams(101);

	int numCompetitions, teamId, questId, timeSpent;
	char statusSub;

	while (std::cin >> numCompetitions and numCompetitions) {
		std::cin.ignore();
		for (int i = 0; i < numCompetitions; ++i) {
			while (std::getline(std::cin, textInfo) and textInfo != "\n") {
				std::stringstream ss(textInfo);
				ss >> teamId >> questId >> timeSpent >> statusSub;
				teams[teamId].participating = true;

				if (statusSub == 'C' and !teams[teamId].solvedQuestions[questId]) {
					teams[teamId].accepted++;
					teams[teamId].solvedQuestions[questId] = true;
					teams[teamId].penalty += timeSpent;
				} else if (statusSub == 'I' and !teams[teamId].solvedQuestions[questId])
					teams[teamId].penalty += 20;
			}

			std::sort(teams.begin() + 1, teams.end(), compare);

			for (int i = 1; i <= 100; ++i) {
				// imprime só os corretos e zera os não zerados
			}

		}
	}


	return 0;
}