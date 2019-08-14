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
#define FORE(i, p, k) for(i=p; i<k; i++)
#define FORN(i, p, k) for(i=p; i>=0; i--)
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define LL long long int
#define pii pair< int, int >
#define psi pair< string, int >
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define PI acos(-1)
#define EPS 10E-5
#define MAX 110

const int INF = 999999999;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
string str;
int len;
int dp[MAX][MAX];

int rec(int cnt, int strt, int end)
{
    int val, min_val;
    if(strt>=end)
    {
        return 0;
    }
    if(dp[strt][end]!=-1)
    {
        return dp[strt][end];
    }

    if(str[strt]==str[end])
    {
    //  min_val= INF;
        val=rec(cnt, strt+1, end-1);
    //  min_val= min(min_val, val);
        dp[strt][end]= val;
        return dp[strt][end];
    }
    else if(str[strt]!=str[end])
    {
        min_val= INF;

        val=rec(cnt, strt+1, end);
        min_val= min(min_val, val+1);

        val=rec(cnt+1, strt, end-1);
        min_val= min(min_val, val+1);

        dp[strt][end]= min_val;
        return dp[strt][end];
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, tcase, t, result;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        cin>>str;
        len= str.length();
        mset(dp, -1);
        result=rec(0, 0, len-1);


        printf("Case %d: %d\n", t, result);
        str.clear();
    }
    return 0;
}
