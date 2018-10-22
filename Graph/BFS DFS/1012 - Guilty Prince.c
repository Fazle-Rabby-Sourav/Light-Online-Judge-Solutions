#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int row, column, count, front, rear;
char grid[30][30] ;
int queue[1000000];
int ok[30][30];

void push (int item)
{
    queue[rear]=item;
    ++rear;
    queue[rear]=-1;
}
void pop (void)
{
    queue[front]=-1;
    front=front+1;

}
void bfs (int item_x, int item_y)
{
    int end_x, end_y, start_x, start_y, n_x, n_y;
    int xx[4]= {1, 0, -1, 0};
    int yy[4]= {0, 1, 0, -1};
    front=0;
    rear=0;
    count=0;
    push(item_x);
    push(item_y);

    int i;
    while(/*queue[rear]!=-1 && **/queue[front]!=-1)
    {
        start_x=queue[front];
        pop();
        start_y=queue[front];
        pop();

        //ok[start_y][start_x]=1;
        count++;
        for(i=0; i<4 ; i++)
        {
            n_x=start_x+xx[i];
            n_y=start_y+yy[i];

            if(n_x>=0 && n_x<column && n_y>=0 && n_y<row)
            {
                if(ok[n_y][n_x]!=1 && grid[n_y][n_x]!='#' &&grid[n_y][n_x]=='.')
                {
                    push(n_x);
                    push(n_y);
                    ok[n_y][n_x]=1;
                }
            }
        }
    }
    return;
}
int main()
{
    char dummy;
    int t, k;
    while(scanf("%d", &t)!=EOF)
    {
        for(k=1; k<=t; k++)
        {
            scanf("%d %d", &column, &row);
            memset(ok, 0, sizeof(ok));
            memset(grid, '\0', sizeof(grid));
            scanf("%c", &dummy);
            if(column==0 && row==0)
                break;
            int item_x, item_y, i, j;
            for(i=0; i<row; i++)
            {
                for(j=0; j<column; j++)
                {
                    scanf("%c", &grid[i][j]);
                    if(grid[i][j]=='@')
                    {
                        item_x=j;
                        item_y=i;
                    }
                }
                scanf("%c", &dummy);
            }

            bfs(item_x, item_y);

            /*   for(i=0; i<row; i++)
               {
                   for(j=0; j<column; j++)
                       {
                        //   printf("%d", ok[i][j]);
                           if(ok[i][j]==1)
                           count++;
                       }
               }*/
            printf("Case %d: %d\n",k,count);
        }
    }
}
