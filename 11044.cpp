#include <stdio.h>
#include <cmath>

int main(int argc, char const *argv[]) {

	int num, sidex, sidey, mehx, mehy;

	scanf("%i", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%i %i", &sidex, &sidey);

		sidex = ceil((sidex - 2)/3.0);
		sidey = ceil((sidey - 2)/3.0);

		printf("%i\n", sidex*sidey);
	}

	return 0;
}