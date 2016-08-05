#include <stdio.h>

int main(int argc, char* argv[]) {

    int rounds, min, max, globalCounter = 1, sequenceId = 1, sequencesVet[1000000];
    char numString[1000000], oldVal;
    bool notFail;

    while (scanf("%s %i", numString, &rounds) != EOF) {
        oldVal = numString[0];
        sequencesVet[0] = sequenceId;
        for (int i = 1; i < 1000000; ++i) {
            if (numString[i] != oldVal) {
                sequenceId++;
                oldVal = numString[i];
            }
            sequencesVet[i] = sequenceId;
        }

        printf("Case %i:\n", globalCounter++);

        for (int i = 0; i < rounds; ++i) {
            scanf("%i %i", &min, &max);

            if (sequencesVet[min] == sequencesVet[max])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
