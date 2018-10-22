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

#define MAXN 505

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

struct edge {
    int v, w;
    edge(){}
    edge(int vv, int ww)
    {
        v= vv; w=ww;
    }
};

struct vert {
    int node, w;
    vert(){}
    vert(int nn, int ww)
    {
        node= nn; w=w;
    }
    bool operator < (const vert &b) const
    {
        return w>b.w;
    }
};

int N, M, S;
vi shop;
int dist[17][MAXN], t=0;
int DP[17][(1<<17)+5];
pii dp[17][(1<<17)+5];

vector< edge > adj[MAXN];

void dijkstra(int src)
{
    int i, j, k, to, from, tw, fw;
    priority_queue < vert > Q;

    REP(i, N+5) dist[src][i]=INF;

    dist[src][shop[src]]=0;
    Q.push(vert(shop[src], dist[src][shop[src]]));

    while(!Q.empty())
    {
        from= Q.top().node;
        fw= Q.top().w;
        Q.pop();
        REP(i, SZ(adj[from]))
        {
            to= adj[from][i].v;            tw= adj[from][i].w;
            if(dist[src][to]>dist[src][from]+tw)
            {
                dist[src][to]= dist[src][from]+tw;
                Q.push(vert(to, dist[src][to]));
            }
        }
    }
    return;
}

pii rec(int pre, int mask)
{
    int s= SZ(shop), i;
//    deb(pre, "start");

    if(pre==s-1)
    {
//        deb("return");
        return MP(0, 0);
    }

    pii &ret= dp[pre][mask];
    int &RET= DP[pre][mask];
    if(RET==t)  return ret;

    RET= t;
    ret= MP(0, INF);

    for(i=0; i<s; i++)
    {
        if( ((1<<i)&mask) ==0 && dist[pre][shop[i]]<INF  )
        {
            pii tmp;
//            deb(pre, i , "to-------");
            tmp= rec(i, (mask|(1<<i)));
            tmp.fs += 1;

            if(tmp.sc>=INF) continue;
            tmp.sc += dist[pre][ shop[i] ];

//            deb(pre, i, tmp.fs, tmp.sc, "inside return");
            if(tmp.fs>ret.fs)
            {
                ret= tmp;
            }
            else if(ret.fs==tmp.fs && tmp.sc<ret.sc)
            {
                ret= tmp;
            }
        }
    }
//    deb(pre, ret.fs, ret.sc, mask, "end");
    return ret;
}

int main()
{
    int i, j, k, u, v, w, x, y, z, tcase, cnt=0;
    pii res;
    CLR(DP);
    cin>>tcase;
    while(tcase--)
    {
        t++;
        scanf("%d %d %d", &N, &M, &S);
        shop.clear(); cnt=0;
        REP(i, S)
        {
            scanf("%d", &x);
            shop.pb(x);
        }
        sort(ALL(shop));

        if(shop[0]!=0)  shop.pb(0), cnt++;
        if(shop[SZ(shop)-1]!=N-1) shop.pb(N-1), cnt++;

        sort(ALL(shop));

        REP(i, M)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(edge(v, w));
        }

        REP(i, SZ(shop))
        {
            dijkstra(i);
//            REP(k, SZ(shop))
//                deb(shop[i], shop[k], dist[i][shop[k]] );
        }

//        deb("ok");

        REP(i, 17) REP(k, (1<<17)+4 )   dp[i][k]= MP(-1, -1);

        res= rec(0, 1);
        res.fs+= 1;
        if(res.sc>=INF)
            printf("Case %d: Impossible\n", t);
        else
            printf("Case %d: %d %d\n", t, res.fs-cnt , res.sc);

        REP(i, N+1)
            adj[i].clear();
    }
    return 0;
}
