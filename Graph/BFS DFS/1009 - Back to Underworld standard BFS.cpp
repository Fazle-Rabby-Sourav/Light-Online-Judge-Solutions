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
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define LL __int64
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define MAX 20020

const int INF = 0x7f7f7f7f;

LL Pow(LL B,LL P){  LL R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(LL B,LL P,LL M){ LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}

int cnt, white, black;
vector <int> fight[MAX];
bool taken[MAX];
int color[MAX];

void bfs (int src)
{
    int i, j, k, from , to;

    if(taken[src]==0)
    {
        queue <int> Q;

        Q.push(src);
        taken[src]=1;
        color[src]=1;
        white++;
        while(!Q.empty())
        {
            from= Q.front();

            for(i=0; i<fight[from].size(); i++)
            {
                to= fight[from][i];
                if(!taken[to])
                {
                    if(color[from]==1)
                    {
                        color[to]=2;
                        black++;
                    }
                    else if(color[from]==2)
                    {
                        color[to]=1;
                        white++;
                    }
                    Q.push(to);
                    taken[to]=1;
                }
            }
            Q.pop();
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int i, j, k, test_case, t, num_fight, dummy_a, dummy_b;


    scanf("%d", &test_case);

    for(t=1; t<=test_case; t++)
    {
        scanf("%d", &num_fight);
        map <int , int> mymap;
        vector <int> save;
        for(i=0; i<num_fight; i++)
        {
            scanf("%d %d", &dummy_a, &dummy_b);

            if(mymap[dummy_a]==0)
            {
                mymap[dummy_a]=1;
                save.pb(dummy_a);
            }
            if(mymap[dummy_b]==0)
            {
                mymap[dummy_b]=1;
                save.pb(dummy_b);
            }

            fight[dummy_a].pb(dummy_b);
            fight[dummy_b].pb(dummy_a);
        }

        mset(color, 0);
        mset(taken, 0);
        for(i=0, cnt=0; i<save.size(); i++)
        {
            black=white=0;
            bfs(save[i]);

            if(white>=black)
                cnt+=white;
            else
                cnt+=black;
        }

        printf("Case %d: %d\n", t, cnt);

        for(i=0; i<MAX; i++)
        {
            fight[i].clear();
        }
        save.clear();
    }
    return 0;
}
