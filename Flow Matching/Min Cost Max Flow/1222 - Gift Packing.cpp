/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1149
Problem Name: 1222 Gift Packing
Rank: 68
*/


/*
problem overview:
There are n gifts and n boxes, each box can contain at most one gift. Now you want to pack all the gifts in the boxes
 such that your profit is as high possible.

The boxes are numbered from 1 to n and the gifts are numbered from 1 to n. You will be given an (n x n) matrix
where pij denotes the profit if we put the ith gift into the jth box. Now your task is to pack all the gifts and maximize
the profit.
*/


/*
solution method:

From the straightforeward statement we can easily identify the problem as a mi cost max flow problem. here are some box and some gift
if we assume boxes and gift as nodes and their relation as edges then the profit assosiated with a gift and box is the cost of edges.
we define a single node aa source and connect edges betweenn all gift nodes with source node. the cost of those node will be 0;
and define a single node as sink. and connect all gift nodes with sink.

then we run maxFlow implementation with Dijkstra for finding augmenting Path. by calculating cost of each cugmenting path with
corresponding profit. we can get total maximum profit.
*/

/*
complexity Analysis:
the number of augmentation step is O(n*m) where n is number of node and m is number of edge
complexity of dikjstra algo is m+nlogn
so the complexity wll be approximately O(n^2*m*log(n))
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

using namespace std;


#define MAX 250

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

#define REP(i,n)for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FORE(i, p, k) for(i=p; i<=k; i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FORD(i,n)    for(i=n;i>=0;i--)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define REV(s, e) reverse(s, e)

#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb push_back

///#define type
#define ll long long int
#define vs vector<string>
#define vi vector<int>
#define vii vector< pair<int, int> >
#define pii pair< int, int >
#define psi pair< string, int >

#define fs first
#define sc second
#define MP(x, y) make_pair(x, y)
//#define pq priority_queue

#define LOG(x,BASE) (log10(x)/log10(BASE))
#define EQ(a,b)     (fabs(a-b)<ERR)

#define csprint printf("Case %d: ", ++t);
#define PI acos(-1)
#define ERR 10E-5

const int INF = 0x7f7f7f7f;

template<class T> void deb(T e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}

template<class T> void deb(vector<T> e){int i;REP(i,SZ(e)) cout<<e[i]<<" ";cout<<endl;}
template<class T> void deb(vector<T> e,int n){int i;REP(i,n) cout<<e[i]<<" ";cout<<endl;}
template<class T> void deb(vector< basic_string<T> > e){int i,j;REP(i,SZ(e)) {REP(j,SZ(e[i])) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void deb(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void deb(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<"\t";cout<<endl;} cout<<endl;}
template<class T> void deb(T e[MAX][MAX],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> void deb(T e[],int row){int i;REP(i,row) cout<<e[i]<<" ";cout<<endl;}

int n, m, nodes, source, sink, min_flow;
int cap[MAX][MAX], dist[MAX], par[MAX];

struct pq{
    int cost, node;
    pq(int x, int y) { node=x, cost=y;}
    bool operator<(const pq &b)const
    {return (cost>b.cost);}};

vector < pq > adj[MAX];


bool exist_aug_path()
{
    int i, j, k, from, to, res=0, from_node, from_cost;
    priority_queue < pq > Q;

    REP(i, MAX)  dist[i]= INF;
    CLR(par);

    dist[source]=0;
    Q.push(pq(source, dist[source]));

    while(!Q.empty())
    {
        from_node= Q.top().node; from_cost=  Q.top().cost;
        Q.pop();

        REP(i, SZ(adj[from_node]))
        {
            int to_node= adj[from_node][i].node;
            int cst= adj[from_node][i].cost;

            if(dist[to_node]> dist[from_node]+cst && cap[from_node][to_node]>0 ){

                dist[to_node]= dist[from_node]+cst;
                par[to_node]= from_node;
                Q.push(pq(to_node, dist[to_node]));
            }
        }
    }
    if(dist[sink]==INF) return false;
    return true;
}


void path_update(int now){
    int pre, cst;
    pre= par[now];
    min_flow= min(min_flow, cap[pre][now]);
    if(pre!= source)
        path_update(pre);

    cap[pre][now]-= min_flow;
    cap[now][pre]+= min_flow;
}


int maxflow()
{
    int i, j, k=0, res=0;

    while(exist_aug_path())
    {
        k++;
        min_flow= INF;
        path_update(sink);
//        deb(k, min_flow, dist[sink]);
        res+= (min_flow*dist[sink]);
    }
    return res;
}


void addedge(int u, int v, int w, int c)
{
    adj[u].pb(pq(v, -w)); adj[v].pb(pq(u, w));
    cap[u][v]= c; cap[v][u]=0;
}


int main()
{
    int i, j, k, u, v, a, b, c, x, w, tcase, t=0, result;
    vi arr;
    cin>>tcase;
    REP(t, tcase)
    {
        cin>>n;
        CLR(cap); REP(i, MAX) adj[i].clear();

        nodes= 2*n;
        source=0; sink= 202;

        for(i=1; i<=n; i++)
            addedge(source, i, 0, INF);

        for(i=0; i<= n; i++)
            addedge(i, i+n, 0, 1);
//
//        for(i=1; i<=n; i++)
//            addedge(i, i+nodes, 0, 1);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin>>w;
                addedge(i+n, j+nodes, w, 1);
            }
        }

        for(i=1; i<=n; i++)
            addedge(i+nodes, sink, 0, 1);

        result= maxflow();
        result= -result;
        printf("Case %d: %d\n", t+1, result);
    }
    return 0;
}

