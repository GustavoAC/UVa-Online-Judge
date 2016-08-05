#include <stdio.h>

int main(int argc, char* argv[]) {

    int v, t;

    while (scanf("%i %i", &v, &t) != EOF)
        printf("%i\n", 2*v*t);

    return 0;
}
