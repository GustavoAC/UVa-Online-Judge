// Nota:
// Apesar de funcional e funcionar em O(1), é uma solução muito complexa
// e demorada pra uma competição real.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

int main(int argc, char const *argv[]) {

	std::unordered_map<int, int> teamIdMap; // personId to teamId
	std::unordered_map<int, int> teamLocationMap; // teamId to vectorIndex
	std::vector<std::queue<int>> mainQueue(1000);
	int queueStart = 0, queueEnd = 0, globalCounter = 1; // indexes to the vector of queues;

	int numTeams, numParts, readId;
	std::string action;

	while (std::cin >> numTeams and numTeams) {
		std::cout << "Scenario #" << globalCounter++ << "\n";
		for (int i = 0; i < numTeams; ++i) {
			std::cin >> numParts;
			for (int j = 0; j < numParts; ++j) {
				std::cin >> readId;
				// Sets read person as someone from team i
				teamIdMap.insert({readId, i});
			}
		}

		while (std::cin >> action and action != "STOP") {
			if (action == "ENQUEUE") {
				std::cin >> readId;
				auto itTeamId = teamIdMap.find(readId); // iterator to teamId
				auto itVectorIndex = teamLocationMap.find(itTeamId->second); // iterator to vectorIndex
				if (itVectorIndex == teamLocationMap.end()) { // team not found
					// register team on the map at queueEnd and
					// push the member onto its correct location
					teamLocationMap.insert({itTeamId->second, queueEnd});
					mainQueue[queueEnd].push(readId);
					queueEnd++;
				} else {
					// push the member onto its team's own queue
					mainQueue[itVectorIndex->second].push(readId);
				}
			} else {
				int personId = mainQueue[queueStart].front();
				mainQueue[queueStart].pop();
				if (mainQueue[queueStart].empty()) { // Empty sub-queue
					// unregister teamId from teamLocationMap
					auto itTeamId = teamIdMap.find(personId);
					teamLocationMap.erase(itTeamId->second);
					queueStart++;
				}
				std::cout << personId << "\n";
			}
		}

		teamIdMap.clear();
		teamLocationMap.clear();
		for (int i = queueStart; i < queueEnd; i++)
			while (!mainQueue[i].empty()) mainQueue[i].pop();
		queueStart = queueEnd = 0;
		std::cout << "\n";
	}

	return 0;
}