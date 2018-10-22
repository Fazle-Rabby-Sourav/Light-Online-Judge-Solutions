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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

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

#define ll long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define vs vector<string>
#define vi vector<int>
#define vii vector< pair<int, int> >

#define fs first
#define sc second
#define MP(x, y) make_pair(x, y)
#define pii pair< int, int >
#define psi pair< string, int >
#define pq priority_queue

#define LOG(x,BASE) (log10(x)/log10(BASE))
#define EQ(a,b)     (fabs(a-b)<ERR)

/**biwise operation**/
#define two(X)          (1<<(X))
#define twoL(X)         (((ll)(1))<<(X))
#define setBit(mask,i)  (mask|two(i))
#define contain(S,X)    (((S)&two(X))!=0)
#define containL(S,X)   (((S)&twoL(X))!=0)
#define popc(i) (__builtin_popcount(i))

#define csprint printf("Case %d: ", ++t);
#define PI acos(-1)
#define ERR 10E-5

const int INF = 0x7f7f7f7f;

#define MAX 1005
/** debugging**/
#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
struct debugger
{    // Taken from rudradevbasak
    template<typename T> debugger& operator , (const T& v)    {        cerr<<v<<" ";        return *this;    }
} dbg;
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

int num_child;
vector <int> adj[MAX], trans[MAX], edge_com[MAX], order;

int taken[MAX], is_wished[MAX], group_no[MAX], dp[MAX], group_mem[MAX], expect, ans, indegre[MAX], outdegre[MAX];

void dfs(int from)
{
    taken[from]=1;
    int i, to;
    for(i=0; i<SZ(adj[from]); i++)
    {
        to= adj[from][i];
        if(taken[to]==0)
            dfs(to);
    }
    order.pb(from);
    return;
}

void dfs2(int from, int grp)
{
  //  deb(from, grp);
    taken[from]=1;
    group_no[from]=grp;
    group_mem[grp]++;
    int i, to;
    for(i=0; i<SZ(trans[from]); i++)
    {
        to= trans[from][i];
    //    bug(to);
        if(taken[to]==0)
            dfs2(to, grp);
    }
    return;
}

bool SCC()
{
    int i, j, k;
    CLR(taken);
    order.clear();
    for(i=0; i<1000; i++)
    {
        if(is_wished[i]==true && taken[i]==false)
        {
            dfs(i);
        }
    }
    int cnt=0;
    CLR(taken); CLR(group_no); CLR(group_mem);
    reverse(ALL(order));

    if(order[0]!=0) return 0;

    for(i=0; i<SZ(order); i++)
    {
        if(taken[order[i]]==0)
        {
            dfs2(order[i], cnt++);
        }
    }
    CLR(indegre); CLR(outdegre); int edgeCom=0;
    for(i=0;i<1000; i++)
    {
        if(is_wished[i])
        {
            for(k=0; k<SZ(adj[i]); k++)
            {
                if(group_no[i]!=group_no[adj[i][k]])
                {
                    indegre[ group_no[ adj[i][k] ]  ]++;
                    outdegre[ group_no[i] ]++;
                    edgeCom++;
                }
            }
        }
    }
 //   bug(cnt); bug(edgeCom);
    ans=0;
    int first=0, last=0;
    if(edgeCom==cnt-1)
    {
        for(i=0; i<cnt; i++)
        {
            if(indegre[i]==0)
                first++;
            if(outdegre[i]==0)
                last++;
        }

        if(first==1 &&  last==1)
            return 1;

        return 0;
    }
    else
        return 0;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, n_wish, result, t=0, tcase, a, b;
    cin>>tcase;
    while(tcase--)
    {
        scanf("%d", &num_child);
        CLR(is_wished);
        for(i=0, expect=0; i<num_child; i++)
        {
            scanf("%d", &n_wish);
            for(k=0; k<n_wish; k++)
            {
                scanf("%d %d", &a, &b);
                {
                    adj[a].pb(b);
                    trans[b].pb(a);
                    if(!is_wished[a]){ is_wished[a]=true; expect++;}
                    if(!is_wished[b]){ is_wished[b]=true; expect++;}
                }
            }
        }
    //    bug(expect);
        result= SCC();
        csprint
        if(result)
            printf("YES\n");
        else
            printf("NO\n");

        for(i=0; i<MAX; i++)
        {
            adj[i].clear();
            trans[i].clear();
            edge_com[i].clear();
        }
    }
}
