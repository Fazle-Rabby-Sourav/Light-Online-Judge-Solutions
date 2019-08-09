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
#define MAX 600

const int INF = 0x7f7f7f7f;
int num_town, num_road, start_twn, D[MAX];
vector <pii> GRAPH[MAX];
PQ <pii, vector<pii>, greater<pii> > Q;
void dijkstra(int start_twn)
{
    int i, j, k, from, to, w;
    for(i=0; i<=num_town; i++)
    {
        D[i]= INF;
    }
    D[start_twn]=0;
    Q.push(pii(start_twn, D[start_twn]));

    while(!Q.empty())
    {
        from= Q.top().ff;
        Q.pop();
        for(i=0; i<(int)GRAPH[from].size(); i++)
        {
            to= GRAPH[from][i].ff;
            w= max(GRAPH[from][i].ss, D[from]);
            if(D[to]>w)
            {
                Q.push(pii(to, w));
                D[to]= w;
            }
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tcase, t, i, j, k, a, b, coast;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d", &num_town, &num_road);

        for(i=0; i<num_road; i++)
        {
            scanf("%d %d %d", &a, &b, &coast);

            GRAPH[a].push_back(pii(b, coast));
            GRAPH[b].push_back(pii(a, coast));
        }
        scanf("%d", &start_twn);


        dijkstra(start_twn);

        printf("Case %d:\n", t);
        for(i=0; i<num_town; i++)
        {
            if(D[i]==INF)
                printf("Impossible\n");
            else
                printf("%d\n", D[i]);
        }

        for(i=0; i<=num_town; i++)
        {
            GRAPH[i].clear();
        }




    }



    return 0;
}
