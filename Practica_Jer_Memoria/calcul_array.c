#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


void printArray(int numbers[], int size){
    for(int i=0; i<size; i++){
        if(i==size-1){
            printf("%d", numbers[i]);
        } else{
        printf("%d, ", numbers[i]);
        }
    }
    printf("\n");
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

void copyArray(int from[], int to[], int size){
    for(int i=0; i<size; i++){
        to[i]=from[i];
    }
}

int removeDupes(int array[], int size){
    int j=1;
    int temp[size];

    for(int i=0; i<size; i++){
        if(i==0){
            temp[0]=array[0];
        } else{
            if(array[i]!=array[i-1]){
                temp[j]=array[i];
                j++;
            }
        }
        
    }
    copyArray(temp, array, j);
    return j;
}

int removePairs(int array[], int size){
    int j=0;
    int temp[size];
    for(int i=0; i<size; i++){
        if(!(array[i]%2==0)){
            temp[j]=array[i];
            j++;
        }
    }
    copyArray(temp, array, size);
    return j;
}

int onlyPairs(int array[], int size){
    int j=0;
    int temp[size];
    for(int i=0; i<size; i++){
        if(array[i]%2==0){
            temp[j]=array[i];
            j++;
        }
    }
    copyArray(temp, array, size);
    return j;
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
    copyArray(numbers, orderedArray, MAX_SIZE);
    quickSort(orderedArray, 0, MAX_SIZE-1);

    int arrayWithoutDupes[MAX_SIZE];
    copyArray(orderedArray, arrayWithoutDupes, MAX_SIZE);
    int noDupesSize=removeDupes(arrayWithoutDupes, MAX_SIZE);

    int arrayWithoutPairs[noDupesSize];
    copyArray(arrayWithoutDupes, arrayWithoutPairs, noDupesSize);
    int noPairSize=removePairs(arrayWithoutPairs, noDupesSize);

    int arrayWithPairs[noDupesSize];
    copyArray(arrayWithoutDupes, arrayWithPairs, noDupesSize);
    int PairSize=onlyPairs(arrayWithPairs, noDupesSize);

    printf("Given values:\n");
    printArray(numbers, MAX_SIZE);
    printf("Orderes Values:\n");
    printArray(orderedArray, MAX_SIZE);
    printf("Only ordered pair values:\n");
    printArray(arrayWithPairs, PairSize);
    printf("Only ordered impair values:\n");
    printArray(arrayWithoutPairs, noPairSize);
    return 0;
}
