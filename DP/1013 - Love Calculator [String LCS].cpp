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

template<class T1> void deb(T1 e){cout<<e<<endl;}
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
#define fs first
#define sc second
#define LL long long int
#define pii pair< int, int >
#define pll pair< long long int, long long int >
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
#define MAX 32

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
string str1, str2;
pll dp[MAX][MAX];
LL len1, len2;

pll rec(int now1, int now2)
{
    pll ans, dum1, dum2;
    if(now1>=len1 || now2>= len2)
        return MP(0, 1);

    pll &ret= dp[now1][now2];
    if(ret.fs!=-1)
        return ret;

    if(str1[now1]==str2[now2])
    {
        ans= rec(now1+1, now2+1);
        ans.fs = ans.fs+1;
    }
    else
    {
        dum1= rec(now1, now2+1);
        dum2= rec(now1+1, now2);
        if(dum1.fs>dum2.fs)
        {
           ans.fs= dum1.fs; ans.sc = dum1.sc;
        }
        else if(dum1.fs<dum2.fs)
        {
            ans.fs= dum2.fs; ans.sc = dum2.sc;
        }
        else
        {
            ans.fs= dum1.fs; ans.sc = dum1.sc+dum2.sc;
        }
    }
    ret= ans;    return ans;
}

int main()
{
    int tcase, t, i, j, k;
    pll ans;
    cin>>tcase;
    for(t=1; t<=tcase; t++)
    {
        cin>>str1>>str2;
        len1= str1.length();
        len2= str2.length();
        mset(dp, -1);
        ans= rec(0, 0);
        printf("Case %d: %lld %lld\n",t, (len1+len2)-ans.fs, ans.sc );
    }
    return 0;
}
