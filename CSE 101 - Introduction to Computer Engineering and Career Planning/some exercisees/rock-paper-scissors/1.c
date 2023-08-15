#include <stdio.h>
#include <stdlib.h>

int main()
{
	int choice;
	int computer;
	int yscore=0;
	int cscore=0; 
	
	printf("---------------------------------------\n");
	printf("WELCOME TO THE ROCK PAPER SCISSORS GAME\n");
	printf("  GET 5 POINTS TO DEFEAT THE COMPUTER\n");
	printf("---------------------------------------\n");
	
	while (1)
	{	
		if (yscore==5)
			{
				printf("Congratulations, you won.");
				break;
			}
			
		if (cscore==5)
			{
				printf("You lost.");
				break;
			}
		
		printf("Make your choice ---> 1 for rock, 2 for paper, 3 for scissors: ");
		scanf("%d", &choice);
		computer = (rand() % 3) + 1;
		
		if (choice==1)
		{
			printf("Your choice: Rock.\n");
			if (computer==1)
			{
				printf("Computer's choice: Rock.\n");
				printf("Draw.\n");
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==2)
			{
				printf("Computer's choice: Paper.\n");
				printf("You lost.\n");
				cscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==3)
			{
				printf("Computer's choice: Scissors.\n");
				printf("You win.\n");
				yscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
		}
		
		else if (choice==2)
		{
			printf("Your choice: Paper.\n");
			if (computer==1)
			{
				printf("Computer's choice: Rock.\n");
				printf("You win.\n");
				yscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==2)
			{
				printf("Computer's choice: Paper.\n");
				printf("Draw.\n");
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==3)
			{
				printf("Computer's choice: Scissors.\n");
				printf("You lost.\n");
				cscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
		}
		
		else if (choice==3)
		{
			printf("Your choice: Scissors.\n");
			if (computer==1)
			{
				printf("Computer's choice: Rock.\n");
				printf("You lost.\n");
				cscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==2)
			{
				printf("Computer's choice: Paper.\n");
				printf("You win.\n");
				yscore++;
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
			else if (computer==3)
			{
				printf("Computer's choice: Scissors.\n");
				printf("Draw.\n");
				printf("You %d-%d Computer\n\n", yscore, cscore);
			}
		}
		else
		{
			printf("Please type 1, 2 or 3.\n\n");
		}
	}

			
	return 0;
}
