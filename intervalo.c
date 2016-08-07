#include <stdio.h>
#include <time.h>
    
int collatz(int i, int f)
{
    int count, vez, n;
    int x = i;
    vez = 0;
    while (x <= f)
    {    
        for (count = 0; x > 1; count++)
        {
            if (x%2!=0)
            {
                x = 3*x+1;
            }
            else
            {
                x = x/2;
            }
        }
        vez++;
        x = i + vez;
        printf("Número: %d Passos: %d\n", x-1, count);
    }
    return 0;
}


int main()
{
    int i, f;
    printf("Digite o inicio e o fim do intervalo: ");
    scanf("%d %d", &i, &f);
    time_t start = clock(), dif;
    int count = collatz(i, f);
    dif = clock() - start;
    printf("Time was: %d miliseconds\n", (dif*1000/CLOCKS_PER_SEC));
    return 0;
}