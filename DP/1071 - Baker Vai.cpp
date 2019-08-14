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
#define MAX 105

const int INF = 0x7f7f7f7f;
LL Pow (LL B, LL P){    LL result ; LL i;    for( i=0, result=1; i<P; i++) {result*=B;}    return result;}
int row_num, col_num;
int grid[MAX][MAX], dp[MAX][MAX][210];

int rec(int row1, int row2, int step)
{
    int i, j, k, max_val, col1, col2;
    col1= _abs(step-row1);    col2= _abs(step-row2);
    //printf("[%d %d %d %d]\n", row1, col1, row2, col2);

    if( (row1==row_num-1 && col1==col_num) || (col1==col_num-1 && row1==row_num) || (row2==row_num-1 && col2==col_num) || (col2==col_num-1 && row2==row_num)   )
    {
        return 0;
    }

    if( row1>=row_num || row2>=row_num ||  col1>=col_num || col2>=col_num)
        return -INF;

    int &ret= dp[row1][row2][step];
    if(ret!=-1)
        return ret;

    max_val= -INF;
    int add;

    if(row1==row2)
        add= grid[row1][col1];
    else
        add= grid[row1][col1]+grid[row2][col2];

    max_val= max(max_val, rec(row1, row2, step+1)+add);
    max_val= max(max_val, rec(row1+1, row2, step+1)+add);
    max_val= max(max_val, rec(row1, row2+1, step+1)+add);
    max_val= max(max_val, rec(row1+1, row2+1, step+1)+add);

    ret= max_val;
    return max_val;
}

int main()
{
    int tcase, i, j, k, t;
    cin>>tcase;
    for(t=1; t<=tcase; t++)
    {
        cin>>row_num>>col_num;
        for(i=0; i<row_num; i++)
        {
            for(j=0; j<col_num; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }
        mset(dp, -1);
        int result;
        result= rec(0, 0, 0);
        printf("Case %d: %d\n", t, result);
    }
    return 0;
}
