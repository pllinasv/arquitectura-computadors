#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *values;
    char fileName[] = "valors.txt";
    char c;

    values = fopen(fileName, "r");

    if (values == NULL) {
        fprintf(stderr, "Error: Failed opening file called as %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fclose(values);
    return 0;
}
