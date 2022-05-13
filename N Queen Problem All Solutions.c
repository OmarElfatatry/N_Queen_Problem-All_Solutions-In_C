/*
 ============================================================================
 Name        : 01.c
 Created on  : Jan 16, 2020
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
#define N 4
static char flag=0;
void printboard(int[][N],int);
void allsolutions(int[][N],int);
int issafe(int[][N],int,int);
int main(void)
{
	int board [N][N];
	memset(board,0,sizeof(board));
	allsolutions(board,0);
	return 0;
}
void printboard(int board[][N],int n)
{
	int row,column;
	for(row=0;row<n;row++)
	{
		for(column=0;column<n;column++)
		{
			printf("%d ",board[row][column]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
}
void allsolutions(int board[][N],int column)
{
	if(column>=N) // if N queens are placed successfully so print the solution and make set solution flag
	{
		flag++;
		printf("%d- \n",flag);
		fflush(stdout);
		printboard(board,N);
		printf("\n");
		return;
	}
	else
	{
		int row=0;
		for(row=0;row<N;row++) //start checking each row in the current column
		{
			if(issafe(board,row,column)==1) //if it safe to place queen here
			{
				board[row][column]=1; //place queen on current row and column
				allsolutions(board,column+1); //recur for next column
				board[row][column]=0; //backtrack and remove queen from current location
			}
		}
	}
}
int issafe(int board[][N],int row,int column)
{
	int colindex,rowindex;
	for(colindex=0;colindex<column;colindex++)
	{
		if(board[row][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	for(colindex=column,rowindex=row;(colindex>=0)&&(rowindex>=0);colindex--,rowindex--)
	{
		if(board[rowindex][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	for(colindex=column,rowindex=row;(colindex>=0)&&(rowindex<N);colindex--,rowindex++)
	{
		if(board[rowindex][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	return 1;
}
