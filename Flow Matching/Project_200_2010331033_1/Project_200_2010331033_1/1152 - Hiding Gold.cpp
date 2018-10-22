/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1152
Problem Name: 1152 - Hiding Gold
Rank: 43
*/


/*
Solution Method:

If we consider every cell on grid as a node then this problem can be easily solved by matching algorithm. From problem statement
 at most one dominoes can be placed between two vartical or horizontal adjacent cell.
 At First, if there are gold on adjacent two cell, then we will create edge between them[we assum each cell as a node]. then simply
 we run bipartite matching matching algorithm. the result is the number of maximum matching. but if
 it is noticed carefully, then it will be clear that we have count each matching twice [double counting problem]. as we create edge
 between x to y as well as y to x. so the real matching number will be (result)/2 [half of the result].
 total cell minus maximum matching number is the desired ans [number of required dominos]
*/

/*
complexity Analysis:
to create necessary edge we need n*m iteration. maximum edge can be E= 4*(m*n), vertex can be V=(m*n);

The Runnig time of DFS is O(E+V) where E is the number of edges and V is is the number of Vertices.
so the complexity will be O(V*(V+E)) or O((m*n)^2)
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int xx[]={1,0,-1,0};				int yy[]={0,1,0,-1}; //4 Direction
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

#define MAX 420

/** debugging**/
#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
#define bugg(x, y) cout<<"->"<<#x<<": "<<x<<"\t\t"<<#y<<": "<<y<<endl;
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

///************************************************************* Code **********************************************************************///

int row, colum, col[MAX], par[MAX];
string str;
vs grid;
vi edge[MAX], gold;


bool dfs(int from)
{
    int i, j, k, to;
    for(i=0; i<SZ(edge[from]); i++)
    {
        to= edge[from][i];
//                bug(to);

        if(col[to]) continue;
        col[to]=1;
        if(par[to]==-1 || ( col[par[to]]==0 && dfs(par[to]) ))
        {
            par[to]= from;
            return true;
        }
    }
    return false;
}

int BPM()
{
    int i, j, k, n, cnt=0;
    mset(par, -1);
    n= SZ(gold);
    for(i=0; i<n; i++)
    {
        CLR(col);
        if(dfs(gold[i]))
            cnt++;
    }
    return cnt;
}

int main()
{
    int i, j, k, result, t=0, tcase, n, m, cnt, from, to, x, y;
    cin>>tcase;
    while(tcase--)
    {
        scanf("%d %d", &row, &colum);
        REP(i, row)
        {
            cin>>str;
            grid.pb(str);
        }

        REP(i, row)
        {
            REP(k, SZ(grid[i]))
            {
                if(grid[i][k] =='*')
                {
                    from= (i*colum)+(k+1);
                    gold.pb(from);
                    REP(j, 4)
                    {
                        x= i+xx[j];
                        y= k+yy[j];

                        if(x>=0 && x<row && y>=0 && y<colum && grid[x][y]=='*')
                        {
                            to= (x*colum)+(y+1);
                            edge[from].pb(to);
                        }
                    }
                }
            }
        }
        int res= BPM();
        result= SZ(gold)-(res/2);
        printf("Case %d: %d\n", ++t, result);
        //clear edges
        gold.clear(); grid.clear();
        REP(i, MAX)
        {
            edge[i].clear();
        }
    }
}

/*problem Statment:
You are given a 2D board where in some cells there are gold. You want to fill the board with 2 x 1 dominoes such that all gold are covered. You may use the dominoes vertically or horizontally and the dominoes may overlap. All you have to do is to cover the gold with least number of dominoes.


In the picture, the golden cells denote that the cells contain gold, and the blue ones denote the 2 x 1 dominoes. The dominoes may overlap, as we already said, as shown in the picture. In reality the dominoes will cover the full 2 x 1 cells; we showed small dominoes just to show how to cover the gold with 11 dominoes.

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with a row containing two integers m (1 ≤ m ≤ 20) and n (1 ≤ n ≤ 20) and m * n > 1. Here m represents the number of rows, and n represents the number of columns. Then there will be m lines, each containing n characters from the set ['*','o']. A '*' character symbolizes the cells which contains a gold, whereas an 'o' character represents empty cells.

Output
For each case print the case number and the minimum number of dominoes necessary to cover all gold ('*' entries) in the given board.

Sample Input
Output for Sample Input
2
5 8
oo**oooo
*oo*ooo*
******oo
*o*oo*oo
******oo
3 4
**oo
**oo
*oo*
Case 1: 11
Case 2: 4
*/

