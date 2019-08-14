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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
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
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 110

const int INF = 0x7f7f7f7f;

int start, destin, node;
int adj_mat[MAX][MAX];

void floyd_warshall(void)
{
    int i, j, k;
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            if(adj_mat[i][j]==0)
                adj_mat[i][j]=9999999;
        }
        adj_mat[i][i]=0;
    }

    for(k=0; k<node; k++)
    {
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                adj_mat[i][j]= min(adj_mat[i][j], (adj_mat[i][k]+adj_mat[k][j]));
            //    printf("[%d] ", adj_mat[i][j]);
                //adj_mat[i][j]= max( adj_mat[i][j] , (adj_mat[i][k]+adj_mat[k][j]));
            }
        }
    }
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k,a, b, w,  num_road;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d", &node, &num_road);

        for(i=0; i<num_road; i++)
        {
            scanf("%d %d", &a, &b);
            adj_mat[a][b]=1;
            adj_mat[b][a]=1;
        }
        scanf("%d %d", &start, &destin);

        floyd_warshall();

        int max_dist, indx, result;
        max_dist=0; result=0;

        for(i=0; i<node; i++)
        {
            result= max(result, adj_mat[start][i]+adj_mat[i][destin]);
        }

        printf("Case %d: %d\n", t, result);

        CLR(adj_mat);
    }


    return 0;
}
