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

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FORE(i, p, k) for(i=p; i<k; i++)
#define FORN(i, p, k) for(i=p; i>=0; i--)
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
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define PI acos(-1)
#define MAX 50010

const int INF = 99999999;

int num_node, city[MAX], start_city, dest_city, par[MAX];
vector < int > edge_list[MAX], path;
bool taken[MAX];



void BFS (int src)
{
    int i, j, k, from, to, w;
    queue < int > Q;
    CLR(taken);

    for(i=0; i<MAX; i++)
        par[i]  = 999999999;

    Q.push(src);
    par[src]= -1;
    taken[src]=1;

    while(!Q.empty())
    {
        from= Q.front();
        Q.pop();

        if(from==dest_city)
            return;

        for(i=0; i< SZ(edge_list[from]); i++)
        {
            sort(edge_list[from].begin(), edge_list[from].end());
            to= edge_list[from][i];
            if(taken[to]==0)
            {
                par[to]= from;
                taken[to]=1;
                Q.push(to);
            }
        }
    }
    return ;
}


int main()
{
    int tcase, t, i, j, k, dummy;
    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &num_node);
        dummy= -1;

        for(i=0; i<num_node; i++)
        {
            scanf("%d", &city[i]);
            if(dummy!=-1)
            {
                edge_list[city[i]].pb(dummy);
                edge_list[dummy].pb(city[i]);
            }
            dummy = city[i];
        }

        start_city= city[0];
        dest_city= city[num_node-1];

        BFS(start_city);

        path.clear();
        path.pb(dest_city);
        dummy = par[dest_city];
        int save;
        for(i=0; ; i++)
        {
            if(dummy!=-1)
            {
                path.pb(dummy);
            }
            else
                break;

            dummy = par[dummy];
        }
        reverse( path.begin(), path.end());

        printf("Case %d:\n", t);
        printf("%d", path[0]);
        for(i=1; i<SZ(path); i++)
            printf(" %d", path[i]);
        cout<<endl;

        for(i=0; i<=MAX; i++)
            edge_list[i].clear();
    }
    return 0;
}
