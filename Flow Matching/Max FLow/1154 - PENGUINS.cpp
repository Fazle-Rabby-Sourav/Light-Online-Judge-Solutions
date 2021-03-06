/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1154
Problem Name: 1154 Penguins
Rank: 59
*/


/*
Statement:
Somewhere near the South Pole, a number of penguins are standing on a number of ice floes. Being social animals, the penguins would
like to get together, all on the same floe. The penguins do not want to get wet, so they have use their limited jump distance to get
together by jumping from piece to piece. However, temperatures have been high lately, and the floes are showing cracks, and they get
damaged further by the force needed to jump to another floe. Fortunately the penguins are real experts on cracking ice floes, and know
exactly how many times a penguin can jump off each floe before it disintegrates and disappears. Landing on an ice floe does not damage
it. You have to help the penguins find all floes where they can meet.
*/

/*
Solution Method:
We consider each ice floes as a node. then we connect source node with these nodes. the weight of the edge will be the number of pwnguins
staying on corresponding ice floes. then we connect these nodes with another new set of nodes. the wight of these edges will be
number the penguin can jump on corresponding node. then we assume every nodes as sink. an then run Max Flow algorithm. If total flow on
these network is equal to the number of penguin then this node/ice floe can be the gathering point. otherwise not
*/

/*
Complexity Analysis:
each augmenting path can be found in O(E) time.  that every time at least one of the E edges becomes saturated that
the distance from the saturated edge to the source along the augmenting path must be longer than last time it was saturated,
 and that the length is at most V. So it will be O(V*E^2) . and every node is assumed to be sink . the length of the iteratiion is V.
 so the complexity will be O(V^2*E^2);.
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


#define MAX 210

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

int N;
double D;

struct fl{
    int x, y, num, val;
    fl(int xx, int yy, int nn, int vv){
        x= xx; y=yy; num=nn; val=vv;
    }
    double getDist(fl b){
        return sqrt(((x-b.x)*(x-b.x)*1.00)+((y-b.y)*(y-b.y)*1.00));
    }
};

vector <fl> arr;
vi adj[MAX], sol;
int sink, source, flow, cap[MAX][MAX], capTemp[MAX][MAX], par[MAX];

void addedge(int u, int v, int c)
{
    adj[u].pb(v); adj[v].pb(u);
    cap[u][v]= c; cap[v][u]= c;
}

bool aug_path()
{
    int i, u, v;
    queue<int>Q;
    Q.push(source);
    memset(par, -1, sizeof par);
    while(!Q.empty())
    {
        u = Q.front(), Q.pop();
        for(i=0;i<SZ(adj[u]);i++)
        {
            v = adj[u][i];
            if(par[v]==-1 && cap[u][v]>0)
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

int maxFlow()
{
    int i, j, k, ret=0;
    while(aug_path())
    {
        flow= INF;
        path_update(sink);
        ret+= flow;
    }
    return ret;
}


int main()
{
    int i, j, k,x,y, u, v, w, a, b, c, tcase, t, m, n, cnt=0, result=0;
    cin>>tcase;
    REP(t, tcase)
    {
        arr.clear(); REP(i, N) adj[i].clear();
        CLR(cap); CLR(capTemp);
        sol.clear();
        source= 0;
        int numPen=0;
//        cin>>N>>D;
        scanf("%d %lf", &N, &D);
        REP(i, N)
        {
//            cin>>x>>y>>c>>w;
            scanf("%d %d %d %d", &x, &y, &c, &w);
            arr.pb(fl(x, y, c, w));
            numPen+= c;
            adj[source].pb(i+1);
            cap[source][i+1]= c;
            adj[i+1].pb(i+N+1);
            adj[i+N+1].pb(i+1);
            cap[i+1][i+N+1]=w, cap[i+N+1][i+1]=w;
        }

        REP(i, N)
        {
           REP(k, N)
           {
               if(i==k) continue;
                double d= arr[i].getDist(arr[k]);
                if(d<=D)
                {
                    adj[i+N+1].pb(k+1);
                    adj[k+1].pb(i+N+1);
                    cap[i+N+1][k+1] = INF;
                }
           }
        }

        REP(i, SZ(arr))
        {
            REP(j, MAX)
                REP(k, MAX)
                    capTemp[j][k]= cap[j][k];

            sink= i+1;
            cnt= maxFlow();
            if(cnt==numPen)
                sol.pb(i);

            REP(j, MAX)
                REP(k, MAX)
                    cap[j][k]= capTemp[j][k];
        }
        printf("Case %d:", t+1);
        if(!SZ(sol))    printf(" -1\n");
        else
        {
            REP(i, SZ(sol)) printf(" %d", sol[i]);
            printf("\n");
        }
    }
    return 0;
}
