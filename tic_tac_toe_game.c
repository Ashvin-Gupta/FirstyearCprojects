#include <stdio.h>
#define clear() printf("\033[H\033[J")

int display(char[][3]);
int getrow();
int getcol();
void update(char[][3],char,int,int);
int validmove( char[][3],int,int);

int main(void){

	int row,col;
	int moves = 0;
	char board[3][3];
	char player = 'X';

	for (row=0;row<3;row++){
		for (col=0;col<3;col++){
			board[row][col] = '-';
		}
	}

	printf("\nLet's play a game of Noughts and Crosses!");
	printf("\nHere is the board:\n" );
	display(board);

	do{
	    if (player=='X'){
		    player = 'O';
	    }
	    else{
		    player = 'X';
	    }


	    do{
	        row = getrow();
	        col = getcol();
	    } while (!validmove(board,row,col));

	    update(board,player,row,col);
	    moves = moves + 1;
	    clear();
	    printf("The board: \n");
	    display(board);
	} while (moves<9);

	printf("\nYou have finished the game!\n");

	return(0);


}

int display(char b[][3]){
	int i,j;
	for (i=0;i<3;i++){
		printf("\n");
		for (j=0;j<3;j++){
			printf("%c\t", b[i][j]);
		}
	}

}

int getrow(){
	int x;
	 printf("\nChoose the row you want to place your item in: \n");
	 scanf("%d", &x);
	 return(x-1);
}

int getcol(){
	int y;
	printf("\nChoose the coloum you want to place your item in: \n");
	scanf("%d", &y);
	return(y-1);
}

void update(char b[][3],char p,int r,int c){
	b[r][c] = p;
}

int validmove(char b[][3], int r, int c){
	if (r>=0 && r<=2 && c>=0 && c<=2 && b[r][c] == '-'){
		return(1);
	}
	else{
		printf("\nChoose a row and coloum in the range of 1-3 and a spot which isn't occupied!\n");
		return(0);
	}

}

















