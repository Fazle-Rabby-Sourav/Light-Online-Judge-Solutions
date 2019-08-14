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
#define psi pair< int, string >
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

string str1, str2;
int len1, len2;

psi dp[MAX][MAX];

psi rec(int now1, int now2)
{
    if( now1<0 || now2<0)
    {
        return MP(0, "");
    }
    psi dummy1, dummy2, dummy;
    psi &ret = dp[now1][now2];

    if( ret.fs != -1)
        return ret;

    if(str1[now1]==str2[now2])
    {
        dummy= rec(now1-1, now2-1);
        dummy.fs+=1;
        dummy.sc+= str1[now1];

        return ret=dummy;
    }
    else
    {
        dummy1= rec(now1, now2-1);
        dummy2= rec(now1-1, now2);

        if(dummy1.fs>dummy2.fs)
            return ret=dummy1;
        else if(dummy1.fs<dummy2.fs)
            return ret= dummy2;
        else if(dummy1.sc<dummy2.sc)
            return ret= dummy1;
        else
            return ret= dummy2;
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        cin>>str1>>str2;
        psi result;

        //dp initialization
        for(i=0; i<MAX; i++)
            for(j=0; j<MAX; j++)
            {
                dp[i][j].fs=-1;
                dp[i][j].sc= "";
            }

        result= rec(SZ(str1)-1, SZ(str2)-1);

        if(result.fs==0)
            printf("Case %d: :(\n", t);
        else
        {
            printf("Case %d: ", t);
            cout<<result.sc<<endl;
        }
    }
    return 0;
}
