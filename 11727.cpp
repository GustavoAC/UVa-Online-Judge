#include <stdio.h>

int main(int argc, char const *argv[]) {

	int num, a, b, c;

	scanf("%d", &num);

	for (int i = 1; i <= num; ++i) {
		scanf("%d %d %d", &a, &b, &c);

		if (a <= b and b <= c || c <= b and b <= a) {
			printf("Case %d: %d\n", i, b);
		} else if (b <= a and a <= c || c <= a and a <= b){
			printf("Case %d: %d\n", i, a);
		} else {
			printf("Case %d: %d\n", i, c);
		}
	}

	return 0;
}