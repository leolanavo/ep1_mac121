#include <stdio.h>
#include <stdlib.h>

void Collatz (int i, int f) {
    int count, index, size, section; 
    unsigned short int *steps; 
    long int aux = i;

    /*O vetor é declarado como unsigned short int, porque o número de
    passos não será maior que 2^16-1.
    Declara a variável aux como long int para garantir que
    durante os cálculos da conjectura, caso o número ultrapasse
    2^31-1, não haja problemas.*/

    section = f - i;

    if (section <= 250000000) {                            
        size = section;         
    }

    else {
        size = 250000000;
    }

    /*O tamanho máximo do vetor é 250*10⁶ de short int's
    para o programa não alocar mais de 500mb de memória*/

    steps = calloc(size, sizeof(short int));

    /*Usa-se a função calloc para garantir que
    o vetor alocado seja preenchido com 0's*/

    for (index = 0; aux <= f; index++, aux = i + index) {
        for (count = 0; x > 1; count++) {

            if (aux < (size) && steps[aux] != 0 && aux - i >= 0) {
                count = steps[aux - i] + count - 1;
                aux = 1;
            }

            /*Caso a posição de certo número dentro do vetor não seja nula
            o count absorverá esse valor, pois este valor é o número 
            de passos de um número previamente calculado. O -1 garante que
            não há passos sendo contado duas vezes. 
            Ex: num intervalo de 26 a 58, o 27 ocupa a segunda posição
            quando a função for calcular o 54, a função irá somar o que há
            na segunda posição do vetor com o valor de count. */

            else if (aux%2) {
                aux = (3*aux + 1)>>1;
                count++;
            }
            
            else {
                aux = aux>>1;

            }

            /*Caso a posição no vetor seja nula, a função irá calcular o valor
            para a próxima interação*/
        }

        if (index <= size) {
            steps[index] = count;
        }


        printf("%u\n", count);
    }
    free(steps);
    steps = NULL;
}


int main () {
    int i, f;
    printf("Digite o início e o fim do intervalo: ");
    scanf("%d %d", &i, &f);
    Collatz(i, f);
    return 0;
}
