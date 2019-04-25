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


#define MAX 50005

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

map <int , int> mp;
vi tree[4*MAX], lineY[MAX], allX;
int N, q;

void initialize(int node, int left, int right)
{
    if(left==right)
    {
        tree[node].clear();
        int x= mp[allX[left]];
        sort(ALL(lineY[x]));
        tree[node]= lineY[x];
        return;
    }
    int mid= (left+right)/2;

    initialize(node*2, left, mid);
    initialize(node*2+1, mid+1, right);

    tree[node].clear();
    merge(ALL(tree[node*2]), ALL(tree[node*2+1]), back_inserter(tree[node]));
    return;
}


int BSearchUpper(int node, int val)
{
    int high, low, mid;
    low= 0; high= SZ(tree[node])-1;

    while(low<high)
    {
        mid= (low+high)/2;
        if(tree[node][mid]<val)
            low= mid+1;
        else
            high= mid;
    }
    return low;
}

int BsearchLower(int node, int val)
{
    int high, low, mid;
    low= 0; high= SZ(tree[node])-1;

    while(low<high)
    {
        mid= (low+high+1)/2;
        if(tree[node][mid]>val)
            high= mid-1;
        else
            low= mid;
    }
    return low;
}


int query(int node, int left, int right, int i, int j, int k, int l)
{
    if(i<=allX[left] && allX[right]<=j)
    {
        if(k>tree[node][SZ(tree[node])-1] || l<tree[node][0])
            return 0;

        int upper, lower;

        upper= BSearchUpper(node, k);
        lower= BsearchLower(node, l);
        return (lower-upper + 1);
    }

    if(i> allX[right] || j<allX[left])
        return 0;

    int mid= (left+right)/2;
    return query(node*2, left, mid, i, j, k, l) + query(node*2 +1, mid+1, right, i, j, k, l);
}

int main()
{
    int x, y, w, i, j, k, result, t=0, tcase, cnt, x1, y1, x2, y2;

    cin>>tcase;
    while(tcase--)
    {
        cnt=1;
        mp.clear(); allX.clear();
        scanf("%d %d", &N, &q);
        REP(i, N)
        {
            scanf("%d %d", &x, &y);
            if(mp[x]==0)
            {
                mp[x]=cnt++;
                allX.pb(x);
            }
            int ind= mp[x];
            lineY[ind].pb(y);
        }
        sort(ALL(allX));
        N= SZ(allX);
        initialize(1, 0, N-1);

        printf("Case %d:\n", ++t);
        REP(i, q)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            result= query(1, 0, N-1, x1, x2, y1, y2);
            printf("%d\n", result);
        }

        REP(i, MAX)
            lineY[i].clear();
    }
}

/*
As the name says, this problem is about finding the number of points in a rectangle whose sides are parallel to axis. All the points and rectangles consist of 2D Cartesian co-ordinates. A point that lies in the boundary of a rectangle is considered inside.

Initially you are given a list of points, after that you are given some queries, each query contains a rectangle. Your task is to find the number of points that lie in each of the query rectangle.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with a line containing two integers: p, q (1 ≤ p, q ≤ 50000), where p denotes the number of points and q denotes the number of query rectangles.

Each of the next p lines contains two integers x y denoting the co-ordinate of a point. All the points are distinct.

Each of the next q lines contains four integers x1 y1 x2 y2 meaning that you are given a rectangle whose lower left co-ordinate is (x1, y1) and upper-right corner is (x2, y2). You can assume that (x1 < x2, y1 < y2).

You can assume that the values of the co-ordinates lie between 0 and 109 (inclusive).

Output
For each case, print the case number in a line first. Then for each query rectangle, you have to answer the number of points that lie inside that rectangle. Print each of the results in separate lines.

Sample Input
Output for Sample Input
1
5 6
0 0
5 9
2 3
4 6
7 7
0 0 5 9
2 2 10 11
4 6 7 9
3 3 4 5
4 6 5 7
5 7 7 9
*/
