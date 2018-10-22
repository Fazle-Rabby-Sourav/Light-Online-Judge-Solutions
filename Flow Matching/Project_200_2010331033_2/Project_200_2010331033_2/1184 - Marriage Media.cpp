/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1184
Problem Name: 1184 - Marriage Media
Rank: 61
*/


/*
Solution Method:
This is an elementary bipartite matching problem with some constrains. we should think a man or woman as a single node. and an edge between them
means they can marry/ be a couple. first , we will set up every possible edge between all nodes. for that we will fulfil the given condition and constrains.
if their age difffernce is less than or equal to 5, and if their height difference is less than or equal to 12 inches then we will create a edge between them.
And ant last we simply run a BP algo on the created graph. thus we can get maximum number of matching or marriage.
*/

 /*
 Complexity Analysis:
 The Runnig time of DFS is O(E+V) where E is the number of edges and V is is the number of Vertices. Here number of edges are m*w where m is the
 number of man and w is the number of women. and the dfs is called m times,  Therefore , the complexity of the algorithm will be O(m*(m*w));
 or approximately O(n^3)
 */

///********************************************Code******************************************///


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
template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int xx[]={1,0,-1,0};				int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};	int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};	int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

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

#define MAX 55

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

struct homoSapiens
{
    int height, age;
    int divorce;

    homoSapiens(int h, int a, int d)
    {
        height=h; age=a; divorce=d;
        return;
    }
};

vector < homoSapiens > man , woman;

vi adj[MAX];
int par[MAX];
bool color[MAX];

bool dfs(int from)
{
    int to, i;
    if(color[from]) return false;
    color[from]=1;

    for(i=0; i<SZ(adj[from]); i++)
    {
        to= adj[from][i];
        if(par[to]==-1 || dfs(par[to])==1)
        {
            par[to]=from;
            return true;
        }
    }
    return false;
}

int BPM()
{
    int i, j, k, cnt=0;
    mset(par, -1);
    for(i=0; i<SZ(man); i++)
    {
        CLR(color);
        if(dfs(i))
            cnt++;
    }
    return cnt;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, result, t=0, tcase, m, w, h, a, d;
    cin>>tcase;
    while(tcase--)
    {
        man.clear(); woman.clear();
        cin>>m>>w;

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &h, &a, &d);
            man.pb(homoSapiens(h, a, d));
        }

        for(i=0; i<w; i++)
        {
            scanf("%d %d %d", &h, &a, &d);
            woman.pb(homoSapiens(h, a, d));
        }


        for(i=0; i<m; i++)
        {
            for(k=0; k<w; k++)
            {
                if( ((abs(man[i].height-woman[k].height))<=12) && ((abs(man[i].age-woman[k].age))<=5) && (man[i].divorce==woman[k].divorce) )
                {
                    adj[i].pb(k);
                }
            }
        }

        result= BPM();
        csprint
        printf("%d\n", result);

        for(i=0; i<MAX; i++)    adj[i].clear();
    }
}

/*
Problem Statement:
You run a marriage media. You take some profiles for men and women, and your task is to arrange as much marriages as you can. But after reading their bio-data you have found the following criteria.

1.      No man will marry a woman if their height gap is greater than 12 inches.
2.      No woman will marry a man if their age gap is greater than 5 years.
3.      A couple can be formed if either both are not divorced or both are divorced.
4.      Of course, a man can marry a single woman and vice versa.

Now you are given the bio-data of some men and women, you have to arrange the maximum number of marriages considering the given criteria.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains two integer m, n (1 ≤ m, n ≤ 50). Each of the next m lines will contain the information for a man, and each of the next n lines will contain the information for a woman. An information will contain three integers denoting the height in inches, age in years and 1 or 0 depending on they are divorced or not respectively. Assume that Height will be between 50 and 80, age will be between 20 and 50.

Output
For each case, print the case number and the maximum number of marriages you can arrange.

Sample Input
Output for Sample Input
2
2 2
70 30 0
60 20 0
71 25 0
71 35 0
1 1
70 30 1
70 30 0
Case 1: 2
Case 2: 0
*/
