#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

// Penalty is only added if the question is solved later

struct Team {
	int id;
	int accepted = 0;
	int penalty = 0;
	bool participating = false;
	bool solvedQuestions[10] = {false};
};

bool compare(const Team &a, const Team &b) {
	return a.participating and (a.accepted > b.accepted or (a.accepted == b.accepted and a.penalty < b.penalty) or
		   a.accepted == b.accepted and a.penalty == b.penalty and a.id < b.id);
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

				if (statusSub == 'C' and !teams[teamId].solvedQuestions[questId]) {
					teams[teamId].accepted++;
					teams[teamId].solvedQuestions[questId] = true;
					teams[teamId].penalty += timeSpent;
				} else if (statusSub == 'I' and !teams[teamId].solvedQuestions[questId]){
					teams[teamId].penalty += 20;
				}
				
			}


			std::sort(teams.begin() + 1, teams.end(), compare);

			for (int i = 1; i <= 100; ++i)
				if (teams[i].participating){
					std::cout << teams[i].id << " " << teams[i].accepted << " ";
					if(teams[i].accepted) std::cout << teams[i].penalty << "\n";
					else std::cout << "0\n";

					teams[i].participating = false;
					teams[i].accepted = 0;
					teams[i].penalty = 0;
					for (int j = 0; j < 10; j++)
						teams[i].solvedQuestions[j] = false;
				}

			if (numCompetitions) std::cout << "\n";
		}
	}


	return 0;
}
