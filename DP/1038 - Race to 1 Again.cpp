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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FORE(i, p, k) for(i=p; i<=k; i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define REP(i,n) for (i=0;i<n;i++)

#define popc(i) (__builtin_popcount(i))
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define fs first
#define sc second
#define LL long long int
#define pii pair< int, int >
#define psi pair< string, int >
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define VII vector< pair<int, int> >
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define two(x) (1<<(x))
#define contain(s, x) ((s)&(two(x))!=0)
#define CNVRT acos(-1.00)/180.0
#define PI acos(-1)
#define EPS 10E-14

const int INF = 0x7f7f7f7f;

#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
struct debugger
{
    // Taken from rudradevbasak
    template<typename T> debugger& operator , (const T& v)
    {
     //   deb(v);
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//For debugging
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
//template<class T> void deb(T e[SIZE][SIZE],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> void deb(T e[],int row){int i;REP(i,row) cout<<e[i]<<" ";cout<<endl;}


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
LL Pow(LL B,LL P){  LL R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
//compute b^p%m
int BigMod(LL B,LL P,LL M){ LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
//print a number in binary format with n length
//void binprint(LL mask,LL n){LL i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
//ASCII Chart
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}
//LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
//LL bigmod(LL B, LL P, LL M){LL R=1;while(P>0){if(P%2==1)R=((R*B)%M);P/=2;B= (B*B)%M;}return R;}
//void sieve(){int k=0;prime_series[k++]=2; for(int i=3; i<MAX; i+=2){   if(is_prime[i]==0)   {  prime_series[k++]=i;  if(i<=MAX/i) for(int j=i*i;j<MAX;j+=i*2)is_prime[j]=1; } } Limit= k;return;}
template< class T > inline T MOD(T n, T m){
    return (n%m+m)%m;
}

#define MAX 100005


bool is_prime[MAX];
int prime_series[MAX], limit, num_prime[MAX], n;
double dp[MAX];

void sieve()
{
    register int k, i=2, j, x;
    memset(is_prime, 1 , MAX);
    x=(int)sqrt((double)MAX);
    ///for even number
    for(j=i*i ; j<=MAX; j+=i)
        is_prime[j]=0;

    for(i=3; i<=x; )
    {
        for(j=i*i; j<=MAX; j+=(i*2))
            is_prime[j]=0;
        i++;
        while(is_prime[i]!=1)
            i++;
    }
    ///saving the prime number
    for(i=2, k=0; i<=MAX ; i++)
        if(is_prime[i]==1)
            prime_series[k++]=i;

    limit=k;
 //   cout<<k<<endl;    ///for saving the last index
}


int divisor (int N)
{   int i, j, k, sum, val, cnt, N_ini;
    sum=1;
    N_ini=N;
    for(i=0; prime_series[i]<= sqrt(N); i++)
    {   if(N%prime_series[i]==0)
        {   cnt=0;
            while(N%prime_series[i]==0)
            {   N=N/prime_series[i];
                cnt++;
            }
            sum*=(cnt+1);
        }
    }
    if(N>1)
        sum*=2;
    return sum;
}

double rec(int now)
{
    int x, another_div, cnt=2, N;
    double total=0.0, div;

    if(now==1)
        return 0.0;

    double &ret= dp[now];
    if(ret>-0.5)        return dp[now];
    x=sqrt(now)+1;
    for(int i=2; i<x; i++)
    {
        if(now%i==0)
        {
            cnt++;
            total+= rec(now/i);
            another_div= (now/i);
            if( another_div != i)
            {
                cnt++;
                total+= rec(now/another_div);
            }
        }
    }
 //   ret= ((total+cnt)/(double)(cnt-1));
    total= total+cnt;
    total= (total/(double)cnt);
    div= (1-(1/(double)cnt));
    total= total/div;
    ret= total;
    return ret;
}

int main()
{
    int i, j, k,cnt, result, t, tcase;
    double ans;
   // sieve();
    t=0;
    mset(dp, -1.0);
    cin>>tcase;
    while(tcase--)
    {
        scanf("%d", &n);
        ans= rec(n);
        printf("Case %d: %.10lf\n",++t, ans);
    }
}
