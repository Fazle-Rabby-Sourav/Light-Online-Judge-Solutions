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
#define MAX 1000

const int INF = 0x7f7f7f7f;
int N, total_min, total_max, parent[MAX];

vector < pair <int, pii> >GRAPH;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal_min(void)
{
    int i, pu, pv;

    sort(ALL(GRAPH));


    for(i=0, total_min=0; i<(int)GRAPH.size(); i++)
    {
        pu= findset(GRAPH[i].ss.ff, parent);
        pv= findset(GRAPH[i].ss.ss, parent);

        if(pu!=pv)
        {
            total_min+= GRAPH[i].ff;
            parent[pu]=parent[pv];
        }
    }
}

void kruskal_max(void)
{
    int i, pu, pv;

    sort(ALL(GRAPH));
    reverse(ALL(GRAPH));

    for(i=0, total_max=0; i<(int)GRAPH.size(); i++)
    {
        pu= findset(GRAPH[i].ss.ff, parent);
        pv= findset(GRAPH[i].ss.ss, parent);

        if(pu!=pv)
        {
            total_max+= GRAPH[i].ff;
            parent[pu]=parent[pv];
        }
    }
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");


    int i, j, k, tcase, t, home1, home2, coast;

    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &N);
        while(1)
        {
            scanf("%d %d %d", &home1, &home2, &coast);
            if(home1==0 && home2==0 && coast==0)
                break;
            GRAPH.push_back(pair <int, pii> (coast, pii(home1, home2)) );
        }

        for(i=0; i<=N; i++)
        {
            parent[i]=i;
        }
        kruskal_min();
        for(i=0; i<=N; i++)
        {
            parent[i]=i;
        }
        kruskal_max();

        printf("Case %d: ", t);

        int result;
        result= total_max+total_min;

        if(result%2==0)
        {
            printf("%d\n", result/2);
        }
        else
        {
            printf("%d/%d\n", result, 2);
        }

        GRAPH.clear();

    }

    return 0;
}
