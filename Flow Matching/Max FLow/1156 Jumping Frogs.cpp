/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1156
Problem Name: 1156 - Jumping Frogs
Rank: 46
*/

/*
statement:
With the increased use of pesticides, the local streams and rivers have become so contaminated that it has become almost impossible for the
aquatic animals to survive.Frog Fred is on the left bank of such a river. N rocks are arranged in a straight line from the left bank to the
right bank. The distance between the left and the right bank is D meters. There are rocks of two sizes. The bigger ones can withstand any
weight but the smaller ones start to drown as soon as any mass is placed on it. Fred has to go to the right bank where he has to collect a
gift and return to the left bank where his home is situated.He can land on every small rock at most one time, but can use the bigger ones
as many times as he likes. He can never touch the polluted water as it is extremely contaminated.Can you plan the itinerary so that the
maximum distance of a single leap is minimized?

/*
Solution Method:
first we consider every stone as a node. then connect those nodes with source node. the capacity of the edges butween stone nodes and source node
will be theassigned this way: if the stone is small then it has capacity 1,otherwise capacity will be infinity.
then we check every possible pairs of stone nodes that if the distance between these nodes is less than or equal to D. if it is then ocnnect them
with edge, which capacity will be a large number.
then we use Binary search to find out minimum distance by sending flow on this network. In binary search we apply Max Flow method on the network.
if the minimum flow of the network is less than 2 that means it is not possible to go to the other side and return back. if it is more than 2
then we decrease the higher limit of Binary search. otherwise increase lower limit.
in such way we can find the minimum flow of the network.
that will be the minimum distance for frog to jump
*/

/*
Complexity Analysis:
The running time of O(V*E^2) is found by showing that each augmenting path can be found in O(E) time, that every time at least one of the E edges
becomes saturated, that the distance from the saturated edge to the source along the augmenting path must be longer than
last time it was saturated, and that the length is at most V.
Binary Serch can be done with O(log(D)) time.
so the final complexity will be O(log(D)*(V*E^2));
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


#define MAX 50005

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
#define pq priority_queue

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


int cap[205][205], par[205], source, sink, flow, tmp[205][205];
struct tt
{ int nd, val;
    tt(int x, int y)
    { nd=x, val=y;}
};
vector<tt>adj[205]; vector<int>dist;

bool aug_path(int mid)
{
    int i, u, v, now;
    queue<int>Q;
    Q.push(source);
    memset(par, -1, sizeof par);
    while(!Q.empty())
    {
        u = Q.front(), Q.pop();
        for(i=0;i<SZ(adj[u]);i++)
        {
            v = adj[u][i].nd, now = adj[u][i].val;
            if(par[v]==-1 && cap[u][v]>0 && now<=mid)
            {
                par[v] = u;
                Q.push(v);
                if(v==sink)
                    return true;
            }
        }
    }
    return false;
}

void path_update(int v)
{
    int u = par[v];
    flow = min(flow, cap[u][v]);
    if(u!=source) path_update(u);
    cap[u][v]-=flow;
    cap[v][u]+=flow;
    return;
}

int maxflow(int mid)
{
    int ret=0;
    while(aug_path(mid))
    {
        flow=INF;
        path_update(sink);
        ret+=flow;
        if(ret>=2) break;
    }
    return ret;
}

int binarySearch(int d)
{
    int low, high, mid, now, i, j;
    low = 0, high = d;

    while(low<high)
    {
        for(i=0;i<204;i++)
            for(j=0;j<204;j++) tmp[i][j] = cap[i][j];

        mid = (low+high)/2;
        now = maxflow(mid);
//        deb(low, mid, high, now, "maxFlow");
        if(now>=2)
            high = mid;
        else
            low = mid+1;

        for(i=0;i<204;i++)
            for(j=0;j<204;j++) cap[i][j] = tmp[i][j];
    }
    return high;
}

int main()
{
    int t=0, tcase;
    scanf("%d", &tcase);
    REP(t, tcase)
    {
        int n, d, i, j, k, dd; char c;

        dist.clear(); memset(cap, 0, sizeof cap);
        for(i=0;i<204;i++) adj[i].clear();

        scanf("%d%d", &n, &d); source=0;
        for(i=0;i<n;i++)
        {
            scanf(" %c-%d", &c, &dd);
            dist.pb(dd);

            adj[source].pb(tt(i+1, dd));
            adj[i+1].pb(tt(source, dd));

            cap[source][i+1] = INF;

            adj[i+1].pb(tt(i+n+1, 0));
            adj[i+n+1].pb(tt(i+1, 0));
            if(c=='B')
                cap[i+1][i+n+1] = INF;
            else
                cap[i+1][i+n+1] = 1;
        }
        for(i=0;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                adj[i+1+n].pb(tt(j+1, abs(dist[i]-dist[j])));
                adj[j+1].pb(tt(i+1+n, abs(dist[i]-dist[j])));

                adj[j+1+n].pb(tt(i+1, abs(dist[i]-dist[j])));
                adj[i+1].pb(tt(j+1+n, abs(dist[i]-dist[j])));

                cap[i+1+n][j+1] = INF;
                cap[j+1+n][i+1] = INF;
            }
        }
        sink = 203;
        for(i=0;i<n;i++)
        {
            adj[i+1+n].pb(tt(sink, d-dist[i]));
            adj[sink].pb(tt(i+1+n, d-dist[i]));
            cap[i+1+n][sink] = INF;
        }
        int ans = binarySearch(d);
        printf("Case %d: %d\n",t+1,  ans);
    }
    return 0;
}
