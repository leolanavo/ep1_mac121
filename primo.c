#include <stdio.h>

int main(){
	int x, count, ehprimo;
	printf("Digite um número para teste: ");
	scanf("%d", &x);
	ehprimo = 1;
	count=2;
	while (count*count<=x && ehprimo==1)
	{
		if (x%count==0)
		{
			ehprimo=0;
		}
	count++;
	}
	if (ehprimo==1)
	{
		printf("%d é primo\n", x);
	}
	else
	{
		printf("%d não é primo\n", x);
	}
	return 0;
}