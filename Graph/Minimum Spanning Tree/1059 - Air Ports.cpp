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
#define pii pair < int, int >
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

const int INF = 0x7f7f7f7f;
int parent[MAX], num_node, num_roads, coast_air, num_air, result, total;
bool air_exist[MAX];
vector < pair< int, pii > > GRAPH;
vector < int > par_list;

int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void kruskal(void)
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<num_roads; i++)
    {
        pu = findset(GRAPH[i].second.first);
        pv = findset(GRAPH[i].second.second);
        if(pu != pv)
        {
            if(coast_air>GRAPH[i].first)
            {
                total += GRAPH[i].first; // add edge cost
                parent[pu] = parent[pv]; // link
            }
        }
    }
}
void reset()
{
    // reset appropriate variables here
    for(int i=1; i<=num_node; i++) parent[i] = i;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k, a, b, w;

    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d %d", &num_node, &num_roads, &coast_air);
        reset();
        for(i=0; i<num_roads; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            GRAPH.push_back( pair <int ,pii> (w, pii(a, b)));
        }
        result=0;        num_air=0;        int flag=1;        CLR(air_exist);

        result+= coast_air;
        kruskal();
        result+= total;

        int x=findset(1);
        par_list.pb(x);
        if(air_exist[x]==0)
        {
            air_exist[x]==1;
            num_air++;
        }

        for(i=1; i<=num_node; i++)
        {
            flag=1;
            x= findset(i);
            for(k=0; k<SZ(par_list); k++)
            {
                if( x== par_list[k])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                int x;
                x=findset(i);
                par_list.pb(x);
                result+= coast_air;
                if(air_exist[x]==0)
                {
                    num_air++;
                    air_exist[x]=1;
                }
            }
        }
        printf("Case %d: %d %d\n", t, result, num_air);
        GRAPH.clear();
        par_list.clear();
    }
    return 0;
}
