#include <stdio.h>

int main(int argc, char const *argv[]) {

	int num, originx, originy, posx, posy;

	while (scanf("%d", &num) != EOF and num) {
		scanf("%d %d", &originx, &originy);

		for (int i = 0; i < num; ++i) {
			scanf("%d %d", &posx, &posy);
			if (originx == posx || originy == posy)
				printf("divisa\n");
			
			else if (posx > originx)
				if (posy > originy) printf("NE\n");
				else printf("SE\n");
			else
				if (posy > originy) printf("NO\n");
				else printf("SO\n");
		}
	}

	return 0;
}