#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Vector;

Vector newVector (int size) {
    Vector new_vector;
    new_vector.size = size;
    new_vector.data = calloc(size, sizeof(*(new_vector.data)));
    return new_vector;
}

void deleteVector (Vector *V) {
    free(V->data);
    V->size = 0;
} 

Vector reallocVector (Vector V) {
    int i;
    Vector W = newVector(V.size*2);

    for (i = 0; i < V.size; i++)
        W.data[i] = V.data[i];

    deleteVector(&V);
    return W;
}


int main () {
    int i, size;
    Vector V;
    scanf("%d", &size);
    V = newVector(size);
    V = reallocVector(V)

    for (i = 0; i < V.size; i++)
        V.v[i]=1;
    

    printf("\n");
    return 0;
}