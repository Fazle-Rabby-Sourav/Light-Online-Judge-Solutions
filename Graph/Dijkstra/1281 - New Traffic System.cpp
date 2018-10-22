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

#define MAX 10005

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define REP(i,n)        for (i=0;i<n;i++)
#define FOR(i,p,k)      for (i=p; i<k;i++)
#define FORE(i, p, k)   for(i=p; i<=k; i++)
#define FOREACH(it,x)   for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define READ(f)     freopen(f, "r", stdin)
#define WRITE(f)    freopen(f, "w", stdout)
#define REV(s, e)   reverse(s, e)

#define CLR(p)      memset(p, 0, sizeof(p))
#define mset(p, v)  memset(p, v, sizeof(p))
#define ALL(c)      c.begin(), c.end()
#define SZ(c)       (int)c.size()
#define pb(x)       push_back(x)

//Type Definition
//typedef long long ll;
//typedef pair<int,int> pii;
//typedef vector<int> vi;
//typedef vector<vi>vvi;
//typedef vector< pair<int , int> > vii;
//typedef vector<string> vs;
//typedef map<string,int> msi;
//typedef map<int,int>mii;

///#define type
#define ll  long long int
#define vs  vector<string>
#define vi  vector<int>
#define vii vector< pair<int, int> >
#define pii pair< int, int >
#define psi pair< string, int >

#define fs  first
#define sc  second
#define MP(x, y)    make_pair(x, y)
#define pq  priority_queue

#define LOG(x,BASE) (log10(x)/log10(BASE))
#define EQ(a,b)     (fabs(a-b)<ERR)

//#define popc(i) (__builtin_popcount(i))

#define csprint printf("Case %d: ", ++t);
#define PI  acos(-1)
#define ERR 10E-5

const int INF = 0x7f7f7f7f;

template<class T> void deb(T e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T> void deb(vector<T> e){int i;REP(i,SZ(e)) cout<<e[i]<<" ";cout<<endl;}

//double deg2rad(double x){ return (PI*x)/180.0; }
//double rad2deg(double x){ return (180.0*x)/PI; }


ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
//compute b^p%m
int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


struct node{
    int v, w, used;

    node(){;}

    node(int vv, int ww, int uu)
    {
        v=vv;        w=ww;        used= uu;
    }
    bool operator < (const node &b) const {
        return (w>b.w);
    }
};

vector < node > adj[MAX];
int dist[MAX][11];
int n,m, mm, d;

int dijkstra(int st, int ed)
{

    priority_queue< node > Q;

    int i, j, k, to, from, fw, fu, tw, tu;

    REP(i, n)
        REP(k, 11)
            dist[i][k]= INF;

    dist[0][0]=0;
    Q.push(node(st, dist[0][0], 0));

    while(!Q.empty())
    {
        from=Q.top().v;
        fw= Q.top().w;
        fu= Q.top().used;
        Q.pop();
        for(i=0; i<SZ(adj[from]); i++)
        {
            to= adj[from][i].v;
            tw= adj[from][i].w;
            tu= adj[from][i].used;

            if( fu+tu<=d && dist[to][fu+tu]> fw+tw)
            {
                dist[to][fu+tu]= fw+tw;
                Q.push(node(to, dist[to][fu+tu], fu+tu));
            }
        }
    }
    int ret= INF;
    for(i=0; i<=d; i++)
    {
        ret= min(ret, dist[ed][i]);
    }

    return ret;
}

int main()
{
    int i, j, k, u, v, w, x, y, z, t=0, tcase, res=0;
    cin>>tcase;

    while(tcase--)
    {
        scanf("%d %d %d %d", &n, &m, &mm, &d);

        REP(i, m)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(node(v, w, 0));
        }
        REP(i, mm)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(node(v, w, 1));
        }

//    deb("call");
        res= dijkstra(0, n-1);

        if(res>=INF)
            printf("Case %d: Impossible\n", ++t);
        else
            printf("Case %d: %d\n", ++t, res);

        REP(i, MAX)
            adj[i].clear();
    }
    return 0;
}
