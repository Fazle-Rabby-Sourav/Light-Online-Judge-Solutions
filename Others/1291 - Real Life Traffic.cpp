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

#define MAXN 10005

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

vi adj[MAXN];
int low[MAXN], tym[MAXN], col[MAXN], T, cnt, grp[MAXN], deg[MAXN], n, m;

stack < int > S;

void BCC(int start)
{
    int i, j, k, now;
    while(!S.empty())
    {
        now= S.top();        S.pop();
        grp[now]= cnt;
        if(now==start) break;
    }
    cnt++;
    return;
}

void dfsArticulation(int u, int par)
{
//    deb(u, "dfs starts");
    int i, j, k, v;
    low[u]= tym[u]= T++;
    S.push(u);
    REP(i, SZ(adj[u]))
    {
        v= adj[u][i];
        if(v==par)  continue;
        if(col[v]==false)
        {
            col[v]=true;
            dfsArticulation(v, u);
            low[u]= min(low[u], low[v]);
        }
        else
            low[u]= min(low[u], tym[v]);
    }
//    deb(u, tym[u], low[u]);
    //starting node of a BCC
    if(tym[u]== low[u])
    {
//        deb(u, "bcc call");
        BCC(u);
    }
    return;
}



int main()
{
    int i, j, k, u, v, w, x, y, z, t=0, res, tcase;
    cin>>tcase;
    while(tcase--)
    {
        scanf("%d %d", &n, &m);
        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        T=0; CLR(tym); CLR(grp); CLR(low); CLR(col); cnt=0;
        while(!(S.empty()))
            S.pop();

        col[0]=true;
        dfsArticulation(0, 0);

        CLR(deg);
        REP(i, n)
        {
            REP(k, SZ(adj[i]))
            {
                u= i;  v= adj[u][k];
                if(grp[u]!=grp[v])
                    deg[grp[v]]++;
            }
        }
        res=0;
        REP(i, cnt)
        {
            if(deg[i]==1) res++;
        }
        printf("Case %d: %d\n", ++t, (res+1)/2);
        REP(i, MAXN)    adj[i].clear();
    }
    return 0;
}
