#include <stdio.h>

int main(){
	
	int i;
	int number;
	int toplam=0;
	int a;
	printf("Kac sayinin: ");
	scanf("%d", &i);
	for (a=0; a<i; a++)
	{
		printf("%d. sayiyi gir: ", a+1);
		scanf("%d", &number);
		toplam += number;
	}
	printf("Sayilarin ortalamasi: %f", toplam/i);
	
	return 0;
}
