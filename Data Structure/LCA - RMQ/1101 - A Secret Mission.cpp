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


#define MAX 50010

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

double deg2rad(double x){ return (PI*x)/180.0; }
double rad2deg(double x){ return (180.0*x)/PI; }

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

string str;
int N, M, r, par[MAX], rank[MAX], lev[MAX], dist[MAX][18], anc[MAX][18];

vector < pair <int, pii > > edge, edgeMst;
vii adj[MAX];

void reset()
{
    int i;
    for(i=0; i<=N+2; i++)
    {
        par[i]= i;
        rank[i]=0;
    }
    return;
}

int findPar(int x)
{
    if(par[x]!=x)
        par[x]= findPar(par[x]);

    return par[x];
}

//void makeUnion(int u, int v)
//{
//    if(rank[u]>rank[v])
//        par[v]= u;
//    else
//        par[u]= v;
//
//    if(rank[u]==rank[v])
//        rank[u]++;
////    par[v]=par[u];
//return;
//}

void makeUnion(int u,int v)
{
    int a=findPar(u);
    int b=findPar(v);

    if(a!=b)
    {
        if(rank[a]<rank[b])
            swap(a,b);

        par[b]=a;

        if(rank[a]==rank[b])
            rank[a]++;
    }
}

bool comp(pair <int, pii > a, pair <int, pii >  b)
{
    return a.fs<b.fs;
}

void kruskal()
{
    int i, j, k, from, to, w, up, vp;
    sort(ALL(edge), comp);
    reset();

    for(i=0; i<SZ(edge); i++)
    {
        from= edge[i].sc.fs;
        to= edge[i].sc.sc;
        up= findPar(from);
        vp= findPar(to);
        w= edge[i].fs;

        if(up!=vp)
        {
            edgeMst.pb(MP(w, MP(from, to)));
            makeUnion(up, vp);
        }
    }
    return;
}

void edgeMake()
{
    int i, u, v, w;
    REP(i, N+3)
    {
        adj[i].clear();
    }

    REP(i, SZ(edgeMst))
    {
        u= edgeMst[i].sc.fs;
        v= edgeMst[i].sc.sc;
        w= edgeMst[i].fs;

        adj[u].pb(MP(w, v));
        adj[v].pb(MP(w, u));
    }
    return;
}

void dfs(int from, int p=-1)
{
    int to, i, w;

    for(i=0; i<SZ(adj[from]); i++)
    {
        to= adj[from][i].sc;
        w= adj[from][i].fs;

        if(to!=p)
        {
            dist[to][0]= w;
            anc[to][0]= from;
            lev[to]= lev[from]+1;

            dfs(to, from);
        }
    }
    return;
}

void LCA()
{
    int i, j, k;
    for(k=1; (1<<k)<=N ; k++)
    {
        for(i=1; i<=N; i++)
        {
            if(anc[i][k-1] != -1)
            {
                dist[i][k]= max( dist[i][k-1], dist[ anc[i][k-1] ][k-1] );
                anc[i][k]= anc[anc[i][k-1]][k-1];
            }
        }
    }
}


int query(int p, int q)
{
    int res, i, j, k;

    if(lev[p]<lev[q])
        swap(p, q);

    int _log=0;
    while((1<<_log)<=lev[p])
        _log++;

    _log--;

    res= -INF;
    for(i= _log; i>=0; i--)
    {
        if(lev[p]-( 1<<i )>=lev[q])
        {
            res= max(res, dist[p][i]);
            p= anc[p][i];
        }
    }

    if(p==q)    return res;

    for(i=_log; i>=0; i--)
    {
        if(anc[p][i]!=-1 && anc[p][i]!=anc[q][i])
        {
            res= max(res, max(dist[p][i], dist[q][i]));
            p= anc[p][i];
            q= anc[q][i];
        }
    }

    return max(res, max(dist[p][0], dist[q][0]));
}

int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    int x, y, i, j, k, result, t=0, tcase, n, m, cnt, w , q;
    cin>>tcase;
    while(tcase--)
    {
        edge.clear(); edgeMst.clear();
        scanf("%d %d", &N, &M);
        REP(i, M)
        {
            scanf("%d %d %d", &x, &y, &w);
            edge.pb(MP(w, MP(x, y)));
        }

        kruskal();
//
//        REP(i, SZ(edgeMst))
//        {
//            deb(edgeMst[i].sc.fs, edgeMst[i].sc.sc, edgeMst[i].fs);
//        }

//        r=edgeMst[0].sc.fs;
        edgeMake();

        CLR(par); CLR(lev); CLR(dist); mset(anc, -1);

        dfs(1);

//        REP(i, N+1)
//            deb(i, lev[i]);
        LCA();

        scanf("%d", &q);
        printf("Case %d:\n", ++t);
        REP(i, q)
        {
            scanf("%d %d", &x, &y);
            result= query(x, y);

            printf("%d\n", result);
        }
    }
}
