#include <stdio.h>

int main(int argc, char* argv[]) {

    int rounds, min, max, globalCounter = 1;
    char numString[1000000], currentVal;
    bool notFail;

    while (scanf("%s %i", numString, &rounds) != EOF) {
        printf("Case %i:\n", globalCounter);

        for (int i = 0; i < rounds; ++i) {
            scanf("%i %i", &min, &max);
            if (min > max) {
                int aux = min;
                min = max;
                max = aux;
            }

            currentVal = numString[min];
            notFail = true;
            for (int j = min + 1; j <= max and notFail; ++j)
                if (numString[j] != currentVal) notFail = false;

            if (notFail)
                printf("Yes\n");
            else
                printf("No\n");
        }

        globalCounter++;
    }

    return 0;
}
