#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <climits>
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


#define MAX 40005
#define MAXP 500002
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

map < int, int > indxMap;

char is_prime[MAXP];
int prime_series[50000], _limit;

void sieve()
{
    int k, i=2, j, x;
    memset(is_prime, 1 , MAXP);
    x=sqrt(MAXP);

    ///for even number
    for(j=i*i ; j<=MAXP; j+=i)
        is_prime[j]=0;

    for(i=3; i<=x; )
    {
        for(j=i*i; j<=MAXP; j+=(i*2))
            is_prime[j]=0;
        i++;
        while(is_prime[i]!=1)
            i++;
    }
    ///storing the prime number
    for(i=2, k=0; i<=MAXP ; i++)
    {
        if(is_prime[i]==1)
            prime_series[k++]=i;
    }
//    cout<<k<<endl;
    _limit=k;    ///for saving the last index
    return;
}

/**************/


#define NILL 0
vi arr, adj[MAX];
int dist[MAX], L[MAX], R[MAX], col[MAX];

bool BFS()
{
    queue<int>Q;
    int i,u,v;

    for(i=1;i<=N;i++)
    {
        if(L[i]==NILL)
            dist[i] =0, Q.push(i);
        else if(col[i]==1)
            dist[i] =INF;
    }
    dist[0] = INF;

    while(!Q.empty())
    {
        u = Q.front();Q.pop();
        if(u==0) continue;

        for(i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            if( dist[R[v]] == INF)
            {
                dist[ R[v] ] = dist[u]+1;
                Q.push(R[v]);
            }
        }
    }
    return (dist[0]!=INF);
}

bool dfs(int u)
{
    if(u==0) return true;
    int i,v;

    for(i=0;i<adj[u].size();i++)
    {
        v = adj[u][i];
        if( (dist[R[v]] == dist[u]+1) && dfs(R[v]))
        {
            L[u] = v; R[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

int HopcroftKarp()
{
    int i,ret = 0;
    for(i=1;i<=N;i++) L[i] = NILL,  R[i] =NILL;
    while(BFS())
    {
        for(i=1;i<=N;i++)
        {
//            printf("<%d %d %d>\n",i, col[i] ,arr[i]);
            if(L[i]==NILL && dfs(i) && col[i]==1 ) ret++;
        }
    }
//    printf("ret=[%d]\n", ret);
    return ret;
}

void buildBipartite(int u, int c)
{
    col[u]=c;
    int i, j, k, v;
    REP(i, SZ(adj[u]))
    {
        v= adj[u][i];
        if(col[v]==0)
            buildBipartite(v, 3-c);
    }
    return;
}



int main()
{
    int i, j, k, u, v, w, x, y, z, t=0, tcase, res=0, ind;
    sieve();
//    deb("okay");
//    REP(i, 100)
//        deb(prime_series[i]);
    scanf("%d", &tcase);
    while(tcase--)
    {
        scanf("%d", &N);
        arr.clear(); indxMap.clear();
        arr.pb(0);
        ///1 - based index
        REP(i, N)
        {
            scanf("%d", &x);
            arr.pb(x);
        }
        sort(ALL(arr));

        FORE(i, 1, SZ(arr))
        {
            indxMap[arr[i]]= i;
        }

        FORE(i, 1, SZ(arr))
        {
            x= arr[i];
            for(k=0; k<_limit && x*prime_series[k]<=arr[N]  ;k++)
            {
                int val= x*prime_series[k];
                if(indxMap.count(val) && indxMap[val]!=i)
                {
                    ind= indxMap[val];
                    adj[i].pb(ind);
                    adj[ind].pb(i);
                }
            }
        }
        CLR(col);

        for(i=1; i<=N; i++)
            if(col[i]==0)
                buildBipartite(i, 1);

        res= HopcroftKarp();
//        deb(N, res, res/2);
        printf("Case %d: %d\n", ++t, N-res);

        REP(i, N+3)
            adj[i].clear();
    }

    return 0;
}
