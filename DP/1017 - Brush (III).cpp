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

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
int dp[MAX][MAX], num_move, num_dust, width_brush;
VI dust;

int rec(int indx, int moved)
{
    int will_removed, next_indx, now_place, cnt, i;

    if(indx==num_dust || moved==0)
    {
        return 0;
    }
    int &ret= dp[indx][moved];

    if(ret!=-1)
        return ret;

    ret= -INF;
    now_place= dust[indx];

    for(i=indx+1, cnt=1, next_indx=SZ(dust) ; i<SZ(dust) ; i++)
    {
        if(dust[i]>now_place+width_brush)
        {
            next_indx= i;
            break;
        }
        cnt++;
    }

//    printf("<next indx:%d %d>\n", next_indx, cnt );

    ret=max(ret, rec(next_indx, moved-1)+cnt);
    ret= max(ret, rec(indx+1, moved));

    return ret;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, dum, i, j, k;

    cin>>tcase;

    for(t=1; t<=tcase; t++)
    {
        dust.clear();
        cin>>num_dust>>width_brush>>num_move;
        for(i=0; i<num_dust; i++)
        {
            cin>>dum>>dum;
            dust.pb(dum);
        }
        sort(ALL(dust));
        int result;
        mset(dp, -1);

        result= rec(0, num_move);
        printf("Case %d: %d\n", t, result);
    }
    return 0;
}
