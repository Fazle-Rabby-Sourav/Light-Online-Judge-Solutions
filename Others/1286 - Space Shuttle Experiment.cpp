#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define INF (1<<30)
#define pii pair<int, int>

using namespace std;

int source, sink, par[210], cap[210][210], flow;
vector<int>adj[210];

bool aug_path()
{
    int i, u, v;
    queue<int>Q;
    Q.push(source);
    memset(par, -1, sizeof par);
    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        for(i=0;i<SZ(adj[u]);i++)
        {
            v = adj[u][i];
            if(par[v]==-1 && cap[u][v]>0)
            {
                par[v]=u;
                Q.push(v);
                if(v==sink)
                    return true;
            }
        }
    }
    return false;
}

void path_update(int v)
{
    int u = par[v];
    flow=min(flow, cap[u][v]);
    if(u!=source) path_update(u);
    cap[u][v]-=flow;
    cap[v][u]+=flow;
    return;
}

int maxflow()
{
    int ret=0;
    while(aug_path())
    {
        flow=INF;
        path_update(sink);
        ret+=flow;
    }
    return ret;
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int m, n, i, j, u, v, w, tot=0;
        scanf("%d%d", &m, &n);
        for(i=0;i<204;i++) adj[i].clear();
        memset(cap, 0, sizeof cap);
        source=0, sink=203;
        for(i=1;i<=m;i++)
        {
            scanf("%d", &w);
            adj[source].pb(i);
            adj[i].pb(source);
            cap[source][i]=w;
            tot+=w;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d", &w);
            adj[m+i].pb(sink);
            adj[sink].pb(m+i);
            cap[m+i][sink]=w;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d", &j);
            for(int k=0;k<j;k++)
            {
                scanf("%d", &v);
                adj[i].pb(m+v);
                adj[m+v].pb(i);
                cap[i][m+v]=INF;
            }
        }
        int ans = maxflow();
        ans = tot-ans;
        if(ans<0) ans=0;
        csprnt;
        printf("%d\n", ans);
    }
    return 0;
}
