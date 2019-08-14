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
#define MAX 1010

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
int tym_eat[2][MAX], tym_jump[2][MAX], dp[2][MAX];
int n;

int rec(int bld, int flr)
{
//    printf("[%d %d]", bld, flr);
    int res, i, j, bld_x;

    if(flr>=n-1)
    {
        return tym_eat[bld][n-1];
    }

    int &ret= dp[bld][flr];
    if(ret!=-1)
        return ret;

    res=INF;
    if(bld==0)
    {
        bld_x=1;
        res=min(res, rec(bld, flr+1)+tym_eat[bld][flr]); //stay same bld
        res= min(res, rec(bld_x, flr+1)+tym_eat[bld][flr]+tym_jump[bld][flr]); //jum another bld
    }
    else
    {
        bld_x=0;
        res=min(res, rec(bld, flr+1)+tym_eat[bld][flr]); //stay same bld
        res= min(res, rec(bld_x, flr+1)+tym_eat[bld][flr]+tym_jump[bld][flr]); //jum another bld
    }
    ret=res;
    return res;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, result, t, i, j, k;

    cin>>tcase;

    for(t=1; t<=tcase; t++)
    {
        cin>>n;
        for(i=0; i<n; i++)  scanf("%d", &tym_eat[0][i]);
        for(i=0; i<n; i++)  scanf("%d", &tym_eat[1][i]);
        for(i=0; i<n-1; i++)  scanf("%d", &tym_jump[0][i]);
        for(i=0; i<n-1; i++)  scanf("%d", &tym_jump[1][i]);
        mset(dp, -1);
        result=INF;
        result= min(result, rec(0, 0));
        result= min(result, rec(1, 0));
        printf("Case %d: %d\n", t, result);
    }
    return 0;
}
