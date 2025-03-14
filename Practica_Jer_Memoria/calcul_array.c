#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Fitxer global per a la traça
FILE *fitxer_traca;

void printArray(int numbers[], int size){
    // Traça de la captura d'instrucció
    
    for(int i=0; i<size; i++){
        // Traça de l'accés de lectura a la variable i
        fprintf(fitxer_traca, "2 %p\n", &i);
        fprintf(fitxer_traca, "2 %p\n", &size);
        // Traça de l'accés de lectura a l'element de l'array
        fprintf(fitxer_traca, "2 %p\n", &numbers[i]);
        
        
        if(i==size-1){
            fprintf(fitxer_traca, "2 %p\n", &i);
            fprintf(fitxer_traca, "2 %p\n", &size);
            printf("%d", numbers[i]);
        
        } else{
            fprintf(fitxer_traca, "2 %p\n", &i);
            fprintf(fitxer_traca, "2 %p\n", &size);
            printf("%d, ", numbers[i]);
        }
        fprintf(fitxer_traca, "3 %p\n", &i);
    }
    printf("\n");
}

void swap(int *a, int *b){
    // Traça de la captura d'instrucció
    
    // Traça dels accessos de lectura
    fprintf(fitxer_traca, "2 %p\n", a);
    fprintf(fitxer_traca, "2 %p\n", b);
    
    int temp = *a;
    
    // Traça de l'accés d'escriptura a temp
    fprintf(fitxer_traca, "3 %p\n", &temp);
    
    *a = *b;
    
    // Traça de l'accés d'escriptura a a
    fprintf(fitxer_traca, "3 %p\n", a);
    
    *b = temp;

    fprintf(fitxer_traca, "2 %p\n", temp);
    
    // Traça de l'accés d'escriptura a b
    fprintf(fitxer_traca, "3 %p\n", b);
}

int partition(int array[], int low, int high){
    // Traça de la captura d'instrucció
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &array[high]);
    
    int pivot = array[high];
    
    // Traça de l'accés d'escriptura a pivot
    fprintf(fitxer_traca, "3 %p\n", &pivot);
    
    // Traça de l'accés de lectura a low
    fprintf(fitxer_traca, "2 %p\n", &low);
    
    int i = (low - 1);
    
    // Traça de l'accés d'escriptura a i
    fprintf(fitxer_traca, "3 %p\n", &i);

    for(int j = low; j < high; j++){
        // Traça dels accessos de lectura
        fprintf(fitxer_traca, "2 %p\n", &j);
        fprintf(fitxer_traca, "2 %p\n", &high);
        fprintf(fitxer_traca, "2 %p\n", &array[j]);
        fprintf(fitxer_traca, "2 %p\n", &pivot);
        
        if(array[j] > pivot){
            i++;
            
            // Traça de l'accés d'escriptura a i
            fprintf(fitxer_traca, "3 %p\n", &i);
            fprintf(fitxer_traca, "2 %p\n", &j);
            fprintf(fitxer_traca, "3 %p\n", &array[i]);
            fprintf(fitxer_traca, "2 %p\n", &array[j]);
            swap(&array[i], &array[j]);
        }
        fprintf(fitxer_traca, "3 %p\n", &j);
    }
    fprintf(fitxer_traca, "2 %p\n", &i);
    fprintf(fitxer_traca, "2 %p\n", &high);
    fprintf(fitxer_traca, "2 %p\n", &array[i]);
    fprintf(fitxer_traca, "2 %p\n", &array[high]);
    swap(&array[i+1], &array[high]);
    return (i+1);
}

void quickSort(int array[], int low, int high){
    // Traça de la captura d'instrucció
    
    // Traça dels accessos de lectura
    fprintf(fitxer_traca, "2 %p\n", &low);
    fprintf(fitxer_traca, "2 %p\n", &high);
    
    if(low < high){
        int pi = partition(array, low, high);
        fprintf(fitxer_traca, "2 %p\n", &low);
        fprintf(fitxer_traca, "2 %p\n", &high);
        fprintf(fitxer_traca, "2 %p\n", &array);
        // Traça de l'accés d'escriptura a pi
        fprintf(fitxer_traca, "3 %p\n", &pi);

        quickSort(array, low, pi-1);
        quickSort(array, pi+1, high);
    }
}

void copyArray(int from[], int to[], int size){
    // Traça de la captura d'instrucció
    
    for(int i=0; i<size; i++){
        // Traça dels accessos de lectura
        fprintf(fitxer_traca, "2 %p\n", &i);
        fprintf(fitxer_traca, "2 %p\n", &size);
        fprintf(fitxer_traca, "2 %p\n", &from[i]);
        
        to[i] = from[i];
        
        // Traça de l'accés d'escriptura
        fprintf(fitxer_traca, "3 %p\n", &to[i]);
        fprintf(fitxer_traca, "3 %p\n", &i);
    }
}

int removeDupes(int array[], int size){
    // Traça de la captura d'instrucció
    
    int j = 1;
    
    // Traça de l'accés d'escriptura a j
    fprintf(fitxer_traca, "3 %p\n", &j);
    
    int temp[size];

    for(int i=0; i<size; i++){
        // Traça dels accessos de lectura
        fprintf(fitxer_traca, "2 %p\n", &i);
        fprintf(fitxer_traca, "2 %p\n", &size);
        
        if(i==0){
            // Traça de l'accés de lectura
            fprintf(fitxer_traca, "2 %p\n", &array[0]);
            
            temp[0] = array[0];
            
            // Traça de l'accés d'escriptura
            fprintf(fitxer_traca, "3 %p\n", &temp[0]);
        } else {
            // Traça dels accessos de lectura
            fprintf(fitxer_traca, "2 %p\n", &i);
            fprintf(fitxer_traca, "2 %p\n", &array[i]);
            fprintf(fitxer_traca, "2 %p\n", &array[i-1]);
            
            if(array[i] != array[i-1]){
                // Traça dels accessos de lectura
                fprintf(fitxer_traca, "2 %p\n", &j);
                fprintf(fitxer_traca, "2 %p\n", &i);
                fprintf(fitxer_traca, "2 %p\n", &array[i]);
                
                temp[j] = array[i];
                
                // Traça de l'accés d'escriptura
                fprintf(fitxer_traca, "3 %p\n", &temp[j]);
                
                j++;
                
                // Traça de l'accés d'escriptura a j
                fprintf(fitxer_traca, "3 %p\n", &j);
            }
        }
        fprintf(fitxer_traca, "3 %p\n", &i);
    }
    copyArray(temp, array, j);
    return j;
}

int removePairs(int array[], int size){
    // Traça de la captura d'instrucció
    
    int j = 0;
    
    // Traça de l'accés d'escriptura a j
    fprintf(fitxer_traca, "3 %p\n", &j);
    
    int temp[size];
    
    for(int i=0; i<size; i++){
        // Traça dels accessos de lectura
        fprintf(fitxer_traca, "2 %p\n", &i);
        fprintf(fitxer_traca, "2 %p\n", &size);
        fprintf(fitxer_traca, "2 %p\n", &array[i]);
        
        if(!(array[i] % 2 == 0)){
            // Traça dels accessos de lectura
            fprintf(fitxer_traca, "2 %p\n", &j);
            fprintf(fitxer_traca, "2 %p\n", &array[i]);
            
            temp[j] = array[i];
            
            // Traça de l'accés d'escriptura
            fprintf(fitxer_traca, "3 %p\n", &temp[j]);
            
            j++;
            
            // Traça de l'accés d'escriptura a j
            fprintf(fitxer_traca, "3 %p\n", &j);
        }
    }
    copyArray(temp, array, size);
    return j;
}

int onlyPairs(int array[], int size){
    // Traça de la captura d'instrucció
    
    int j = 0;
    
    // Traça de l'accés d'escriptura a j
    fprintf(fitxer_traca, "3 %p\n", &j);
    
    int temp[size];
    
    for(int i=0; i<size; i++){
        // Traça dels accessos de lectura
        fprintf(fitxer_traca, "2 %p\n", &i);
        fprintf(fitxer_traca, "2 %p\n", &size);
        fprintf(fitxer_traca, "2 %p\n", &array[i]);
        
        if(array[i] % 2 == 0){
            // Traça dels accessos de lectura
            fprintf(fitxer_traca, "2 %p\n", &j);
            fprintf(fitxer_traca, "2 %p\n", &array[i]);
            
            temp[j] = array[i];
            
            // Traça de l'accés d'escriptura
            fprintf(fitxer_traca, "3 %p\n", &temp[j]);
            
            j++;
            
            // Traça de l'accés d'escriptura a j
            fprintf(fitxer_traca, "3 %p\n", &j);
        }
        fprintf(fitxer_traca, "2 %p\n", &i);
    }
    copyArray(temp, array, size);
    return j;
}

int main() {
    // Obrir el fitxer de traça
    fitxer_traca = fopen("tr_calcul_array.prg", "w");
    
    if (fitxer_traca == NULL) {
        fprintf(stderr, "Error: No s'ha pogut obrir el fitxer de traça\n");
        exit(EXIT_FAILURE);
    }
    
    // Traça de la captura d'instrucció
    
    FILE *values;
    char fileName[] = "valors.txt";
    int numbers[MAX_SIZE];

    values = fopen(fileName, "r");

    if (values == NULL) {
        fprintf(stderr, "Error: Failed opening file called as %s\n", fileName);
        fclose(fitxer_traca);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    
    // Traça de l'accés d'escriptura a i
    fprintf(fitxer_traca, "3 %p\n", &i);
    
    while (fscanf(values, "%d", &numbers[i]) == 1)
    {
        // Traça de l'accés d'escriptura a numbers[i]
        fprintf(fitxer_traca, "3 %p\n", &numbers[i]);
        
        i++;
        
        // Traça de l'accés d'escriptura a i
        fprintf(fitxer_traca, "3 %p\n", &i);
        
        // Traça de l'accés de lectura
        fprintf(fitxer_traca, "2 %p\n", &i);
        
        if (i >= MAX_SIZE) break;
    }
    
    fclose(values);
    
    int orderedArray[MAX_SIZE];
    copyArray(numbers, orderedArray, MAX_SIZE);
    quickSort(orderedArray, 0, MAX_SIZE-1);

    int arrayWithoutDupes[MAX_SIZE];
    copyArray(orderedArray, arrayWithoutDupes, MAX_SIZE);
    
    
    int noDupesSize = removeDupes(arrayWithoutDupes, MAX_SIZE);
    
    // Traça de l'accés d'escriptura
    fprintf(fitxer_traca, "3 %p\n", &noDupesSize);

    int arrayWithoutPairs[noDupesSize];
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &noDupesSize);
    
    copyArray(arrayWithoutDupes, arrayWithoutPairs, noDupesSize);
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &noDupesSize);
    
    int noPairSize = removePairs(arrayWithoutPairs, noDupesSize);
    
    // Traça de l'accés d'escriptura
    fprintf(fitxer_traca, "3 %p\n", &noPairSize);

    int arrayWithPairs[noDupesSize];
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &noDupesSize);
    
    copyArray(arrayWithoutDupes, arrayWithPairs, noDupesSize);
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &noDupesSize);
    
    int PairSize = onlyPairs(arrayWithPairs, noDupesSize);
    
    // Traça de l'accés d'escriptura
    fprintf(fitxer_traca, "3 %p\n", &PairSize);

    printf("Given values:\n");
    
    // Traça de l'accés de lectura
    
    printArray(numbers, MAX_SIZE);
    
    printf("Orderes Values:\n");
    
    // Traça de l'accés de lectura
    
    printArray(orderedArray, MAX_SIZE);
    
    printf("Only ordered pair values:\n");
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &PairSize);
    
    printArray(arrayWithPairs, PairSize);
    
    printf("Only ordered impair values:\n");
    
    // Traça de l'accés de lectura
    fprintf(fitxer_traca, "2 %p\n", &noPairSize);
    
    printArray(arrayWithoutPairs, noPairSize);
    
    // Tancar el fitxer de traça
    fclose(fitxer_traca);
    
    return 0;
}