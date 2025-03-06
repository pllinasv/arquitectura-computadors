#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printArray(int numbers[]){
    for(int i=0; i<MAX_SIZE; i++){
        printf("%d\n", numbers[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high){
    int pivot=array[high];
    int i = (low -1);

    for(int j = low; j<high; j++){
        if(array[j] > pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return(i+1);
}

void quickSort(int array[], int low, int high){
    if( low<high ){
        int pi = partition(array, low, high);

        quickSort(array, low, pi-1);
        quickSort(array, pi+1, high);
    }
}

void copyArray(int from[], int to[]){
    for(int i=0; i<MAX_SIZE; i++){
        to[i]=from[i];
    }
}

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
    
    int orderedArray[MAX_SIZE];

    copyArray(numbers, orderedArray);

    quickSort(orderedArray, 0, MAX_SIZE-1);

    printArray(orderedArray);

    return 0;
}
