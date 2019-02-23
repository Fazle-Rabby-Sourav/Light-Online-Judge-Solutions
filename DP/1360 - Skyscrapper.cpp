///**Bismillahir-Rahmanir-Rahim**///

/*
The Build n' Profit construction company is about to build its tallest building. It will be huge, the tallest building in the world by a wide margin.
 It will house hundreds of thousands of people and have rocket-powered elevators to the upper floors. They even plan for a shuttle docking station
 instead of a helipad on its roof. But any building of that size is extremely costly to build and maintain, and even after selling and renting
  out all the floor-space it will be very difficult to meet the costs. Luckily, they have come up with a great solution. They will place advertisements
  on the outer walls of the building for a hefty charge. This will help offset some of the costs and bring in a profit.

However, feedbacks from prospective buyers of this advertisement space have brought up a new problem. Each customer wants a specific sized advertisement
 placed at a specific height, and they will pay a certain amount of money for it. Each advertisement order specifies its position (i.e. the lowest floor
 of the advertisement) and its size (i.e. the number of floors it covers, including the starting floor). Each advertisement spans the whole face of the building,
  so no two advertisements can occupy the same floor and no floors can be partially covered. Each order also includes the amount to be earned if that advertisement
   is placed on the building. Of course, no money is earned if only part of an advertisement is placed, or it is placed in any other position.

Since many of the advertisements want some of the same floors as others, it is often impossible to choose all of them. Can you help choosing which of
the orders to accept so that the above constraints are fulfilled and the amount of profit is maximized?

Input
Input starts with an integer T (<= 50), denoting the number of test cases.

Each case starts with an integer N (1<= N <= 30000) denoting the number of advertisement orders. Each of the next N lines represents an advertisement
by three integers A (0 <= A <= 105), B (1 <= B <= 105) and C (1 <= C <= 1000) denoting the lowest floor, the number of floors the advertisement covers
(including the lowest floor) and the amount of money earned for placing it, respectively.

Output
For each case, print the case number and the maximum profit they can achieve.

Sample Input

1
3
1 5 1
2 10 3
7 12 1

Case 1: 3
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

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define REP(i,n)for (i=0;i<n;i++)
#define REV(i,n) for(i=n;i>=0;i--)
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

#define PI acos(-1)
#define ERR 10E-5
#define MAX 60010
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

int num_build, dp[MAX],  exist_list[MAX];
map <int, int> indx;
vector < pii > poster[MAX];
vector <pair <pii, int> > dummy;
vi num;

int rec(int now)
{
    now= exist_list[now];
    if(now==-1) return 0;

    int &ret= dp[now];
    if(ret!=-1) return ret;    ret=0;

    for(int i=0; i<SZ(poster[now]); i++)
        ret= max(ret, rec(poster[now][i].fs)+poster[now][i].sc);
    ret= max(ret, rec(now+1));

    return ret;
}

int main()
{
    int i, j, k, result, t=0, tcase, x, y, z, ind;
    cin>>tcase;
    while(tcase--)
    {
        indx.clear(); dummy.clear(); num.clear();  ind=0;
        scanf("%d", &num_build);
        for(i=0; i<num_build; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            num.pb(x);
            num.pb(x+y);
            dummy.pb(MP( MP(x, x+y), z ));
        }
        sort(ALL(num));
        for(i=0; i<SZ(num); i++)
        {
            if(indx.count(num[i])==0)
            {
                indx[num[i]]= ind;
                ind++;
            }
        }

        mset(exist_list, -1);
        for(i=0; i<SZ(dummy); i++)
        {
            poster[ indx[dummy[i].fs.fs] ].pb(MP(indx[ dummy[i].fs.sc ], dummy[i].sc));
            exist_list[ indx[dummy[i].fs.fs] ]= indx[dummy[i].fs.fs];
        }

        int pre=-1;
        FORD(i, MAX-1)
        {
            if(exist_list[i]<0)
                exist_list[i]= pre;
            else
                pre= exist_list[i];
        }
        mset(dp, -1);
        result= rec(0);
        printf("Case %d: %d\n",++t,  result);

        //poseter clear
        for(i=0; i<=ind; i++)
            poster[i].clear();
    }
}
