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
#define MAX 55
#define MAX_indx 18000
const int INF = 0x7f7f7f7f;

int num_forbiden;
map < string, int > map_toy;
vector < string > toys;
string str, initial, target, inpt;
char dummy_str[5], input1[30], input2[30], input3[30];
int taken[MAX_indx],dist[MAX_indx], indx;
vector < int > GRAPH[MAX_indx];

void reset(void)
{
    int i, j, k;
    for(i=0; i<26; i++)
    {
        for(k=0; k<26; k++)
        {
            for(j=0; j<26; j++)
            {
                dummy_str[0]= 'a'+i;
                dummy_str[1]= 'a'+k;
                dummy_str[2]= 'a'+j;
                dummy_str[3]= '\0';
                str= dummy_str;
                toys.pb(str);
            }
        }
    }
    for(i=0; i< toys.size(); i++)
    {
        map_toy[toys[i]]= i;
    }
}

void setting_edge (void)
{
    int i, j, k;
    for(i=0; i< SZ(toys) ; i++)
    {

        //previous press
        for(k=0; k<3; k++)
        {
            str= toys[i];
            if(toys[i][k]=='a')
            {
                str[k]='z';
            }
            else
            {
                str[k]= toys[i][k]-1;
            }
            GRAPH[i].pb(map_toy[str]);
        //  cout<<str<<" ";
        }
        //next press
        for(k=0; k<3; k++)
        {
            str= toys[i];
            if(toys[i][k]=='z')
            {
                str[k]='a';
            }
            else
            {
                str[k]= toys[i][k]+1;
            }
            GRAPH[i].pb(map_toy[str]);
        }

    }
}

void BFS(int src)
{
    int i, j, k, from, to;
    queue < int > Q;

    if(!taken[src])
    {
        taken[src]=1;
        Q.push(src);
        dist[src]=0;
        while(!Q.empty())
        {
            from= Q.front();
            Q.pop();
            for(i=0; i<SZ(GRAPH[from]); i++)
            {

                to = GRAPH[from][i];
                if(!taken[to])
                {
                    taken[to]=1;
                    dist[to] = dist[from]+1;
                    Q.push(to);
                }
            }
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int tcase, t, i, j, k, m, len1, len2, len3;
    vector < int > forbidden_indx;
    reset();
    setting_edge();

    scanf("%d", &tcase);

    for(t=1; t<=tcase; t++)
    {
        CLR(taken); CLR(dist);

        cin>>initial>>target;

        scanf("%d", &num_forbiden);
        for(m=0; m<num_forbiden; m++)
        {
            scanf("%s %s %s", &input1, &input2, &input3);
            len1= strlen(input1); len2= strlen(input2); len3= strlen(input3);

            for(i=0; i<len1; i++)
            {
                for(j=0; j<len2; j++)
                {
                    for(k=0; k<len3; k++)
                    {
                        dummy_str[0]= input1[i];
                        dummy_str[1]= input2[j];
                        dummy_str[2]= input3[k];
                        dummy_str[3]= '\0';
                        str= dummy_str;
                        forbidden_indx.pb( map_toy[str] );
                        taken[map_toy[str]]=1;
                    }
                }
            }
        }
        BFS(map_toy[initial]);
        int flag=1, target_indx;
        if( taken[map_toy[target]]==1)
        {
            target_indx=map_toy[target];
            //for checking if target is a forbidden str or not
            for(i=0; i<SZ(forbidden_indx); i++)
            {
                if(forbidden_indx[i]==target_indx)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                printf("Case %d: %d\n", t, dist[ target_indx ]);
            else
                printf("Case %d: -1\n", t);

        }
        else
        {
            printf("Case %d: -1\n", t);
        }
        forbidden_indx.clear();
    }
    return 0;
}
