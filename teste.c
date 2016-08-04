#include <stdio.h>
#include <time.h>
#include <math.h>

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
        /*printf("Número: %d Passos: %d\n", x-1, countp);*/
    }
    return 0;
}


int main()
{
    int i, f;
    printf("Digite o inicio do intervalo: ");
    scanf("%d", &i);
    printf("Digite o final do intervalo: ");
    scanf("%d", &f);
    time_t start = clock(), dif;
    int count = collatz(i, f);
    dif = clock() - start;
    printf("Time was: %d miliseconds\n", (dif*1000/CLOCKS_PER_SEC));
    return 0;
}