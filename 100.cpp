#include <stdio.h>

int main(int argc, char const *argv[]) {

	int in1, in2, min, max, value, currentSteps, mostSteps;

	while (scanf("%i %i", &in1, &in2) != EOF){
		if (in1 < in2) min = in1, max = in2;
		else min = in2, max = in1;

		mostSteps = 0;

		for (int i = min; i <= max; ++i) {
			value = i;
			currentSteps = 1;

			while (value != 1) {
				value = (value & 1) ? value*3 + 1 : value/2;
				currentSteps++;
			}

			if (mostSteps < currentSteps) mostSteps = currentSteps;
		}

		printf("%i %i %i\n", in1, in2, mostSteps);
	}

	return 0;
}
