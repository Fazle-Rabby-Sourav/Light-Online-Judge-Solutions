/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1404
Problem Name: 1404 Sending Secret Message
Rank: 35
*/

/*
Statement:
Alice wants to send Bob some confidential messages. But their internet connection is not secured enough.
As their names have been used in many networking schemes, they are very rich now. So, they don't want to
send encoded messages, they want to use secured dedicated connection for them. So, they talked to some ISPS
(Internet Service Providers) about their problem. Only they get is that there are N routers in the network,
some of them share bidirectional links. Each link has a capacity, and for each KB of data passing through this
link, they have to pay some money. Assume that Alice is connected with the 1st router and Bob is connected to
the Nth router
*/

/*
Solution Method:
here it is Give that node 1 is the source and node N is sink. we need to send P data from source to sink.
the problem is to find the minimum money needed for sending that data.

we can apply min cost max flow problem with some modification. every time we try to send flow on a
valid augmenting path. If that is possible then we decrease that amount flow from P. we need to do same
precess untill there is no augmenting path or all data are sent. if there is no augmenting pathe before
all data are sent then it is impossible to send that amount of data.
other wise we calculate money that are needed to send data from source to destination by multiplying
the flow with total money needed per byte for that path.
thus we can get the solution.
*/

/*
Complexity Analysis:
complexity wll be approximately O(n^2*m*log(n));
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


#define MAX 305

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
//template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

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
#define pb(x) push_back(x)

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

///**biwise operation**/
//#define two(X)          (1<<(X))
//#define twoL(X)         (((ll)(1))<<(X))
//#define setBit(mask,i)  (mask|two(i))
//#define contain(S,X)    (((S)&two(X))!=0)
//#define containL(S,X)   (((S)&twoL(X))!=0)
//#define popc(i) (__builtin_popcount(i))

#define csprint printf("Case %d: ", ++t);
#define PI acos(-1)
#define ERR 10E-5

const int INF = 0x7f7f7f7f;

//
/////** debugging**/
////#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
////#define bugg(x, y) cout<<"->"<<#x<<": "<<x<<"\t\t"<<#y<<": "<<y<<endl;
////#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
////struct debugger
////{    // Taken from rudradevbasak
////    template<typename T> debugger& operator , (const T& v)    {        cerr<<v<<" ";        return *this;    }
////} dbg;

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

//double deg2rad(double x){ return (PI*x)/180.0; }
//double rad2deg(double x){ return (180.0*x)/PI; }

//prime check
template<class T> inline bool isPrime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
//int,double is converted to string
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//string is converted to int
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//string is converted to Long long
bool IsVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
//isUpperCase
bool isUpper(char c){return c>='A' && c<='Z';}
//isLowerCase
bool isLower(char c){return c>='a' && c<='z';}
//compute b^p
ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
//compute b^p%m
int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
//print a number in binary format with n length
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);reverse(ALL(s) );s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
//ASCII Chart
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


struct pq{
    int cost, node;
    pq(int x, int y) { node=x, cost=y;}
    bool operator<(const pq &b)const
    {return (cost>b.cost);}
};

vector<pq> adj[MAX];


int source, sink, flow, N, M, Byte, dist[MAX], cap[MAX][MAX], par[MAX];


void addedge(int u, int v, int w, int c)
{
    adj[u].pb(pq(v, w)); adj[v].pb(pq(u, -w));
    cap[u][v] = c; cap[v][u]=0;
}



bool aug_path()
{
    int i, from, to, fc, tc;

    for(i=0;i<MAX;i++)
        dist[i]=INF;
    mset(par, -1);
    dist[source] = 0;

    priority_queue<pq>Q;
    Q.push(pq(source, 0));

    while(!Q.empty())
    {
        from = Q.top().node, fc = Q.top().cost; Q.pop();
        for(i=0;i<SZ(adj[from]);i++)
        {
            to = adj[from][i].node, tc = adj[from][i].cost;
            if((dist[to] > (tc+fc)) && (cap[from][to]>0))
            {
                dist[to] = fc+tc;
                par[to] = from;
                Q.push(pq(to, dist[to]));
            }
        }
    }
    if(dist[sink]!=INF) return true;
    return false;
}

void path_update(int now){
    int pre, cst;
    pre= par[now];
    flow= min(flow, cap[pre][now]);
    if(pre!= source)
        path_update(pre);

    cap[pre][now]-= flow;
    cap[now][pre]+= flow;
}

int maxFlow()
{
    int ret=0, tot=0;
    while(Byte>0)
    {
        if(!aug_path()) break;
        flow=INF;
        path_update(sink);
        ret+=(dist[sink]*min(flow, Byte));
        Byte-= flow;
    }

//    deb(Byte, "before Return");
    if(Byte<=0) return ret;
    else
        return -1;
}



int main()
{
    int i, j, k, x, y, z, u, v, w, a, b, c, tcase, t, m, n, cnt=0, result=0;

    cin>>tcase;
    REP(t, tcase)
    {
        REP(i, MAX)   adj[i].clear();
        CLR(cap);

        cin>>N>>M>>Byte;
        for(i=1; i<=N; i++)
        {
            addedge(i, i+N, 0, INF);
        }

        REP(i, M)
        {
            scanf("%d %d %d %d", &u, &v, &c , &w);
            addedge(u+N, v, w, c);
            addedge(v+N, u, w, c);
        }
        source=1; sink= N;

        result= maxFlow();

        if(result==-1)
            printf("Case %d: impossible\n", t+1);
        else
            printf("Case %d: %d\n",t+1, result);
    }
    return 0;
}
