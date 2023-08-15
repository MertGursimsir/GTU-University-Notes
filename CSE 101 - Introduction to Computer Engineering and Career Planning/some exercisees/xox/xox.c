#include <stdio.h>

int main(){
	char player1[20];
	char player2[20];
	char game[3][3]={'.','.','.','.','.','.','.','.','.'};
	int a,b,c,d,i,j,k=0;
	printf("Enter 1. Player: ");
	scanf("%s", player1);
	printf("Enter 2. Player: ");
	scanf("%s", player2);
	printf(" Welcome %s and %s to the XOX game.\n",player1,player2);
	printf("----------------------------------------------\n");
	printf("You should enter coordinates to play the game.\n");
	
	while (k<4){
		printf("\n%s's TURN", player1);
		LOOP:do{
			printf("\nEnter the x coordinate: ");
			scanf("%d", &a);			
		}while(a>2 || a<0);

		do{
			printf("Enter the y coordinate: ");
			scanf("%d", &b);
		}while(b>2 || b<0);
		
		if (game[a][b]!='.'){
			printf("Enter again!");
			goto LOOP;
		}
	
		game[a][b]='X';	
		
		for (i=0; i<3;i++){
			for (j=0; j<3; j++){
				printf("%c ", game[j][i]);
			}
			printf("\n");
		}
		
		if (game[0][0]=='X' && game[0][1]=='X' && game[0][2]=='X'){
			printf("%s WON!", player1);
			break;
		}
		else if (game[1][0]=='X' && game[1][1]=='X' && game[1][2]=='X'){
			printf("%s WON!", player1);
			break;			
		}
		else if (game[2][0]=='X' && game[2][1]=='X' && game[2][2]=='X'){
			printf("%s WON!", player1);
			break;			
		}
		else if (game[0][0]=='X' && game[1][0]=='X' && game[2][0]=='X'){
			printf("%s WON!", player1);
			break;			
		}		
		else if (game[0][1]=='X' && game[1][1]=='X' && game[2][1]=='X'){
			printf("%s WON!", player1);
			break;			
		}	
		else if (game[0][2]=='X' && game[1][2]=='X' && game[2][2]=='X'){
			printf("%s WON!", player1);
			break;			
		}			
		else if (game[0][2]=='X' && game[1][1]=='X' && game[2][0]=='X'){
			printf("%s WON!", player1);
			break;			
		}
		else if (game[0][0]=='X' && game[1][1]=='X' && game[2][2]=='X'){
			printf("%s WON!", player1);
			break;			
		}
			
		printf("\n%s's TURN", player2);			
		SLOOP:do{
			printf("\nEnter the x coordinate: ");
			scanf("%d", &c);			
		}while(c>2 || c<0);

		do{
			printf("Enter the y coordinate: ");
			scanf("%d", &d);
		}while(d>2 || d<0);
		
		if (game[c][d]!='.'){
			printf("Enter again!");
			goto SLOOP;
		}
		
		game[c][d]='O';	
		
		for (i=0; i<3;i++){
			for (j=0; j<3; j++){
				printf("%c ", game[j][i]);
			}
			printf("\n");
		}
		
		if (game[0][0]=='O' && game[0][1]=='O' && game[0][2]=='O'){
			printf("%s WON!", player2);
			break;
		}
		else if (game[1][0]=='O' && game[1][1]=='O' && game[1][2]=='O'){
			printf("%s WON!", player2);
			break;			
		}
		else if (game[2][0]=='O' && game[2][1]=='O' && game[2][2]=='O'){
			printf("%s WON!", player2);
			break;			
		}
		else if (game[0][0]=='O' && game[1][0]=='O' && game[2][0]=='O'){
			printf("%s WON!", player2);
			break;			
		}		
		else if (game[0][1]=='O' && game[1][1]=='O' && game[2][1]=='O'){
			printf("%s WON!", player2);
			break;			
		}	
		else if (game[0][2]=='O' && game[1][2]=='O' && game[2][2]=='O'){
			printf("%s WON!", player2);
			break;			
		}			
		else if (game[0][2]=='O' && game[1][1]=='O' && game[2][0]=='O'){
			printf("%s WON!", player2);
			break;			
		}
		else if (game[0][0]=='O' && game[1][1]=='O' && game[2][2]=='O'){
			printf("%s WON!", player2);
			break;			
		}
		
		k++;
	}
	
	return 0;
}
