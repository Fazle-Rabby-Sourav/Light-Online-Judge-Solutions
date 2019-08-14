#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

template< class T > T _abs(T n)
{
    return (n < 0 ? -n : n);
}
template< class T > T sq(T x)
{
    return x * x;
}
template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c)
{
    return a<=b && b<=c;
}

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define LL __int64
#define pii pair< int, int >
#define psi pair< string, int >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 12

const int INF = 0x7f7f7f7f;
int row, column, indx_rider, pow_level;
char board[MAX][MAX];
bool taken[105][MAX][MAX];
int move[105][MAX][MAX];

int xx[8]= {-1,-2,-2,-1,1,2,2,1};
int yy[8]= {-2, -1,1,2,2,1,-1,-2};
void BFS(int src_x, int src_y)
{
    int i, j, k, from_x,from_y, to_x, to_y;
    queue <int> Q;

    Q.push(src_x);
    Q.push(src_y);

    taken[indx_rider][src_y][src_x]=1;
    move[indx_rider][src_y][src_x]=0;
    while(!Q.empty())
    {
        from_x= Q.front();
        Q.pop();
        from_y= Q.front();
        Q.pop();
        //  printf("[%d]from:%d%d:\t", indx_rider, from_x, from_y);
        for(i=0; i<8; i++)
        {
            to_x= from_x+xx[i];
            to_y= from_y+yy[i];

            if(to_x>=0 && to_x<column && to_y>=0 && to_y <row && taken[indx_rider][to_y][to_x]==false)
            {
                move[indx_rider][to_y][to_x]= move[indx_rider][from_y][from_x]+1;
                //    printf("move:%d-%d->%d ",to_y, to_x, move[indx_rider][to_y][to_x]);
                Q.push(to_x);
                Q.push(to_y);
                taken[indx_rider][to_y][to_x]=true;
            }
        }
    }
    for(i=0; i<row; i++)
    {
        for(k=0; k<column; k++)
        {
            move[indx_rider][i][k]= ceil((double)(move[indx_rider][i][k]/(pow_level*1.00) ));
        }
    }
//    cout<<endl;
//    for(i=0; i<row; i++)
//    {
//        for(k=0; k<column; k++)
//        {
//            if(taken[indx_rider][i][k]==1)
//            {
//
//            }
//            //printf("%d", move[indx_rider][i][k]);
//        }
//        cout<<endl;
//    }
//    cout<<endl;

}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        CLR(taken);
        CLR(move);
        CLR(board);
        scanf("%d %d", &row, &column);

        for(i=0; i<row; i++)
        {
            scanf("%s", &board[i]);
        }

        for(i=0, indx_rider=0; i<row; i++)
        {
            for(k=0; k<column; k++)
            {
                if(board[i][k]>='0' && board[i][k]<='9')
                {
                    pow_level= board[i][k]-'0';
                    BFS(k, i);
                    indx_rider++;
                }
            }
        }

//        for(i=0; i<indx_rider; i++)
//        {
//            for(k=0; k<row; k++)
//            {
//                for(j=0; j<column; j++)
//                {
//
//                    printf("%d", move[i][k][j]);
//
//                }
//                cout<<endl;
//            }
//            cout<<endl<<endl<<endl;
//        }

        int min_temp, min_final, flag, sum_move, flag_final;
        for(i=0, min_final=99999999, flag_final=0; i<row; i++)
        {
            for(k=0; k<column; k++)
            {
                for(j=0, min_temp=9999999, sum_move=0, flag=1; j<indx_rider; j++)
                {
                    if(taken[j][i][k])
                    {
                        sum_move+= move[j][i][k];
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(sum_move<min_final && flag==1)
                {
                    flag_final= 1;
                    min_final= sum_move;
                }
            }
        }
        if(flag_final==0 || indx_rider<1)
        {
            printf("Case %d: -1\n", t);
        }
        else
        {
            printf("Case %d: %d\n",t ,min_final);
        }
    }

    return 0;
}
