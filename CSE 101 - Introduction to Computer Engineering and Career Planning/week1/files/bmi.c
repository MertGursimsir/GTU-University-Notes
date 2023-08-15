#include <stdio.h>
#include <conio.h>

int main()
{
	float weight,height;
	printf("Enter your weight: ");
	scanf("%f", &weight);
	printf("Enter your height as meter: ");
	scanf("%f", &height);
	float bmi = weight/(height*height);
	printf("Your body mass index is %f. ", bmi);
	if (bmi < 18.5)
	{
		printf("You are underweight.\n");
	}
	else if (bmi < 24.9)
	{
		printf("You are normal.\n");
	}
	else if (bmi < 29.9)
	{
		printf("You are overweight.\n");
	}
	else if (bmi < 34.9)
	{
		printf("You are Obese.\n");
	}
	else
	{
		printf("You are extremely obese.\n");
	}
	getch();
	return 0;
}

