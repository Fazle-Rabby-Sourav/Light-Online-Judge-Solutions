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


#define MAX 505

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

////template<class T> void deb(vector<T> e){int i;REP(i,SZ(e)) cout<<e[i]<<" ";cout<<endl;}
////template<class T> void deb(vector<T> e,int n){int i;REP(i,n) cout<<e[i]<<" ";cout<<endl;}
////template<class T> void deb(vector< basic_string<T> > e){int i,j;REP(i,SZ(e)) {REP(j,SZ(e[i])) cout<<e[i][j];cout<<endl;} cout<<endl;}
////template<class T> void deb(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
////template<class T> void deb(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<"\t";cout<<endl;} cout<<endl;}
////template<class T> void deb(T e[MAX][MAX],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
////template<class T> void deb(T e[],int row){int i;REP(i,row) cout<<e[i]<<" ";cout<<endl;}

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

int n, m;

vi grid[MAX];
int tree[4*MAX][4*MAX];


void initializeY(int nodex, int left, int right, int nodey, int up, int down)
{
    if(up==down)
    {
        if(left==right)
            tree[nodey][nodex]= grid[up][left];
        else
            tree[nodey][nodex]= max(tree[nodey][nodex*2], tree[nodey][nodex*2 +1]);
        return;
    }
    int mid= (up+down)/2 ;

    initializeY(nodex, left, right, nodey*2, up, mid);
    initializeY(nodex, left, right, nodey*2 +1, mid+1, down);

    tree[nodey][nodex]= max(tree[nodey*2][nodex], tree[nodey*2+1][nodex]);
    return;
}

void initializeX(int nodex, int left, int right, int nodey, int up, int down)
{
    if(left!=right)
    {
        int mid= (left+right)/2;
        initializeX(nodex*2, left, mid, nodey, up, down);
        initializeX(nodex*2 +1, mid+1, right, nodey, up, down);
    }
    initializeY(nodex, left, right, 1, 0, n-1);
}

int queryY(int nodex, int nodey, int left, int right, int up, int down, int k, int l)
{
    if(k<=up && down<=l)
    {
        return tree[nodey][nodex];
    }

    if(down<k || up>l)
        return -INF;

    int mid= (up+down)/2;
    return max(  queryY(nodex, nodey*2, left, right, up, mid, k, l),  queryY(nodex, nodey*2 +1, left, right, mid+1, down, k, l));
}

int queryX(int nodex, int nodey, int left, int right, int i, int j, int k, int l)
{
    if(i<=left && right<=j)
    {
        return queryY(nodex, nodey, left, right, 0, n-1, k, l);
    }
    if(right<i || left>j)
        return -INF;

    int mid= (left+right)/2;
    return max(queryX(nodex*2, nodey, left, mid, i, j, k, l), queryX(nodex*2 +1, nodey, mid+1, right, i, j, k, l));
}

int main()
{
    int x, y, s, i, j, k, result, t=0, tcase, q, cnt;

    cin>>tcase;
    while(tcase--)
    {
        scanf("%d %d", &n, &q);
        REP(i, n)
        {
            REP(k, n)
            {
                scanf("%d", &x);
                grid[i].pb(x);
            }
        }
        initializeX(1, 0, n-1, 1,  0, n-1);
       // deb("ok");
        printf("Case %d:\n", ++t);
        REP(i, q)
        {
            scanf("%d %d %d", &y, &x, &s);
            result= queryX(1, 1, 0, n-1, x-1, x+s-2, y-1, y+s-2);
            printf("%d\n", result);
        }

        REP(i, MAX)
            grid[i].clear();
    }
}


/*
Little Tommy is playing a game. The game is played on a 2D N x N grid. There is an integer in each cell of the grid. The rows and columns are numbered from 1 to N.

At first the board is shown. When the user presses a key, the screen shows three integers I, J, S which designates a square (I, J) to (I+S-1, J+S-1) in the grid. The player has to predict the largest integer found in this square. The user will be given points based on the difference between the actual result and the given result.

Tommy doesn't like to lose. So, he made a plan, he will take help of a computer to generate the result. But since he is not a good programmer, he is seeking your help.

Input
Input starts with an integer T (≤ 3), denoting the number of test cases.

The first line of a case is a blank line. The next line contains two integers N (1 ≤ N ≤ 500), Q (0 ≤ Q ≤ 50000). Each of the next N lines will contain N space separated integers forming the grid. All the integers will be between 0 and 105.

Each of the next Q lines will contain a query which is in the form I J S (1 ≤ I, J ≤ N and 1 ≤ I + S, J + S < N and S > 0).

Output
For each test case, print the case number in a single line. Then for each query you have to print the maximum integer found in the square whose top left corner is (I, J) and whose bottom right corner is (I+S-1, J+S-1).

Sample Input
Output for Sample Input
1

4 5
67 1 2 3
8 88 21 1
89 12 0 12
5 5 5 5
1 1 2
1 3 2
3 3 2
1 1 4
2 2 3
*/
