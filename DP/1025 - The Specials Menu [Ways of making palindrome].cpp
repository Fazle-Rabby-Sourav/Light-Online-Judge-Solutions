#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define pb push_back
#define clean(a,b) memset(a,b,sizeof(a))
#define oo 1<<20
#define dd double
#define ll long long
#define ull unsigned long long
#define ff float
#define EPS 10E-5
#define fr first
#define sc second
#define MAXX 100000
#define PRIME_N 1000000
#define PI (2*acos(0))
#define INFI 1<<30
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()

//int rx[] = {0,-1,0,1,1,-1,-1,0,1}; //four direction x
//int ry[] = {0,1,1,1,0,0,-1,-1,-1   //four direction y
//int rep[] = {1,1,4,4,2,1,1,4,4,2}; //repet cycle for mod
//void ullpr(){printf("range unsigned long long : %llu\n",-1U);} //for ull
//void ulpr(){printf("range unsigned long : %lu\n",-1U);} //for ull
//void upr(){printf("range unsigned : %u\n",-1U);} //for ull

ll dp[70][70][3];
char str[1000];

ll rec(ll st,ll ed,ll state)
{
    if(st>ed) return state;

    if(dp[st][ed][state]!=-1) return dp[st][ed][state];
    dp[st][ed][state]= 0;

    if(str[st]==str[ed])
    {
        dp[st][ed][state] += rec(st+1,ed-1,1);
    }
    dp[st][ed][state] += rec(st+1,ed,state);
    dp[st][ed][state] += rec(st,ed-1,state);
    dp[st][ed][state] -= rec(st+1,ed-1,state);
    return dp[st][ed][state];
}

int main()
{
    ll tcase,cas=1;
    scanf(" %lld",&tcase);
    while(tcase--)
    {
        scanf(" %s",str);
        clean(dp,-1);
        ll ans = rec(0,strlen(str)-1,0);
        printf("Case %lld: %lld\n",cas++,ans);
    }
    return 0;
}
