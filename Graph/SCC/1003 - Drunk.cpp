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

template< class T > T _abs(T n)
{
    return (n < 0 ? -n : n);
}
template< class T > T sq(T x)
{
    return x * x;
}
template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c)
{
    return a<=b && b<=c;
}

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
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
#define LL __int64
#define pii pair< int, int >
#define psi pair< string, int >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define vii vector<int, int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 10000

const int INF = 0x7f7f7f7f;
vector < int > graph[MAX], sorted;
bool taken[MAX], flag;
int indegre[MAX], num_drink, indx;

void topological_sort()
{
    int i, j, k, now ;
    queue < int >Q;

    for(i=0; i<indx; i++)
    {
        if(indegre[i]==0)
        {
            Q.push(i);
        }
    }

    while(!Q.empty())
    {

        now= Q.front();
        Q.pop();

        for(i=0; i<SZ(graph[now]); i++)
        {
            --indegre[graph[now][i]];

            if(indegre[graph[now][i]]==0)
            {
                Q.push(graph[now][i]);
            }
        }
    }

    for(i=0, flag=1; i<indx; i++)
    {
        if(indegre[i]>0)
        {
            flag=0;
            break;
        }
    }
}



int main()
{
    int tcase, t, i, j, k;
    char str1[100], str2[100];
    map <string , int> drink_map;
    string a, b;


    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        CLR(taken); CLR (indegre);
        scanf("%d", &num_drink);

        for(i=0; i<num_drink; i++)
        {
            scanf("%s %s", &str1, &str2);
            a= (string)str1;
            b= (string)str2;
            if(drink_map[ a ]==0)
            {
                drink_map[a]=indx++;
            }
            if(drink_map[b]==0)
            {
                drink_map[b]=indx++;
            }
            graph[drink_map[a]].pb(drink_map[b]);
            indegre[drink_map[b]]++;
        }

        topological_sort();

        if(flag==0)
        {
            printf("Case %d: No\n", t);
        }
        else
            printf("Case %d: Yes\n", t);

        for(i=0; i<indx; i++)
            graph[i].clear();
    }

    return 0;
}
