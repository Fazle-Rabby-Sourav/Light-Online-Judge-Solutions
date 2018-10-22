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

#define csprnt printf("Case %d:\n", ++t);
#define PI acos(-1)
#define ERR 10E-5
#define MAX 10010
const int INF = 0x7f7f7f7f;

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

struct trie
{
    int cnt;
    int grid[52];
    trie()
    {
        cnt=0;
        mset(grid, -1);
    }
    void refresh()
    {
        cnt=0;
        mset(grid, -1);
    }
};

int n_word, len, T, n_sentence;
char str[MAX], sentence[MAX];
trie arr[149900];

void INSERT (int cur, int cur_ind)
{
  //  deb(cur, cur_ind);
    if(str[cur]=='\0')
    {
        arr[cur_ind].cnt++;
        return;
    }
    int ch;
    if(str[cur]>='a' && str[cur]<='z')
        ch= str[cur]-'a';
    else if(str[cur]>='A' && str[cur]<='Z')
        ch= str[cur]-'A'+26;

    if(arr[cur_ind].grid[ch]==-1)
    {
        arr[cur_ind].grid[ch]= ++T;
    }
    int new_ind= arr[cur_ind].grid[ch];
    INSERT(cur+1, new_ind);
    return;
}
int FIND(int cur, int cur_ind)
{
    if(str[cur]=='\0')
    {
        return arr[cur_ind].cnt;
    }
    int ch;
    if(str[cur]>='a' && str[cur]<='z')
        ch= str[cur]-'a';
    else if(str[cur]>='A' && str[cur]<='Z')
        ch= str[cur]-'A'+26;

    if(arr[cur_ind].grid[ch]==-1)
    {
        return 0;
    }
    int new_ind= arr[cur_ind].grid[ch];
    return FIND(cur+1, new_ind);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, t=0, tcase;
    int result;
    cin>>tcase;
    while(tcase--)
    {
        T=0;
        scanf("%d", &n_word);
        for(i=0; i<n_word; i++)
        {
            scanf("%s", &str);
            len= strlen(str);
            if(len>2)  sort(str+1, (str+len-1) );
            INSERT(0, 0);
        }
        char dum;
        csprnt;
        scanf("%d%c", &n_sentence, &dum);
        for(i=0; i<n_sentence; i++)
        {
            result=1;
            gets(sentence);
            stringstream ss;
            ss<<sentence;
            while(ss>>str)
            {
                len= strlen(str);
                if(len>2) sort(str+1, (str+len-1) );
                result*=FIND(0, 0);
                if(result==0)     break;
            }
            printf("%d\n", result);
        }
        for(i=0; i<=T+1; i++)
        {
            arr[i].refresh();
        }
    }
}
/// cant find reason for getting WA
