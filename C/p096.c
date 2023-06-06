/* Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear,
 * but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares.
 * The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column,
 * and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.
 *
 *    0 0 3  0 2 0  6 0 0        4 8 3  9 2 1  6 5 7
 *    9 0 0  3 0 5  0 0 1        9 6 7  3 4 5  8 2 1
 *    0 0 1  8 0 6  4 0 0        2 5 1  8 7 6  4 9 3
 *
 *    0 0 8  1 0 2  9 0 0        5 4 8  1 3 2  9 7 6
 *    7 0 0  0 0 0  0 0 8        7 2 9  5 6 4  1 3 8
 *    0 0 6  7 0 8  2 0 0        1 3 6  7 9 8  2 4 5
 *
 *    0 0 2  6 0 9  5 0 0        3 7 2  6 8 9  5 1 4
 *    8 0 0  2 0 3  0 0 9        8 1 4  2 5 3  7 6 9
 *    0 0 5  0 1 0  3 0 0        6 9 5  4 1 7  3 8 2
 *
 *    A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ
 *    "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search
 *    determines the difficulty of the puzzle; the example above is considered easy because it can be solved by straight forward direct deduction.
 *
 *    The 6K text file, sudoku.txt, contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions
 *    (the first puzzle in the file is the example above).
 *
 *    By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid;
 *    for example, 483 is the 3-digit number found in the top left corner of the solution grid above.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int solve_sudoku(int grid[][9]);
int solve_recursive(int grid[][9], int step);
int check(int grid[][9], int i, int j, int n);

int main(int argc, char **argv)
{
   char dummy[10], dummy_c;
   int i, j, sum = 0, partial;
   int grid[9][9];
   double elapsed;
   struct timespec start, end;
   FILE *fp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("sudoku.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "sudoku.txt");
      return 1;
   }

   while(!feof(fp))
   {
      fgets(dummy, sizeof(dummy), fp);

      for(i = 0; i < 9; i++)
      {
         for(j = 0; j < 9; j++)
         {
            fscanf(fp, "%c", &dummy_c); 
            grid[i][j] = (int)dummy_c - '0';
         }
         
         fscanf(fp, "%c", &dummy_c);
      }

      /* For each sudoku in the file, solve it and sum the number in the
       * top left corner to the total.*/
      if(!solve_sudoku(grid))
      {
         printf("Bad sudoku grid\n");
         return 1;
      }

      partial = grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
      sum += partial;
   }

   fclose(fp);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;
   
   printf("Project Euler, Problem 96\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int check(int grid[][9], int i, int j, int n)
{
   int k, w, ii, jj;

   for(k = 0; k < 9; k++)
   {
      if(k != j && grid[i][k] == n)
      {
         return 0;
      }
   }

   for(k = 0; k < 9; k++)
   {
      if(k != i && grid[k][j] == n)
      {
         return 0;
      }
   }

   ii = 3 * (i / 3);
   jj = 3 * (j / 3);

   for(k = 0; k < 3; k++)
   {
      for(w = 0; w < 3; w++)
      {
         if(ii + k != i && jj +w != j && grid[ii+k][jj+w] == n)
         {
            return 0;
         }
      }
   }

   return 1;
}

int solve_recursive(int grid[][9], int step)
{
   int i, j, k;

   if(step == 81)
   {
      return 1;
   }

   i = step / 9;
   j = step % 9;

   if(grid[i][j] != 0)
   {
      if(solve_recursive(grid, step+1))
      {
         return 1;
      }
   }          
   else
   {
      for(k = 1; k <= 9; k++)
      {
         grid[i][j] = k;

         if(check(grid, i, j, k))
         {
            if(solve_recursive(grid, step+1))
            {
               return 1;
            }

            grid[i][j] = 0;
         }
      }

      grid[i][j] = 0;
   }

   return 0;
}

int line_complete(int grid[][9], int i)
{
   int n;

   for(n = 0; n < 9; n++)
   {
      if(grid[i][n] == 0)
      {
         return 0;
      }
   }

   return 1;
}

int column_complete(int grid[][9], int j)
{
   int n;

   for(n = 0; n < 9; n++)
   {
      if(grid[n][j] == 0)
      {
         return 0;
      }
   }

   return 1;
}

int solve_sudoku(int grid[][9])
{
   int i, j, k, w, count, val;

   for(w = 0; w < 4; w++)
   {
      for(i = 0; i < 9; i++)
      {
         for(j = 0; j < 9; j++)
         {
            if(grid[i][j] == 0)
            {
               count = 0;
            
               for(k = 1; k <= 9 && count < 2; k++)
               {
                  grid[i][j] = k;

                  if(check(grid, i, j, k) == 1)
                  {
                     count++;
                     val = k;
                  }
               }

               if(count == 1)
               {
                  grid[i][j] = val;
               }
               else
               {
                  grid[i][j] = 0;
               }
            }
         }
      }

      for(i = 0; i < 9; i++)
      {
         for(k = 1; k <= 9 && !line_complete(grid, i); k++)
         {
            count = 0;

            for(j = 0; j < 9 && count < 2; j++)
            {
               if(grid[i][j] == 0)
               {
                  grid[i][j] = k;

                  if(check(grid, i, j, k))
                  {
                     count++;
                     val = j;
                  }

                  grid[i][j] = 0;
               }
            }

            if(count == 1)
            {
               grid[i][val] = k;
            }
         }
      }

      for(j = 0; j < 9; j++)
      {
         for(k = 1; k <= 9 && !column_complete(grid, j); k++)
         {
            count = 0;

            for(i = 0; i < 9 && count < 2; i++)
            {
               if(grid[i][j] == 0)
               {
                  grid[i][j] = k;

                  if(check(grid, i, j, k))
                  {
                     count++;
                     val = i;
                  }

                  grid[i][j] = 0;
               }
            }

            if(count == 1)
            {
               grid[val][j] = k;
            }
         }
      }
   }

   return solve_recursive(grid, 0);
}
