#include<stdio.h>
#include<stdlib.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);
int zhineng(void);

int main(void)
{
	char done;
	printf("This is the game of Tic Tac Toe.\n");
	printf("You will be playing against the computer\n");
	done = ' ';
	init_matrix();
	do
	{
		disp_matrix();
		get_player_move();
		done = check();
		if (done != ' ') break;
		get_computer_move();
		done = check();
	}while (done == ' ');
	disp_matrix();
	if (done == 'X')
	printf("You win!\n");
	else
	printf("I win!!!\n");
	return 0;
}

char check(void)
{
	int i;
	if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
	return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
	return matrix[0][2];
	for (i = 0;i < 3;i++)
	if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
	return matrix[0][i];
	for (i = 0;i < 3;i++)
	if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
	return matrix[i][0];
	return ' ';
}
void init_matrix(void)
{
	int i;
	char *p;
	p = matrix;
	for (i = 0;i < 9;i++,p++)
	*p = ' ';
}
void get_player_move(void)
{
	int x, y;
	printf("Enter X,Y coordinates for your move:");
	scanf("%d%*c%d", &x, &y);
	x--;y--;
	if (matrix[x][y] != ' ')
	{
		printf("Invaild move, try again.\n");
		get_player_move();
	}
	else matrix[x][y] = 'X';
}
void get_computer_move(void)
{
	int i, j;
	if (zhineng())
	{
		if (matrix[1][1] == ' ')
    	i = j = 1;
   	else
   	{
      	for (i = 0;i < 3;i++)
      	{
   	   for (j = 0;j < 3;j++)
	          if (matrix[i][j] == ' ') break;
	      if (matrix[i][j] == ' ') break;
   	   }
   	}
   	if (i*j == 9)
   	{
	   	printf("draw\n");
	   	exit(0);
   	}
   	else
   	matrix[i][j] = 'O';
	}
}
void disp_matrix(void)
{
	int t;
	for (t = 0;t < 3;t++)
	{
   	printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
   	if (t != 2)
	   printf("\n---|---|---\n");
    }
    printf("\n");
}
int zhineng(void)
{
	int i;
	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == ' ')
	{
		matrix[2][2] = 'O';
		return 0;
	}
	if (matrix[0][0] == 'X' && matrix[2][2] == 'X' && matrix[1][1] == ' ')
	{
		matrix[1][1] = 'O';
		return 0;
	}
	if (matrix[2][2] == 'X' && matrix[1][1] == 'X' && matrix[0][0] == ' ')
	{
		matrix[0][0] = 'O';
		return 0;
	}
	if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == ' ')
	{
		matrix[2][0] = 'O';
		return 0;
	}
	if (matrix[0][2] == 'X' && matrix[2][0] == 'X' && matrix[1][1] == ' ')
	{
		matrix[1][1] = 'O';
		return 0;
	}
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == ' ')
	{
		matrix[0][2] = 'O';
		return 0;
	}
	for (i = 0;i < 3;i++)
	{
		if (matrix[i][0] == 'X' && matrix[i][1] =='X' && matrix[i][2] == ' ')
	   {	
	      matrix[i][2] = 'O';
   		return 0;
   	}
   	if (matrix[i][0] == 'X' && matrix[i][2] == 'X' && matrix[i][1] == ' ')
	   {	
	      matrix[i][1] = 'O';
   		return 0;
   	}
		if (matrix[i][2] == 'X' && matrix[i][1] == 'X' && matrix[i][0] == ' ')
	   {	
	      matrix[i][0] = 'O';
   		return 0;
   	}
	}
	for (i = 0;i < 3;i++)
	{
		if (matrix[0][i] == 'X' && matrix[1][i] == 'X' && matrix[2][i] == ' ')
	   {	
	      matrix[2][i] = 'O';
   		return 0;
   	}
   	if (matrix[0][i] == 'X' && matrix[2][i] == 'X' && matrix[1][i] == ' ')
	   {	
	      matrix[1][i] = 'O';
   		return 0;
   	}
		if (matrix[2][i] == 'X' &&matrix[1][i] == 'X' && matrix[0][i] == ' ')
	   {	
	      matrix[0][i] = 'O';
   		return 0;
   	}
	}
	return 1;
}