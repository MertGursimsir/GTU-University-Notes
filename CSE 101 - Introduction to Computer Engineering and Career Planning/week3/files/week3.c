#include <stdio.h>

int main()
{
	int i, sum=0;
	for (i=1; i<=5; i++)
	{
		int a;
	   	scanf("%d", &a);
	   	sum += a;
	}
	printf("%d", sum/5);
	return 0;
}
