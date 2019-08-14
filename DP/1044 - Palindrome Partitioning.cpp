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

string str;
int len, dp_pal[MAX][MAX], dp_par[MAX];

bool is_palindrome(int i, int j)
{
    int x;
    if(i>=j)
        return 1;

    if(dp_pal[i][j]!=-1)
        return dp_pal[i][j];

    if(str[i]==str[j])
        x= (is_palindrome(i+1, j-1));
    else
        x= 0;

    dp_pal[i][j]=x;
    return x;
}

int partition(int x)
{
    int is_pal, min_val, i;

    if(x==len)
        return 0;

    if(dp_par[x]!=-1)
        return dp_par[x];

    for(i=x, min_val=INF; i<len; i++)
    {
        is_pal= is_palindrome(x, i);
        if(is_pal)
        {
            min_val=min(min_val, partition(i+1)+1);
        }
    }
    dp_par[x]=min_val;
    return min_val;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k, res;

    cin>>tcase;
    for(t=1; t<=tcase; t++)
    {
        cin>>str;
        len= str.length();

        mset(dp_pal, -1);
        mset(dp_par, -1);
        res=partition(0);
       //res= is_palindrome(0, len-1);
        printf("Case %d: %d\n",t, res);
    }
    return 0;
}
