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
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define LL __int64
#define pii pair< int, int >
#define pil pair <int , long long int >
#define psi pair< string, int >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 10010

const int INF = 999999999;
int num_node, num_EDGE, taka, src, destin;

int dist1[MAX], dist2[MAX];
int toll[MAX];

vector < pii > EDGE[MAX], EDGE_REV[MAX];

struct myCmp
{
    bool operator() (pil a, pil b)
    {
        a.ss < b.ss;
    }
};

void dijkstra(int src)
{
    PQ < pii, vector< pii >, myCmp > Q;
    int i, j, k, from, to, w;

    for(i=0; i<=num_node; i++)
        dist1[i]= INF;

    mset(toll, -1);
    dist1[src]=0;
    toll[src]=0;
    Q.push(MP(src, dist1[src]));

    while(!Q.empty())
    {
        from = Q.top().ff;
        Q.pop();
    //  printf("\nfrom:%d: ", from);
        for(i=0; i<SZ(EDGE[from]); i++)
        {
            to= EDGE[from][i].ff;
            w= EDGE[from][i].ss;

            if( dist1[to]>dist1[from]+w)
            {;
                dist1[to]= dist1[from]+w;
                Q.push( MP(to, dist1[to]));
            //  printf("\nto:%d:%lld  ", to, dist1[to]);
            }
        }
    }
}

void dijkstra_rev(int src)
{
    PQ < pii, vector< pii >, myCmp > Q;
    int i, j, k, from, to, w;
    for(i=0; i<=num_node; i++)
        dist2[i]= INF;

    dist2[src]=0;

    Q.push(MP(src, dist2[src]));

    while(!Q.empty())
    {
        from = Q.top().ff;
        Q.pop();
    //  printf("\nfrom:%d: ", from);
        for(i=0; i<SZ(EDGE_REV[from]); i++)
        {
            to= EDGE_REV[from][i].ff;
            w= EDGE_REV[from][i].ss;

            if( dist2[to]> dist2[from]+w)
            {
                dist2[to]= dist2[from]+w;
                Q.push( MP(to, dist2[to]));
        //      printf("\nto:%d:%d  ", to, dist2[to]);
            }
        }
    }
}

int main()
{
    int tcase, t, i, j, k, a, b, w;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        cin>>num_node>>num_EDGE>>src>>destin>>taka;
        for(i=0; i<num_EDGE; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            EDGE[a].pb( MP(b, w));
            EDGE_REV[b].pb( MP(a, w) );
        }
        dijkstra(src);
        dijkstra_rev(destin);

        int max_w;

        for(i=1, max_w=-1; i<=num_node; i++)
        {
            for(k=0; k<SZ(EDGE[i]); k++)
            {
                a=i;
                b= EDGE[i][k].ff;
                w= EDGE[i][k].ss;
                if(w > max_w && dist1[a]+dist2[b]+w<=taka)
                {
                    max_w= w;
                }
            }
        }
        printf("Case %d: %d\n", t, max_w);
        for(i=0; i<=num_node; i++)
        {
            EDGE[i].clear();
            EDGE_REV[i].clear();
        }
    }
    return 0;
}
