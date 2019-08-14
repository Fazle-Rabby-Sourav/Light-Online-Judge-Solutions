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
#define MAX 35000

const int INF = 0x7f7f7f7f;

vector < pii > edge[35000];
int max_val, max_pos, D[MAX];
bool taken[MAX];

void BFS(int src)
{
    int i, j, k, from, to , w;

    queue < pii > Q;

    Q.push( pii ( 0, src ));


    D[src]= 0;
    taken[src]=1;
    while(!Q.empty())
    {

        from= Q.front().ss;
        Q.pop();
        //  cout<<"from:"<<from<<" ";
        for(i=0; i<SZ(edge[from]); i++ )
        {
            w= edge[from][i].ff;
            to= edge[from][i].ss;

            if(!taken[to])
            {
                D[to]=D[from]+w;
                if(D[to]>max_val)
                {
                    max_pos= to;
                    max_val= D[to];
                }
                Q.push(pii(D[to], to));
                taken[to]=1;
            }
        }
    }
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k,a, b,w, tcase, t, node;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &node);
        CLR(edge);
        for(i=0; i<node-1; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            edge[a].pb(pii(w, b));
            edge[b].pb(pii(w, a));
        }
        CLR(D);
        CLR(taken);
        max_pos=0;
        max_val=0;
        BFS(0);

        //  cout<<"max_dist:"<<max_val<<"max_pos:"<<max_pos<<endl;

        CLR(D);
        CLR(taken);
        max_val=0;

        BFS(max_pos);

        printf("Case %d: %d\n", t, max_val);
    }
    return 0;
}
