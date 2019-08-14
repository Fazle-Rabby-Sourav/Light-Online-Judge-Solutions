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
#define MAX 205
int xx[5]= {0, -1, 0, 1};
int yy[5]= {-1, 0, 1, 0};
const int INF = 20000;
char grid[MAX][MAX];
bool taken_fire[MAX][MAX], taken_jane[MAX][MAX];
int dist_jane[MAX][MAX], dist_fire[MAX][MAX], src_fire, src_jane,  row, column;

pii jane_src;
vector < pii > fire_src;

int BFS (void)
{
    queue < int > Q_jane;
    queue < int >Q_fire;

    int i, j, k, from_x, from_y, to_x, to_y, n_x, n_y, num_push_fire, num_final_fire, num_push_jane, num_final_jane;

    num_push_fire=0;
    num_push_jane=0;
    //Fire
    for(i=0; i<SZ(fire_src); i++)
    {
        Q_fire.push(fire_src[i].ff);
        Q_fire.push(fire_src[i].ss);
        num_push_fire++;
        dist_fire[fire_src[i].ss][fire_src[i].ff]=0;
        taken_fire[fire_src[i].ss][fire_src[i].ff]=1;
    }

    //Jane
    Q_jane.push(jane_src.ff);
    Q_jane.push(jane_src.ss);
    dist_jane[jane_src.ss][jane_src.ff]=0;
    taken_jane[jane_src.ss][jane_src.ff]=1;
    num_push_jane++;

    while(!Q_fire.empty() || !Q_jane.empty())
    {
        //Jane
        if(!Q_jane.empty())
        {
            num_final_jane= num_push_jane;
            num_push_jane=0;
            for(k=0; k<num_final_jane; k++)
            {
                from_x= Q_jane.front();
                Q_jane.pop();
                from_y= Q_jane.front();
                Q_jane.pop();
                if(from_y==0 || from_y==row-1 || from_x==0 || from_x==column-1)
                {
                    if(taken_fire[from_y][from_x]==0)
                        return (dist_jane[from_y][from_x]+1);
                }
                for(i=0; i<4; i++)
                {
                    n_x= from_x+ xx[i];
                    n_y= from_y+ yy[i];

                    if(n_x>=0 && n_x <column && n_y>=0 && n_y<row && taken_jane[n_y][n_x]==0 && taken_fire[n_y][n_x]==0 && grid[n_y][n_x]!= '#')
                    {

                        dist_jane[n_y][n_x] = dist_jane[from_y][from_x]+1;

                        Q_jane.push(n_x);
                        Q_jane.push(n_y);
                        taken_jane[n_y][n_x]= 1;
                        num_push_jane++;
                    }
                }
            }
        }

        if(!Q_fire.empty())
        {
            num_final_fire= num_push_fire;
            num_push_fire=0;
            for(k=0; k<num_final_fire; k++)
            {
                from_x= Q_fire.front();
                Q_fire.pop();
                from_y= Q_fire.front();
                Q_fire.pop();
                for(i=0; i<4; i++)
                {
                    n_x= from_x+ xx[i];
                    n_y= from_y+ yy[i];

                    if(n_x>=0 && n_x <column && n_y>=0 && n_y<row && taken_fire[n_y][n_x]==0 && grid[n_y][n_x]!= '#')
                    {
                        dist_fire[n_y][n_x] =dist_fire[from_y][from_x]+1;
                        taken_fire[n_y][n_x]=1;
                        Q_fire.push(n_x);
                        Q_fire.push(n_y);
                        num_push_fire++;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int tcase, t, i, j, k, flag, result;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        CLR(taken_jane);        CLR(dist_jane);        mset(dist_fire, 0);      CLR(taken_fire);        fire_src.clear();
        scanf("%d %d", &row, &column);
        for(i=0; i<row; i++)
            scanf("%s", &grid[i]);

        for(i=0; i<row; i++)
        {
            for(k=0; k<column; k++)
            {
                if(grid[i][k]=='J')
                {
                    jane_src.ff= k;
                    jane_src.ss= i;
                }
                if(grid[i][k]=='F')
                {
                    fire_src.pb(MP(k, i));
                }
            }
        }

     //   printf("[%d %d]", jane_src.ff, jane_src.ss);
        int result;
        result=BFS();
        if(result==-1)
        {
            printf("Case %d: IMPOSSIBLE\n", t);
        }
        else
        {
            printf("Case %d: %d\n", t, result);
        }
    }
}
