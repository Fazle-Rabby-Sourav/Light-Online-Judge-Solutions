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
#define MAX 210

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
LL num_num, num_query, d, r;
LL number[MAX], dp[MAX][25][15];

LL mod (LL n)
{
    if(n<0)
        return d-(_abs(n)%d);
    else
        return (n%d);
}

LL rec(LL n, LL sum, LL k)
{
    LL res;
    sum = mod(sum);

    if(k==0)
    {
        if(mod(sum)==0)
            return 1;
        else
            return 0;
    }
    if(n==num_num)
    {
        return 0;
    }

    if(dp[n][sum][k]!=-1)
        return dp[n][sum][k];

    res=0;
    res+= rec(n+1, sum+mod(number[n]), k-1) ;   ///taken
    res+= rec(n+1, sum, k);                     ///not taken

    dp[n][sum][k]= res;
    return res;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    LL ans,i, j, k, t, r, tcase;
    cin>>tcase;
    for(t=1; t<=tcase; t++)
    {
        CLR(number);
        cin>>num_num>>num_query;
        for(i=0 ; i<num_num; i++)
        {
            scanf("%lld", &number[i]);
        }
        printf("Case %lld:\n", t);
        for(i=1 ; i<=num_query; i++)
        {
            scanf("%lld %lld", &d, &r);
            mset(dp, -1);
            ans=rec(0, 0, r);
            printf("%lld\n",ans);
        }

    }
    return 0;
}
