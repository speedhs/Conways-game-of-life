#include <stdio.h>
int main(void)
{
  int i, j, count, n, m, row, col, a[100][100], gen = 0; //a=area
  char choice = 121;                                     //to view multiple generations
  //using multiple printf for better presentation
  printf("CONWAY'S GAME OF LIFE\n Rules:\n1.Any live cell with two or three live neighbours survives.\n");
  printf("2.Any dead cell with three live neighbours becomes a live cell.\n");
  printf("3.All other live cells die in the next generation. Similarly, all other dead cells stay dead\n(Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent\n");
  printf("Enter the size of sample area(m*n)\n");
  scanf("%d", &m);
  scanf("%d", &n);
  if (m < 3 || n < 3)
  {
    printf("Invalid input");
    return 0;
  }
  printf("Enter elements row wise(0 for dead cells and 1 for alive cells\n");
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  }
  printf("Input(0 for dead cells and 1 for alive cells:\nOth generation\n");
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
      printf("%d", a[i][j]);

    printf("\n");
  }
  //main logic
  while (choice == 121) //(choice ==1)
  {
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
      {
        count = 0;
        if (a[i][j] == 1) //alive cells
        {
          for (row = i - 1; row <= i + 1; row++) //forming a sub matrix
          {
            for (col = j - 1; col <= j + 1; col++)
            {
              if (row < 0)
                row++;
              if (col < 0)
                col++;
              if (a[row][col] == 1)
                count++;
            }
          }
          if (!(count == 4 || count == 3)) //conway's condition.count one more than given because it counts the cell which we are calculating for also
            a[i][j] = 0;                   //cell dies
        }
        else //dead cells
        {
          for (row = i - 1; row <= i + 1; row++) //forming a sub matrix
          {
            for (col = j - 1; col <= j + 1; col++)
            {
              if (row < 0)
                row++;
              if (col < 0)
                col++;
              if (a[row][col] == 1)
                count++;
            }
          }
          if (count == 3) //conway's condition.
            a[i][j] = 1;  //cell becomes alive
        }
      }
    }

    printf("Output(0 for dead cells and 1 for alive cells):\n%dth generation\n", (++gen));
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
        printf("%d", a[i][j]);
      printf("\n");
    }
    printf("Do you wish to see next generation?\nInput y for yes");
    scanf("%c", &choice);
  }
  return 0;
}
