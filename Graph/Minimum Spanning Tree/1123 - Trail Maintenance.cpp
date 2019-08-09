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
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 210

const int INF = 0x7f7f7f7f;


vector <pair<int, pii > > MST_last, GRAPH;
int num_week, num_node, total_best, cnt;

int parent[MAX], total;
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
    MST_last.clear();
    for(i=total_best=0; i<SZ(GRAPH); i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST_last.push_back(GRAPH[i]); // add to tree
            total_best += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
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
    int tcase, t, i, j, k, a, b, w, flag;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        GRAPH.clear();
        MST_last.clear();
        scanf("%d %d", &num_node, &num_week);
        flag=0;
        printf("Case %d:\n", t);
        for(i=0; i<num_week; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            GRAPH= MST_last;
            GRAPH.pb(MP(w, MP(a, b)));
            reset();
            kruskal();

            int par_x;
            par_x= findset(1, parent);

            for(k=1, flag=1; k<=num_node; k++)
            {
                if(findset(k, parent)!=par_x)
                {
                    flag=0;
                    break;
                }
            }

            if(flag)
            {
                printf("%d\n", total_best);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}
