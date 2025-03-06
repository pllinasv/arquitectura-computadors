#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *values;
    char fileName[] = "valors.txt";
    int numbers[MAX_SIZE];

    values = fopen(fileName, "r");

    if (values == NULL) {
        fprintf(stderr, "Error: Failed opening file called as %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    int i=0;
    while ( fscanf(values, "%d", &numbers[i])==1)
    {
        i++;
        if (i>=MAX_SIZE) break;
    }
    
    fclose(values);
    
    for(int i=0; i<MAX_SIZE; i++){
        printf("%d\n", numbers[i]);
    }

    return 0;
}
