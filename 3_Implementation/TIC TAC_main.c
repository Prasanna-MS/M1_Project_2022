#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[6][6];
const char Prasanna = '2';
const char pc = '1';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void PrasannaMove();
void pcMove();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char response = ' ';

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         PrasannaMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         pcMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Yes/No): ");
      scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("THANKS");

   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void PrasannaMove()
{
   int x;
   int y;
   printf("Welcome to the new trend of x and o game here x,o replaces by 1,2\n");
   do
   {
      printf("Enter the number of row you want to put the number 2(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter the number of column you want to put the number 2(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("wrong move \n");
      }
      else
      {
         board[x][y] = Prasanna;
         break;
      }
   } while (board[x][y] != ' ');
   
}
void pcMove()
{
   
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
     
      board[x][y] = pc;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }

   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
 
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
void printWinner(char winner)
{
   if(winner == Prasanna)
   {
      printf("WINNER");
   }
   else if(winner == pc)
   {
      printf("LOSER");
   }
   else{
      printf("MATCH DRAW");
   }
}