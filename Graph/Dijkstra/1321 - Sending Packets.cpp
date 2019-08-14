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
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define LL __int64
#define pii pair< int, int >
#define psi pair< string, int >
#define pid pair< int, double >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 110

const int INF = 0x7f7f7f7f;
int num_router, num_link, data_size, tym;
vector < pid > graph[MAX];
double dist[MAX];
struct myComp
{
    bool operator() (pid a, pid b)
    {
        return a.ss < b.ss;
    }
};
void dijkstra (int src)
{
    PQ < pid, vector < pid >, myComp > Q;
    int i, j, k, from, to;
    double w;
    mset(dist, 0.0);
    dist[src]=1.0;
    Q.push (MP(src, dist[src]));
    while(!Q.empty())
    {
        from= Q.top().ff;
        Q.pop();
        int sz=SZ(graph[from]);
        for(i=0; i<sz; i++)
        {
            to= graph[from][i].ff;
            w= graph[from][i].ss;
            if(dist[to] < dist[from]*w)
            {
                dist[to]= dist[from]*w;
                Q.push( MP(to, dist[to]));
            }
        }
    }
}
int main()
{
    int tcase, t,a, b, w, i, j, k;
    double w_d, probability, result;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d %d %d", &num_router, &num_link, &data_size, &tym);
        for(i=0; i<num_link; i++)
        {
            scanf("%d %d %d", &a, &b , &w);
            w_d= w/100.00;
            graph[a].pb(MP(b, w_d));
            graph[b].pb(MP(a, w_d));
        }

        dijkstra(0);

        probability= (1.0/dist[num_router-1]*1.0);
        result= probability*2*tym*data_size;

        printf("Case %d: %.10lf\n", t, result);

        for(i=0; i<=num_router; i++)
            graph[i].clear();
    }
    return 0;
}
