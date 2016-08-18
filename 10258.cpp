#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

struct Team {
	int id;
	int accepted = 0;
	int penalty = 0;
	bool participating = false;
	int solvedQuestions[10] = {0}; //0 is no attempt, negative for errors, 1 is correct
};

bool compare(const Team &a, const Team &b) {
	return (a.accepted > b.accepted or (a.accepted == b.accepted and a.penalty < b.penalty) or
           (a.accepted == b.accepted and a.penalty == b.penalty and a.id < b.id));
}

int main(int argc, char const *argv[]) {
	std::string textInfo;
	std::vector<Team> teams(101);

	int numCompetitions, teamId, questId, timeSpent;
	char statusSub;

	while (std::cin >> numCompetitions and numCompetitions) {
		std::cin.ignore();
		std::getline(std::cin, textInfo);	//Gets rid of the first newline
		while (numCompetitions--) {
			while (std::getline(std::cin, textInfo) and textInfo != "") {
				std::stringstream ss(textInfo);
				ss >> teamId >> questId >> timeSpent >> statusSub;
				teams[teamId].id = teamId;
				teams[teamId].participating = true;

				if (statusSub == 'C' and teams[teamId].solvedQuestions[questId] <= 0) {
					teams[teamId].accepted++;
					teams[teamId].penalty += timeSpent + -1*teams[teamId].solvedQuestions[questId]*20;
					teams[teamId].solvedQuestions[questId] = 1;
				} else if (statusSub == 'I' and teams[teamId].solvedQuestions[questId] <= 0){
					teams[teamId].solvedQuestions[questId]--;
				}
			}

			// for (int i = 1; i <= 100; ++i){
			// 		std::cout << teams[i].id << " " << teams[i].accepted << " "
			// 		          << teams[i].penalty << "\n";
			// }

			std::sort(teams.begin() + 1, teams.end(), compare);
		//	std::sort(teams.begin() + 1, teams.end(), compare);

			for (int i = 1; i <= 100; ++i){
				if (teams[i].participating) {
					std::cout << teams[i].id << " " << teams[i].accepted << " "
							  << teams[i].penalty << "\n";

					teams[i].participating = false;
					teams[i].accepted = 0;
					teams[i].penalty = 0;
					for (int j = 0; j < 10; j++)
						teams[i].solvedQuestions[j] = false;
				}
			}
			if (numCompetitions) std::cout << "\n";
		}
	}


	return 0;
}
