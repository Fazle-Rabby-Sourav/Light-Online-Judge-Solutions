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
#define MAX 100

const int INF = 0x7f7f7f7f;

int n;
vector < pair< int ,pii> > GRAPH;
int parent[MAX] , total, all_cable;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}
void kruskal(void)
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
//    for(i=0; i<n*n; i++)
//    {
//        printf("[%d %d :%d]\n", GRAPH[i].ss.ff, GRAPH[i].ss.second, GRAPH[i].ff);
//    }
    for(i=total=0; i<n*n; i++)
    {
        pu = findset(GRAPH[i].ss.first, parent);
        pv = findset(GRAPH[i].ss.second, parent);
        if(pu != pv && GRAPH[i].ff)
        {
            total += GRAPH[i].ff; // add edge cost
        //    printf("MST[%d %d :%d] ", GRAPH[i].ss.ff, GRAPH[i].ss.second, GRAPH[i].ff);
            parent[pu] = parent[pv]; // link
        }
    }
}
void reset()
{
    // reset appropriate variables here
    for(int i=0; i<=n; i++) parent[i] = i;
}



int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k, w;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &n);
        reset();
        for(i=0, all_cable=0; i<n; i++)
        {
            for(k=0; k<n; k++)
            {
                scanf("%d", &w);
                GRAPH.push_back(MP(w, MP(i, k)));

                //  GRAPH.push_back(MP ( MP(k, i), w));
                all_cable+= w;
            }
        }
        kruskal();
        int x= findset(0, parent), flag=1;

        for(i=0; i<n; i++)
        {
            if(findset(i, parent)!=x)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            printf("Case %d: %d\n", t, all_cable-total);
        else
            printf("Case %d: %d\n", t, -1);

        GRAPH.clear();
    }
    return 0;
}
