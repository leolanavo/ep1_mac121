#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short int *data;
    int *size;
} Vector;

Vector* newVector (int* size) {
    int vector_size = *size;
    Vector *new_vector;

    new_vector = malloc(sizeof(Vector));

    new_vector->size = &vector_size;
    new_vector->data = calloc(*size, sizeof(*(new_vector->data)));
    
    return new_vector;
}

void deleteVector (Vector* V) {
    free(V->data);
    *(V->size) = 0;
} 

void Collatz (int i, int f) {
    int count, index, section, max, *initial_size, *maxp;
    Vector *steps;
    int x = i;

    section = f - i;
    initial_size = &section;
    max = 300000000;
    maxp = &max;

    if (section <= max) {
        steps = newVector(initial_size);
    }
    
    else {
        steps = newVector(maxp);
    }

    for (index = 0; x <= f; index++, x = i + index) {
        for (count = 0; x > 1; count++) {

            if (x < *(steps->size) && steps->data[x] != 0) {
                count = steps->data[x] + count - 1;
                x = 1;
            }

            else if (x%2) {
                x = 3*x + 1;
            }
            
            else {
                x = x/2;
            }

        }

        if (i + index < *(steps->size)) {
            steps->data[i + index] = count;
        }

        printf("%d\n", count);
    }
    deleteVector(steps);
}


int main () {
    int i, f;
    printf("Digite o início e o fim do intervalo: ");
    scanf("%d %d", &i, &f);
    Collatz(i, f);
    return 0;
}
