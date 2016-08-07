#include <stdio.h>

int main()
{
    int x, count;
    printf("Digite um valor para X: ");
    scanf("%d", &x);
    for(count = 0; x!=1 ;count++)
    {
        if(x%2)
        {
            x = 3*x+1;
        }
        else
        {
            x = x/2;
        }
        printf("Número: %d\n", x);
    }
    printf("Passos: %d\n", count);
    return 0;
}