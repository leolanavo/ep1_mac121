#include <stdio.h>

unsigned short int steps[500000000];

void collatz(int i, int f)
{
    int count, index;
    int x = i;
    for (index = 0; x <= f; index++, x = i + index)
    {
        for (count = 0; x > 1; count++)
        {
            if (x < 500000000 && steps[x] != 0)
            {
                count = steps[x] + count - 1;
                x = 1;
            }
            else if (x%2 != 0)
            {
                x = 3*x + 1;
            }
            else
            {
                x = x/2;
            }
        }
        if (i + index < 500000000) steps[i + index]=count;
        printf("%d", count);
    }
}


int main()
{
    int i, f;
    printf("Digite o início e o fim do intervalo: ");
    scanf("%d %d", &i, &f);
    collatz(i, f);
    return 0;
}