
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

#define ROWS 4
#define COLS 5

void readMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);

int main(void)
{

   char maze[ROWS][COLS] = {};

   readMaze(maze);

   //Q(a)
   cout << maze[1][3] << endl;
   cout << maze[2][1] << endl;

   // printMaze(maze);

   return EXIT_SUCCESS;
}

void readMaze(char maze[ROWS][COLS])
{
   std::ifstream rawMaze;
   rawMaze.open("sample01.out");

   for (int i = 0; i < ROWS; i++)
   {
      for (int j = 0; j < COLS; j++)
      {
         rawMaze >> maze[i][j];
      }
   }

}

void printMaze(char maze[ROWS][COLS]){
   char str[COLS];

   for (int i = 0; i < ROWS; i++)
   {
      for (int j = 0; j < COLS; j++)
      {
         str[j] = maze[i][j];
      }
      cout << str << endl;
   }

}