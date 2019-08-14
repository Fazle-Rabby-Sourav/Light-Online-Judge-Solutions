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
#define MAX 5010
#define paii  pair< int, pii >
const int INF = 999999999;

pii dist[5005];

//struct cmp
//{
//    bool operator()(pii a, pii b)
//    {
//      return a.second > b.second;
//    }
//};

vector < pii > GRAPH[MAX];
priority_queue < pii, vector <pii>, greater< pii > > Q;
int color[MAX], num_node, num_edge;

void reset(void)
{
    int i;
    for(i=0; i<=num_node; i++)
    {
        dist[i].ff= INF;
        dist[i].ss= INF;
        GRAPH[i].clear();
    }
}

void dijkstra(int start)
{
    int i, j, k, from, to, w, w2, sz, prev;
    dist[start].ff=0;
    Q.push( make_pair ( start, dist[start].ff));

    while(!Q.empty())
    {
        from=Q.top().ff;
        prev= Q.top().ss;
        Q.pop();
         //    cout<<endl<<"\nnow:"<<from<<" ";
        sz=GRAPH[from].size();
        for(i=0; i<sz; i++)
        {
            to= GRAPH[from][i].first;
            w= GRAPH[from][i].second;
        //  printf("->to:%d\t", to);
            if( dist[to].ss > (prev+w) )
            {
                if(dist[to].ff > prev+w)
                {
                    dist[to].ss= dist[to].ff;
                    dist[to].ff= (prev+w);
                    Q.push( make_pair( to, (dist[to].ff)));
        //          cout<<"1st_time:"<<dist[to].ss<<"\t";
                }
                else if(dist[to].ff != (prev+w) )
                {
                    dist[to].ss= prev+w;
                    Q.push( make_pair(to, dist[to].ss));
                }
            }
        }
    }
}

int main()
{
    int i, j, k, tcase, t, a, b, w;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d", &num_node, &num_edge);
        reset();
        for(i=0; i<num_edge; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            GRAPH[a].push_back( pii(b, w));
            GRAPH[b].push_back( pii(a, w));
        }
        dijkstra(1);
        printf("Case %d: %d\n",t, dist[num_node].ss);
    }
    return 0;
}
