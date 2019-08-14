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
#define LL unsigned long long int
#define pii pair< int, int >
#define pil pair <unsigned long long int, unsigned long long int>
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
#define MAX 200

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
LL sum_lim, num_dice, all_poss, cer_poss;
pil dp[MAX][MAX];
bool flag;
pil rec(LL cur, LL sum)
{
    LL ans, ans_all, i;
    all_poss++;
    if(cur>num_dice)
    {
        if(sum>=sum_lim)
        {
            return MP(1, 1);
        }
        else
        {
            flag=1;
            return MP(0, 1);
        }
    }

    if(dp[cur][sum].ff!=-1)
    {
        return dp[cur][sum];
    }

    ans=0;
    ans_all=0;
    for(i=1; i<=6; i++)
    {
        ans+= rec(cur+1, sum+i).ff;
        ans_all+= rec(cur+1, sum+i).ss;
    }
    dp[cur][sum].ff= ans;
    dp[cur][sum].ss= ans_all;
    return dp[cur][sum];
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    LL i, tcase, t, j, k, ans, ans_all, result, x;
    cin>>tcase;
    for(t=1; t<=tcase; t++)
    {
        cin>>num_dice>>sum_lim;
        all_poss=0;     cer_poss=0;     flag=0;
        mset(dp, -1);
        ans=rec(1, 0).ff;
        ans_all= rec(1, 0).ss;

        x= gcd(ans, ans_all);
        ans= ans/x;
        ans_all= ans_all/x;

        if(ans==0)
        {
            cout<<"Case "<<t<<": "<<"0\n";
        }
        else if(ans==ans_all)
        {
            cout<<"Case "<<t<<": "<<"1\n";
        }
        else
        {
            cout<<"Case "<<t<<": "<<ans<<"/"<<ans_all<<endl;
        }
    }
    return 0;
}
