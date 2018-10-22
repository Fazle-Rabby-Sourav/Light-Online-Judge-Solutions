/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1176
Problem Name: 1176 - Getting a T-shirt
Rank: 59
*/


/*
Statement:
In programming contests, a common problem for the contestants is to get a suited T-shirt. Sometimes people gets too long or too short T-shirts.
 So, this time I have planned to ask the authority to manage the T-shirts such that everyone gets a suitable one. From my past experience, it's
known that there are 6 available sizes of T-shirts and they are XXL, XL, L, M, S, and XS. And exactly two sizes of the T-shirts suit a person.

Now, for a contest there are T-shirts of N colors and M contestants. And for each color, all the 6 sizes are available. So, there are 6*N T-shirts.
And you are given the suitable sizes for each contestant. You have to distribute the T-shirts to the contestants such that everyone gets a suitable
size. Only size matters, color is not an issue. Now you have to decide whether it's possible or not.
*/

/*
Solution Method:
first we need to create nodes for every person. then connect them with source node, the wight of the edge will be 1 as a person will get only
one T shirt from his two choice. another set of nodes will be created for different sizes. Person's node need to be conneccted with his preferablee
both of the two size nodes. then we connect the size nodes with sink node. then we try to send flow. after sending flow on possible every augmenting
path , if the maximum flow is equal to the number of person, then it is possible to give every person according to their suitable size. other
wise not.
*/

/*
Complexity Analysis:
each augmenting path can be found in O(E) time.  that every time at least one of the E edges becomes saturated that
the distance from the saturated edge to the source along the augmenting path must be longer than last time it was saturated,
 and that the length is at most V. So it will be O(V*E^2) .
*/


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
template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int xx[]={1,0,-1,0};              int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};    int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};   int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

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

#define csprint printf("Case %d: ", ++t);
#define PI acos(-1)
#define ERR 10E-5

const int INF = 0x7f7f7f7f;

#define MAX 555

/** debugging**/
#define bug(x) cout<<"->"<<#x<<": "<<x<<endl;
#define bugg(x, y) cout<<"->"<<#x<<": "<<x<<"\t\t"<<#y<<": "<<y<<endl;
#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
struct debugger
{    // Taken from rudradevbasak
    template<typename T> debugger& operator , (const T& v)    {        cerr<<v<<" ";        return *this;    }
} dbg;
template<class T> void deb(T e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T> void deb(vector<T> e){int i;REP(i,SZ(e)) cout<<e[i]<<" ";cout<<endl;}
template<class T> void deb(vector<T> e,int n){int i;REP(i,n) cout<<e[i]<<" ";cout<<endl;}
template<class T> void deb(vector< basic_string<T> > e){int i,j;REP(i,SZ(e)) {REP(j,SZ(e[i])) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void deb(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void deb(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<"\t";cout<<endl;} cout<<endl;}
template<class T> void deb(T e[MAX][MAX],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> void deb(T e[],int row){int i;REP(i,row) cout<<e[i]<<" ";cout<<endl;}

double deg2rad(double x){ return (PI*x)/180.0; }
double rad2deg(double x){ return (180.0*x)/PI; }

//prime check
template<class T> inline bool isPrime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
//int,double is converted to string
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//string is converted to int
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//string is converted to Long long
bool IsVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
//isUpperCase
bool isUpper(char c){return c>='A' && c<='Z';}
//isLowerCase
bool isLower(char c){return c>='a' && c<='z';}
//compute b^p
ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
//compute b^p%m
int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
//print a number in binary format with n length
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);reverse(ALL(s) );s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
//ASCII Chart
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}

int n_cont, n_col, source, sink, min_flow, par[MAX], cap[MAX][MAX];
vi edge[MAX];
map<string, int> indx;

bool path_find()
{
    int from, to, i, j, k;
    mset(par, -1);
    queue<int> Q;
    Q.push(source);
    while(!Q.empty())
    {
        from= Q.front();
        Q.pop();

        for(i=0; i<SZ(edge[from]); i++)
        {
            to = edge[from][i];

            if(par[to]==-1 && cap[from][to]>0)
            {
                Q.push(to);
                par[to]=from;
                if(to==sink)   return true;
            }
        }

    }
    return false;
}
void path_update(int now)
{
    int prev= par[now];
    min_flow= min(min_flow, cap[prev][now]);

    if(prev!=source)    path_update(prev);

    cap[prev][now] -= min_flow;
    cap[now][prev] += min_flow;
    return;
}
int max_flow()
{
    int i, j, k, res=0;
    while(path_find())
    {
        min_flow= INF;
        path_update(sink);
        res+= min_flow;
    }
    return res;
}
int main()
{
    int i, j, k, result, t=0, tcase, cnt, x;
    cin>>tcase;

    indx["XXL"]=0;
    indx["XL"]= 1;
    indx["L"]= 2;
    indx["M"]= 3;
    indx["S"]= 4;
    indx["XS"]= 5;

    string str;
    int lim=110, sub_lim=450;

    while(tcase--)
    {
        scanf("%d %d", &n_col, &n_cont);

        for(i=1, k=1; i<=n_cont; i++)
        {
            cin>>str;
            for(j=0; j<n_col; j++)
            {
                x= lim+(indx[str]*n_col)+j;

                edge[k].pb(x);
                edge[x].pb(k);
                cap[k][x]=1;
            }
            k++;
            cin>>str;
            for(j=0; j<n_col; j++)
            {
                x= lim+(indx[str]*n_col)+j;
                edge[k].pb(x);
                edge[x].pb(k);
                cap[k][x]=1;
            }
            k++;
        }
        source=0;
        sink= MAX-1;

        for(i=1, k=1; i<= n_cont; i++)
        {
            int y=sub_lim+i;

            edge[source].pb(y);
            edge[y].pb(source);
            cap[source][y]=1;

            edge[y].pb(k);
            edge[k].pb(y);
            cap[y][k]=1;
            k++;
            edge[y].pb(k);
            edge[k].pb(y);
            cap[y][k]=1;
            k++;
        }
        for(i= lim; i<lim+(6*n_cont); i++)
        {
            edge[i].pb(sink);
            edge[sink].pb(i);
            cap[i][sink]=1;
        }
        result= max_flow();
        printf("Case %d: ", ++t);
        if(result==n_cont)
            printf("YES\n");
        else
            printf("NO\n");
        CLR(cap);
        for(i=0; i<MAX; i++)
        {
            edge[i].clear();
        }
    }
}
