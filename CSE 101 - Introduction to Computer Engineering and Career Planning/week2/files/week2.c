#include <stdio.h>
#include <stdbool.h>

#define y 30

int x=5;
const int z=100;


int main()
{
	int x=7;
	printf("%d\n", x);
	int z=1412;
	int z=23423;
	printf("%d\n", z);
	printf("%d\n", y);
	#undef y
	#define y 2311
	f();
}

int f()
{
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d", z);
}

