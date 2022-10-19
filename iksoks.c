#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	char tabla[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tabla[i][j]='/';
		}
	}
	printaj(tabla);
	int igra=1;
	int x,y;
	int player=1;
	while(igra){
		if (player == 10){
			printf("\nDraw");
			break;
		}
		printf("\nunesite red i kolonu \n");
		scanf("%d %d",&x,&y);
		if(player % 2 == 1){
			if(tabla[x][y]=='/'){
				tabla[x][y]='X';
			}
			else{
				printf("uneli ste nedozvoljene kooordinate");
				continue;
			}

		}
		else{
			if(tabla[x][y]=='/'){
				tabla[x][y]='O';
			}
			else{
				printf("uneli ste nedozvoljene kooordinate \n");
				continue;
			}
		}
		printaj(tabla);
		if(proverapobednika(tabla) == 1){
			printf("\nPobeda\n");
			igra=0;
		}
		player++;
	}	
	return 0;
}
int proverapobednika(char t[3][3]){
	for (int i = 0; i < 3; i++){
		if(t[i][0]=='X' && t[i][1]=='X' && t[i][2]=='X'){
			return 1;
		}
		else if(t[i][0]=='O' && t[i][1]=='O' && t[i][2]=='O'){
			return 1;
		}
	}
	for (int i = 0; i < 3; i++){
		if(t[0][i]=='X' && t[1][i]=='X' && t[2][i]=='X'){
			return 1;
		}
		else if(t[0][i]=='O' && t[1][i]=='O' && t[2][i]=='O'){
			return 1;
		}
	}
	if(t[0][0]=='X' && t[1][1]=='X' && t[2][2]=='X'){
			return 1;
		}
	else if(t[0][0]=='O' && t[1][1]=='O' && t[2][2]=='O'){
			return 1;
		}
	if(t[0][2]=='X' && t[1][1]=='X' && t[2][0]=='X'){
			return 1;
		}
	else if(t[0][2]=='O' && t[1][1]=='O' && t[2][0]=='O'){
			return 1;
		}
	return 0;	

}

void printaj(char tabla[3][3])
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",tabla[i][j]);
		}
		printf("\n");
		}

}
