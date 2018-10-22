#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair

///**biwise operation**/
//#define two(X)          (1<<(X))
//#define twoL(X)         (((ll)(1))<<(X))
//#define setBit(mask,i)  (mask|two(i))
//#define contain(S,X)    (((S)&two(X))!=0)
//#define containL(S,X)   (((S)&twoL(X))!=0)
//#define popc(i) (__builtin_popcount(i))

/////** debugging**/
////#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
////#define bugg(x, y) cout<<"->"<<#x<<": "<<x<<"\t\t"<<#y<<": "<<y<<endl;
////#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
////struct debugger
////{    // Taken from rudradevbasak
////    template<typename T> debugger& operator , (const T& v)    {        cerr<<v<<" ";        return *this;    }
////} dbg;

//template<class T> void deb(T e){cout<<e<<endl;}
//template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
//template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
//template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
//template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
//
//template<class T> void deb(vector<T> e){int i;REP(i,SZ(e)) cout<<e[i]<<" ";cout<<endl;}
//template<class T> void deb(vector<T> e,int n){int i;REP(i,n) cout<<e[i]<<" ";cout<<endl;}
//template<class T> void deb(vector< basic_string<T> > e){int i,j;REP(i,SZ(e)) {REP(j,SZ(e[i])) cout<<e[i][j];cout<<endl;} cout<<endl;}
//template<class T> void deb(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
//template<class T> void deb(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<"\t";cout<<endl;} cout<<endl;}
//template<class T> void deb(T e[MAX][MAX],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
//template<class T> void deb(T e[],int row){int i;REP(i,row) cout<<e[i]<<" ";cout<<endl;}

//double deg2rad(double x){ return (PI*x)/180.0; }
//double rad2deg(double x){ return (180.0*x)/PI; }

//prime check
//template<class T> inline bool isPrime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
////int,double is converted to string
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
////string is converted to int
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
////string is converted to Long long
//bool IsVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
////isUpperCase
//bool isUpper(char c){return c>='A' && c<='Z';}
////isLowerCase
//bool isLower(char c){return c>='a' && c<='z';}
////compute b^p
//ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
////compute b^p%m
//int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
////print a number in binary format with n length
//void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);reverse(ALL(s) );s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
////ASCII Chart
//void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};

using namespace std;

struct node{
    int u, v, cap, revind;
    node(int c=0, int a=0, int b=0, int d=0)
    {
        u=c, v=a, cap=b, revind=d;
    }
}; node edge[400000];

vector<int>adj[20010];
vector<pii>ed;
int source, sink, parInd[20010], flow, edgeNum;
char grid[105][105];

void addedge(int u, int v, int cap)
{
    edge[edgeNum] = node(u, v, 1, edgeNum+1);
    adj[u].pb(edgeNum);
    edge[edgeNum+1] = node(v, u, 0, edgeNum);
    adj[v].pb(edgeNum+1);
    edgeNum+=2;
}

bool aug_path()
{
    int i, u, used=0;
    queue<int>Q;
    Q.push(source);
    memset(parInd, -1, sizeof parInd);
    parInd[source] = -2;
    while(!Q.empty())
    {
        u = Q.front(), Q.pop();
        for(i=0;i<SZ(adj[u]);i++)
        {
            node now = edge[adj[u][i]];
            if(parInd[now.v]==-1 && now.cap>0)
            {
                parInd[now.v] = adj[u][i];;
                if(now.v!=sink) Q.push(now.v);
            }
        }
    }
    return (parInd[sink]!=-1);
}

void path_update(int v)
{
    node now = edge[parInd[v]];
    flow = min(flow, now.cap);
    if(now.u!=source) path_update(now.u);
    edge[parInd[v]].cap -= flow;
    edge[now.revind].cap += flow;
    return;
}

bool maxflow(int cnt)
{
    int i, u, v, j, ret=0;

    while(aug_path())
    {
        for(i=0;i<SZ(ed);i++)
        {
            u = ed[i].first, j = ed[i].second;
            if(parInd[u]==-1) continue;
            if(edge[j].cap<=0) continue;

            parInd[sink] = j;
            flow=INF;
            path_update(sink);
            ret+=flow;
            if(ret==cnt) return true;
        }
    }
    return false;
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        edgeNum=0;
        int N, M, i, j, k, nodes, nx, ny, u, v;
        int req=0;

        scanf("%d%d ", &N, &M);
        for(i=0;i<N;i++)
            scanf("%s", grid[i]);

        nodes = N*M; ed.clear();
        source=0, sink = 2*nodes + 1;
        for(i=0;i<=sink;i++) adj[i].clear();

        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                u = (i*M)+j+1;
                addedge(u, u+nodes, 1);
                if(grid[i][j]=='*')
                {
                    addedge(source, u, 1);
                    req++;
                }
                if(i==0 || i==N-1 || j==0 || j==M-1)
                {
                    addedge(u+nodes, sink, 1);
                    ed.pb(MP(u+nodes, edgeNum-2));
                }
                for(k=0;k<4;k++)
                {
                    nx = i+dx[k], ny = j+dy[k];
                    if(nx<0 || nx==N || ny<0 || ny==M) continue;
                    v = (nx*M)+ny+1;
                    addedge(u+nodes, v, 1);
                }
            }
        }
        int sol = maxflow(req);
        csprnt;
        if(sol) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
