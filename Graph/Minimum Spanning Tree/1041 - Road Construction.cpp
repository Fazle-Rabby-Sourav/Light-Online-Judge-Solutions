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
#define pii pair< int, int >
#define psi pair< string, int >
#define PI acos(-1)
#define PQ priority_queue
#define VS vector<string>
#define VI vector<int>
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define DEBUG(x) if(x)
#define CNVRT acos(-1.00)/180.0
#define MAX 110

const int INF = 0x7f7f7f7f;
string town1, town2;
map <string, int> mymap;
vector <pair <int, pii> > GRAPH, MST;
int parent[MAX], total, N, E;
char str1[100], str2[100];

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}


void kruskal (void)
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end());
    total=0;
    for(i=0; i<(int)GRAPH.size(); i++)
    {
    //  cout<<"for ok";
        pu = findset(GRAPH[i].ss.ff, parent);
        pv= findset(GRAPH[i].ss.ss, parent);

        if(pu!=pv)
        {
        //  cout<<"ok";
            MST.pb(GRAPH[i]);
            total+= GRAPH[i].ff;
            parent[pv]= parent[pu];
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k, coast, index_town, indx_twn1, indx_twn2;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d", &N);
        mymap.clear();
        GRAPH.clear();
        MST.clear();

        for(i=1, index_town=1; i<=N; i++)
        {
            scanf("%s %s %d", &str1, &str2, &coast);
            town1= (string)str1;
            town2= (string)str2;

            if(mymap[town1]==0)
            {
                mymap[town1]=index_town;
                indx_twn1= index_town++;
            }
            else
                indx_twn1= mymap[town1];

            if(mymap[town2]==0)
            {
                mymap[town2]=index_town;
                indx_twn2= index_town++;
            }
            else
            {
                indx_twn2= mymap[town2];
            }
            GRAPH.push_back(pair <int, pii> (coast, pii(indx_twn1, indx_twn2) ));
        }

        for(i=1; i<index_town; i++)
        {
            parent[i]=i;
        }
//      for(i=0; i<(int)GRAPH.size(); i++)
//      {
//          cout<<GRAPH[i].ss.ff<<" "<<GRAPH[i].ss.ss<<" "<<GRAPH[i].ff<<endl;
//      }
        kruskal();
        int x, flag;
        x= findset(1, parent); flag=1;
        for(i=2; i<index_town; i++)
        {
        //  printf("%d->%d   ", i, parent[i]);
            if(findset(i, parent)!=x)
            {
                flag=0;
                break;
            }
        }

        printf("Case %d: ", t);
        if(flag==0 )
            printf("Impossible\n");
        else
        {
            printf("%d\n", total);
        }
    }
    return 0;
}
