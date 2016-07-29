#include <stdio.h>
#include <limits>
#include <cassert>

int main(int argc, char const *argv[]) {

	int min, max, value, currentSteps, mostSteps;

	while (scanf("%i %i", &min, &max) != EOF){
		if (min > max) {
			int aux = min;
			min = max;
			max = aux;
		}

		mostSteps = 0;

		for (int i = min; i <= max; ++i) {
			value = i;
			currentSteps = 1;

			while (value != 1) {
				value = (value & 1) ? value/3 + 1 : value/2;
				currentSteps++;
			}

			if (mostSteps < currentSteps){
				printf("%d\n", currentSteps);
				mostSteps = currentSteps;
			}
		}

		printf("%i %i %i\n", min, max, mostSteps);
	}

	return 0;
}