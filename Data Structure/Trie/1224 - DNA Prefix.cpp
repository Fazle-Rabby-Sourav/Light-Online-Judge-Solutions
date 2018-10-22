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

#define REP(i,n)for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FORE(i, p, k) for(i=p; i<=k; i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FORD(i,n)    for(i=n;i>=0;i--)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define REV(s, e) reverse(s, e)

#define ll long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define vs vector<string>
#define vi vector<int>
#define vii vector< pair<int, int> >

#define fs first
#define sc second
#define MP(x, y) make_pair(x, y)
#define pii pair< int, int >
#define psi pair< string, int >
#define pq priority_queue

#define LOG(x,BASE) (log10(x)/log10(BASE))
#define EQ(a,b)     (fabs(a-b)<ERR)

/**biwise operation**/
#define two(X)          (1<<(X))
#define twoL(X)         (((ll)(1))<<(X))
#define setBit(mask,i)  (mask|two(i))
#define contain(S,X)    (((S)&two(X))!=0)
#define containL(S,X)   (((S)&twoL(X))!=0)
#define popc(i) (__builtin_popcount(i))

#define PI acos(-1)
#define ERR 10E-5
#define MAX 100005
const int INF = 0x7f7f7f7f;


struct trie
{
    int cnt_path;
    int scal[4];
};

int T, n, len, result;
char str[52];
//vector < trie > arr;
trie arr[900000];
void update(int cur, int ind)
{
    if(cur==len)
    {
        arr[ind].cnt_path++;
        result= max(result, (arr[ind].cnt_path*(cur)));
        return;
    }

    int ch, new_ind;
    if(str[cur]=='A')      ch= 0;
    else if(str[cur]=='C') ch= 1;
    else if(str[cur]=='G') ch= 2;
    else ch= 3;

    arr[ind].cnt_path++;
    result= max(result, (arr[ind].cnt_path*(cur)));

    if(arr[ind].scal[ch]==-1)
    {
        arr[ind].scal[ch]= ++T;
        arr[T].cnt_path=0;
        arr[T].scal[0]=arr[T].scal[1]=arr[T].scal[2]=arr[T].scal[3]=-1;
    }
    update(cur+1, arr[ind].scal[ch]);
}

int main()
{
    int i, j, k, t=0, tcase;
    cin>>tcase;
    while(tcase--)
    {
        scanf("%d ", &n);
        T=0;        result= - INF;
        arr[T].cnt_path=0;
        arr[T].scal[0]=arr[T].scal[1]=arr[T].scal[2]=arr[T].scal[3]=-1;
        for(i=0; i<n; i++)
        {
            scanf("%s", &str);            len= strlen(str);
            update(0, 0);
        }
        printf("Case %d: %d\n", ++t, result);
    }
}
