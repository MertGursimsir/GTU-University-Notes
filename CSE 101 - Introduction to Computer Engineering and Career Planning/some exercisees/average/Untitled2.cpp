#include <stdio.h>

int main(){
	
	char s[]="hallo ich heisse mert im schulerin";
	printf("%s",s);
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
	float ortalama;
	ortalama= toplam/i;
	printf("Sayilarin ortalamasi: %f", ortalama);
	
	return 0;
}
