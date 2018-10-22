/*
/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1243
Problem Name: 1243 - Guardian Knights
Rank: 26
*/

/*
statement:
The kingdom of Azkaroth is in great danger. Some strange creatures have captured the city and attacking the poor inhabitants.
The old wise king has chosen his best knights to save the kingdom from these creatures. They have already found that
the creatures are targeting some food mills. So, the best way is to send the knights to look after the food mills.
And if anything goes wrong he may call others to attack the creatures.
The kingdom can be modeled as an n x n grid. The legends are:
'#'       denotes a rock
'.'         denotes an empty space
[A-Z]  denotes a knight
'm'      denotes a mill
A knight can go to a mill using some moves, in each move a knight can go to its four neighboring cells {North, East, West, South}
with the restriction that the destination cell shouldn't contain a rock (multiple knights can move together in a cell). And the
number of mills that can be maintained by a knight is limited. The cost to look after a mill by a knight is the distance
between the knight and the mill, distance means the number of moves the knight has to use to go to the mill. If a knight
looks after multiple mills, the cost is the summation of distances from the knight to the mills. Now your task is to find the
minimum total cost needed for the knights to look after all the mills. There can be more than one knight looking after a mill.
*/

/*
solution Method:
First I findout the co ordiante of every knight and mills. Assume every knight and mills as nodes. For determining the distance
of all mills from every knight, I have used BFS to find shortest distance. then I build a flow network where edges are weighted
and the weight of every edge is equal to the shortest distance between corresponding knight and mills. I define a node as sourced
node and another as sink node. then connect source to every knight nodes, and connect every kmill nodes with sink node.
then I have used min cost max flow on that network to get the desired result.
*/

/*
Complexity Analysis:
THe complexity of BFS algorithm is O(|V|+|E|).
the number of augmentation step is O(V*E) where V is number of nodes and E is number of edges
complexity of dikjstra algo is O(E+VlogV).  so the complexity wll be approximately O( (V+E) + (V^2*E*log(V)) )
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


#define MAX 160

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
//template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
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
#define pb push_back

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

vector <string> grid;
string str;

struct km{
    int x, y; char c;
    km(int xx, int yy, char cc){
        x=xx, y=yy, c=cc;
    }
};

struct pq{
    int cost, node;
    pq(int x, int y) { node=x, cost=y;}
    bool operator<(const pq &b)const
    {
        return (cost>b.cost);
    }
};

vector <km> mils, knight;
int source, sink, N, M, K, flow, par[MAX], dist[MAX];
int  d[40][40], taken[40][40],  cap[MAX][MAX];
vi knightEnergy;
vector <pq> adj[MAX];

bool comp(km a, km b)
{
    return a.c< b.c;
}

void addedge(int u, int v, int w, int c)
{
    adj[u].pb(pq(v, w)); adj[v].pb(pq(u, -w));
    cap[u][v] = c; cap[v][u]=0;
}

void BFS(int sx, int sy)
{
    int i, j, k, fx, fy, tx, ty, nx, ny;
    CLR(taken); CLR(d);
    queue < pii > Q;
    Q.push(MP(sx, sy));
    d[sx][sy]=0;

    while(!Q.empty())
    {
        fx= Q.front().fs; fy= Q.front().sc;        Q.pop();
        REP(i, 4)
        {
            tx= xx[i]+fx;
            ty= yy[i]+fy;

            if(tx<0 || tx>=N || ty<0 || ty>=N) continue;

            if((grid[tx][ty]!='#') && (taken[tx][ty]==0) )
            {
                taken[tx][ty]=1;
                Q.push(MP(tx, ty));
                d[tx][ty]= d[fx][fy]+1;
            }
        }
    }
    return;
}

bool aug_path()
{
    int i, from, to, fc, tc;
    priority_queue<pq>Q;
    Q.push(pq(source, 0));

    for(i=0;i<MAX;i++) dist[i]=INF;
    memset(par, -1, sizeof par);
    dist[source] = 0;

    while(!Q.empty())
    {
        from = Q.top().node, fc = Q.top().cost; Q.pop();
        for(i=0;i<SZ(adj[from]);i++)
        {
            to = adj[from][i].node, tc = adj[from][i].cost;
            if((dist[to] > (tc+fc)) && (cap[from][to]>0))
            {
                dist[to] = fc+tc;
                par [to]  = from;
                Q.push(pq(to, fc+tc));
            }
        }
    }
    if(dist[sink]!=INF) return true;
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

int maxFlow()
{
    int ret=0;
    while(aug_path())
    {
        flow=INF;
        path_update(sink);
        ret+=(flow*dist[sink]);
    }
    return ret;
}

int main()
{
    int i, j, k,x, u, v, w, a, b, c, tcase, t, m, n, cnt=0, result=0;
    cin>>tcase;
    REP(t, tcase)
    {
        cin>>N>>K>>M;
        mils.clear(); knight.clear(); knightEnergy.clear(); CLR(cap);
        REP(i, MAX) adj[i].clear();
        CLR(taken); CLR(d); mset(par, -1); mset(dist, -1); grid.clear();

        REP(i, N)
        {
            cin>>str;            grid.pb(str);
        }
        REP(i, K)
        {
            cin>>w;
            knightEnergy.pb(w);
        }

        REP(i, N)
        {
            REP(k, SZ(grid))
            {
                char ch ;
                str=grid[i];
                ch = str[k];

                if(str[k]>='A' && str[k]<='Z')
                    knight.pb(km(i, k, ch));
                else if(str[k]=='m')
                    mils.pb(km(i, k, ch));
            }
        }
        source=0; sink= MAX-1;
        sort(knight.begin(), knight.end(), comp);
        REP(i, SZ(knight))
        {

            BFS(knight[i].x, knight[i].y);
            c=  knightEnergy[i];
            addedge(source, i+1, 0, c);
            REP(k, SZ(mils))
            {
                w= d[mils[k].x][mils[k].y];
                if(w>0)
                    addedge(i+1, k+K+1, w, 1);
            }
        }

        for(i=1+K; i<= 1+K+SZ(mils); i++)
        {
            addedge(i, sink, 0, 1);
        }

        result= maxFlow();
        printf("Case %d: %d\n", t+1, result);
    }
    return 0;
}
