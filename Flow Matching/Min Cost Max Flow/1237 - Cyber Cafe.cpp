/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1237
Problem Name: 1237 Cyber cafe
Rank: 38
*/

/*
Statement:
In his café he maintains two papers for his customers. One paper contains the entering times of the customers in the
café and the other paper contains the times they have exited. He writes the times in the same order in the papers for the
money calculations. And he only writes the nearest minute of the time. He writes the times from 0 to 1000 (0 means 12:00 am,
60 means 01:00 am, 730 means 02:10 pm). This idea was given by his little son.
When a person exits the café he was to pay some money. If he stays in the café for T minutes, he has to pay (T-K)2
paisa but not more than G paisa (if money exceeds G). It's guaranteed that every person stays at least one minute in the café.
Now one day his little son came to the café and took the paper that contained the entering times of the customers.
He took a new paper and wrote the entering times randomly and threw the old paper. When his father came, he found two papers,
where the first one contained some random entering times. He was at a loss and angry. Cause how can he find the total money
given by the customers since for an entering time there can be multiple exiting times.
So, finally he realized the importance of ACM in life and asked you to find the minimum and maximum money he could earn by
matching all entering times and exiting times. His son can be faulty. So, you have to report that too.
*/

/*
Solution Method:
Its a variation Min-Cost Max-Flow problem with some tricky case. First we need to build network with a source
and a sink.. then Connect them with weighted age. weher weight is the edge will be ((T-K)2 ). here T is the time of
staying at Cafe and K is given. Then we will check if there is an augmenting path or not.
 if there exist any augmenting path then we send flow on that path. then we update the path unltill
 there is no such augmentig path. For finding shortest path I have used dijkstra Algo as the edges are weightrd.

 if there is an augmenting path then the distance of the sink from source will be added with result.
 Thus we we get the final result
*/


/*
Complexity Analysis:
the number of augmentation step is O(V*E) where V is number of nodes and E is number of edges
complexity of dikjstra algo is O(E+VlogV)....so the complexity wll be approximately O(V^2*E*log(V))
*/

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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define INF (1<<30)
#define pii pair<int, int>

///**biwise operation**/
//#define two(X)          (1<<(X))
//#define twoL(X)         (((ll)(1))<<(X))
//#define setBit(mask,i)  (mask|two(i))
//#define contain(S,X)    (((S)&two(X))!=0)
//#define containL(S,X)   (((S)&twoL(X))!=0)
//#define popc(i) (__builtin_popcount(i))


////prime check
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


using namespace std;

int cap[205][205], par[205], source, sink, flow, dist[205], arr[105];

struct pq{
    int cost, node;
    pq(int x, int y) { node=x, cost=y;}
    bool operator<(const pq &b)const
    {return (cost>b.cost);}};
vector<pq>adj[205];

void addedge(int u, int v, int w, int c)
{
    adj[u].pb(pq(v, w)); adj[v].pb(pq(u, -w));
    cap[u][v] = c; cap[v][u]=0;
}

long long sqr(int x)
{ long long ret = (x*x); return ret;}

void MakeGraph(int n, int g, int k)
{
    int i, j, nodes=n*2; source=0, sink=203;
    long long val;
    for(i=0;i<204;i++) adj[i].clear();
    memset(cap, 0, sizeof cap);
    for(i=1;i<=nodes;i++)
        addedge(i, i+nodes, 0, 1);
    for(i=1;i<=n;i++)
        addedge(source, i, 0, INF);
    for(i=n+1;i<=nodes;i++)
        addedge(i+nodes, sink, 0, INF);
    return;
}


bool aug_path()
{
    int i, now, nxt, nc, xc;
    priority_queue<pq>Q;
    Q.push(pq(source, 0));
    for(i=0;i<204;i++) dist[i]=INF;
    memset(par, -1, sizeof par);
    dist[source] = 0;
    while(!Q.empty())
    {
        now = Q.top().node, nc = Q.top().cost; Q.pop();
        for(i=0;i<SZ(adj[now]);i++)
        {
            nxt = adj[now][i].node, xc = adj[now][i].cost;
            if((dist[nxt] > (xc+nc)) && (cap[now][nxt]>0))
            {
                dist[nxt] = nc+xc;
                par[nxt] = now;
                Q.push(pq(nxt, nc+xc));
            }
        }
    }
    if(dist[sink]!=INF) return true;
    return false;
}


void path_upd(int v)
{
    int u = par[v];
    flow = min(flow, cap[u][v]);
    if(u!=source) path_upd(u);
    cap[u][v]-=flow;
    cap[v][u]+=flow;
    return;
}

int MaxFlow(int n)
{
    int ret=0, tot=0;
    while(aug_path())
    {
        flow=INF;
        path_upd(sink);
        ret+=(dist[sink]);
        tot+=flow;
    }
    if(tot==n)
        return ret;
    else return -1;
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, g, i, j, nodes; int val, mn=-1, mx=-1;
        scanf("%d%d%d", &n, &k, &g);
        for(i=1;i<=(2*n);i++)
            scanf("%d", &arr[i]);
        MakeGraph(n, k, g); nodes=2*n;
        for(i=1;i<=n;i++)
        {
            for(j=(n+1);j<=nodes;j++)
            {
                if(arr[i]<arr[j])
                {
                    val = sqr((arr[j]-arr[i])-k);
                    addedge(i+nodes, j, min(val, g), 1);
                }
            }
        }
        int ans = MaxFlow(n);
        mn = ans;
        if(mn!=-1)
        {
            MakeGraph(n, k, g);
            for(i=1;i<=n;i++)
            {
                for(j=(n+1);j<=nodes;j++)
                {
                    if(arr[i]<arr[j])
                    {
                        val = sqr((arr[j]-arr[i])-k);
                        addedge(i+nodes, j, (-(min(val, g))), 1);
                    }
                }
            }
            ans = MaxFlow(n);
            mx = -1*ans;
        }
        csprnt;
        if(mn==-1 || mx==-1)
            printf("impossible\n");
        else
            printf("%d %d\n", mn, mx);
    }
    return 0;
}
