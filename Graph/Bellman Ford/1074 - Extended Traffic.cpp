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

const int INF = 9999999;
int num_junc, num_road, num_query;
int bussyness[MAX];
vector < pii > road_list;
int adj_mat[MAX][MAX], dist[MAX];
vector < int >neg_cycle;
bool isInNegCycle[MAX];


void Bellman_ford(int src)
{
    int i, j, k, from, to, w;
    neg_cycle.clear();
    for(i=0 ; i<=num_junc; i++)
        dist[i]= INF;

    dist[src]=0;

    for(k=0; k<num_junc-1; k++)
    {
        for(j=0; j<road_list.size(); j++)
        {
            from= road_list[j].ff;
            to= road_list[j].ss;

            if(dist[from]<INF && dist[to]> dist[from]+adj_mat[from][to])
            {
                dist[to]= dist[from]+adj_mat[from][to];
            }
        }
    }

    for(j=0; j<road_list.size(); j++)
    {
        from= road_list[j].ff;
        to= road_list[j].ss;

        if(dist[from]<INF && dist[to]> dist[from]+adj_mat[from][to])
        {
            dist[to]= dist[from]+adj_mat[from][to];
            neg_cycle.pb(to);
            isInNegCycle[to]= 1;
        }
    }
}

int main()
{
    int tcase, t, i ,j, k, a, b, w, destin;
    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &num_junc);
        CLR(bussyness);
        for(i=1; i<=num_junc; i++)
        {
            scanf("%d", &bussyness[i]);
        }
        road_list.clear();
        mset(adj_mat, INF);

        scanf("%d", &num_road);
        for(i=0; i<num_road; i++)
        {
            scanf("%d %d", &a, &b);
            road_list.pb(MP(a, b));
            w= (bussyness[b]-bussyness[a])*(bussyness[b]-bussyness[a])*(bussyness[b]-bussyness[a]);
            adj_mat[a][b]= w;
        }

        CLR(isInNegCycle);
        Bellman_ford(1);

        scanf("%d", &num_query);
        printf("Case %d:\n", t);

        for(i=0; i<num_query; i++)
        {
            scanf("%d", &destin);
            int is_neg_cycle=isInNegCycle[destin];


            if(dist[1]<INF && is_neg_cycle==1)
                printf("\?\n");
            else if(dist[destin]<3 || dist[destin]==INF)
                printf("\?\n");
            else
                printf("%d\n", dist[destin]);
        }
    }
    return 0;
}
