/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1149
Problem Name: 1149 - Factors and Multiples
Rank: 68
*/


/*
Solution Method:
It is a very straight forward Bipartite matching problem. In this problem we are given two sets of numbers, A and B. we have to find the minimum number
of elments, which have to remove, in set A and B that No element in set B is a multiple of any element of set A.

 we will assume every number of both sets as a node. if an element of B is divisible by an element of set A,
 then we will set up an edge between those two nodes. we will repeat this process for every elements of set A and B. after setting up all possible edges,
 we can run simple BPM algo [with dfs] to find the maximum possible matching. it is easy to understand that the maximum matching number and the desired minimum
 removal numbers are same number. So the maximum matching number is the desired result
 */

 /*
 Complexity Analysis:
 The Runnig time of DFS is O(E+V) where E is the number of edges and V is is the number of Vertices. in my solution there can be at most
 n*m= N edges. so the complexity will be O(n*(n*m)) or O(m* n^2);
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

#define MAX 105

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


///************************************************************* Code **********************************************************************///
vi A, B;

vi adj[MAX];
int par[MAX];
bool color[MAX];

bool dfs(int from)
{
    int to, i;
    if(color[from]) return false;

    color[from]=1;
  //  deb(from);
    for(i=0; i<SZ(adj[from]); i++)
    {
        to= adj[from][i];
        if( par[to]==-1 || dfs(par[to])==1)
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
//    deb("BPM ok");
    mset(par, -1);
    for(i=0; i<SZ(A); i++)
    {
        CLR(color);
        if(dfs(i))
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, result, t=0, tcase, m, n;

    cin>>tcase;
    while(tcase--)
    {
        A.clear(); B.clear();
        scanf("%d", &m);
        for(i=0; i<m; i++)
        {
            scanf("%d", &k);
            A.pb(k);
        }
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &k);
            B.pb(k);
        }

        for(i=0; i<SZ(A); i++)
        {
            for(k=0; k<SZ(B); k++)
            {
                if(B[k]%A[i]==0)
                {
                    adj[i].pb(k);
                }
            }
        }


        result= BPM();
        csprint
        printf("%d\n", result);

        for(i=0; i<MAX; i++)  adj[i].clear();
    }
}

/*
Problem Statement:
You will be given two sets of integers. Let's call them set A and set B. Set A contains n elements and set B contains m elements. You have to remove k1 elements from set A and k2 elements from set B so that of the remaining values no integer in set B is a multiple of any integer in set A. k1 should be in the range [0, n] and k2 in the range [0, m].

You have to find the value of (k1 + k2) such that (k1 + k2) is as low as possible. P is a multiple of Q if there is some integer K such that P = K * Q.



Suppose set A is {2, 3, 4, 5} and set B is {6, 7, 8, 9}. By removing 2 and 3 from A and 8 from B, we get the sets {4, 5} and {6, 7, 9}. Here none of the integers 6, 7 or 9 is a multiple of 4 or 5.

So for this case the answer is 3 (two from set A and one from set B).

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

The first line of each case starts with an integer n followed by n positive integers. The second line starts with m followed by m positive integers. Both n and m will be in the range [1, 100]. Each element of the two sets will fit in a 32 bit signed integer.

Output
For each case of input, print the case number and the result.

Sample Input
Output for Sample Input
2
4 2 3 4 5
4 6 7 8 9
3 100 200 300
1 150
Case 1: 3
Case 2: 0
*/
