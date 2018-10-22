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
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

template<class T1> void deb(T1 e){cout<<e<<endl;}
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
#define fs first
#define sc second
#define LL long long int
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
#define EPS 10E-5
#define MAX 10005

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
VI adj[MAX], trans[MAX], S;
bool color[MAX];
int num_node, num_edge, cnt;

int dfs(int from)
{
    int i, to;

    color[from]=1;

    for(i=0; i<SZ(adj[from]); i++)
    {
        to= adj[from][i];
        if(color[to]==0)
        {
            dfs(to);
        }
    }
    S.pb(from);
}

int dfs_2(int from)
{
    printf("dfs: %d\n", from);
    int to, w, i;
    color[from]=1;
    for(i=0; i<SZ(trans[from]); i++)
    {
        to= trans[from][i];
        if(color[to]==0)
        {
            dfs_2(to);
        }
    }
}



void SCC(void)
{
    int i, j,k, from, to;
    cnt=0;
    S.clear();
    CLR(color);
    for(i=1; i<=num_node; i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }
    CLR(color);
    for(i=0; i<SZ(S); i++)
        printf("%d ", S[i]);

    for(i=SZ(S)-1, cnt=0; i>=0; i--)
    {
        from= S[i];
        if(color[from]==0)
        {
            printf("\ncall 2nd dfs: [%d]---\n", from);
            dfs_2(from);
            cnt++;
        }
    }
//    printf("[%d]", cnt);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase,a, b, t, i, j, k;
    cin>>tcase;

    for(t=1; t<=tcase; t++)
    {
        cin>>num_node>>num_edge;
        for(i=0; i<num_edge; i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            trans[b].pb(a);
        }
        SCC();
        printf("Case %d: %d\n", t, cnt);
        for(i=0; i<=num_node; i++)
        {
            adj[i].clear();
            trans[i].clear();
        }
    }
    return 0;
}
