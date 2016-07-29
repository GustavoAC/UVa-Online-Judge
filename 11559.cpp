#include <stdio.h>

int main(int argc, char const *argv[]) {

	int numPar, budget, numHot, numWeeks;
	int priceWeek, bedsForWeek;
	int lowestCost;

	while (scanf("%d %d %d %d", &numPar, &budget, &numHot, &numWeeks) != EOF) {
		lowestCost = 500001;

		for (int i = 0; i < numHot; ++i) {
			scanf("%d", &priceWeek);

			for (int i = 0; i < numWeeks; ++i) {
				scanf("%d", &bedsForWeek);
				if (bedsForWeek < numPar || priceWeek * numPar > budget) continue;

				if (lowestCost > priceWeek * numPar)
					lowestCost = priceWeek * numPar;
			}
		}

		if (lowestCost <= budget)
			printf("%d\n", lowestCost);
		else
			printf("stay home\n");
	}

	return 0;
}