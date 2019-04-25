/*
OJ: Light OJ
Name Fazle Rabby Sourav
Rank: 68
Problem Link:  http://www.lightoj.com/volume_showproblem.php?problem=1201
*/

/*
Solution Method:
 we assume each mosqueto as an edge and if there is friendship between two mosquitos, then we need to set up an edge between them.
 In the statement it is mentioned that there will be no cycle. and there will be no self edge. we need to convert the graph  into a bipartite graph.
 we will run a DFS to devide all nodes to two sets where there is no edge between the elements of same set.[bipartite]

 then from every node we run a DFS to find the maximum matiching. what will the maximum matching in this case stands for??
 the maximum node number which are reachable from other set's node is the maximum mathing which is the same number of mosquito those are not possible to kill.
 So the desired ans will be- all mosquito minus the maximum matching[ which cant be killed ]
*/


/*
Comlexity Analysis:

for converting the graph into bipartite grphe it is needed to O(V*(E+V)) time
and for BPM its nedded to O(V*(V+E)) time
SO the complexity of the solution is O(V*(V+E))
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

//int xx[]={1,0,-1,0};				int yy[]={0,1,0,-1}; //4 Direction
//int xx[]={1,1,0,-1,-1,-1,0,1};	int yy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int xx[]={2,1,-1,-2,-2,-1,1,2};	int yy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define REP(i,n)for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FORE(i, p, k) for(i=p; i<=k; i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FORD(i,n)    for(i=n;i>=0;i--)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define REV(s, e) reverse(s, e)

//#define ll long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
//#define vs vector<string>
//#define vi vector<int>
//#define vii vector< pair<int, int> >
//#define vvi vector< vi >
#define fs first
#define sc second
#define MP(x, y) make_pair(x, y)
//#define pii pair< int, int >
//#define psi pair< string, int >
//#define pq priority_queue

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector < pair<int, int> > vii;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;


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

#define MAX 1005

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

///************************************************************* Code **********************************************************************///

int n, m, col[MAX], par[MAX];
vi adj[MAX], edge[MAX];


bool matching(int from)
{
    int to, i;

    REP(i, SZ(edge[from]))
    {
        to= edge[from][i];
        if(col[to]) continue;

        col[to]=1;
        if(par[to]==-1 || matching(par[to]))
        {
            par[to]= from;
            return true;
        }
    }
    return false;
}

int BPM()
{
    int i, j, cnt=0;

    for(i=1; i<=n; i++)
    {
        CLR(col);
        if(matching(i))
            cnt++;
    }
    return cnt;
}


void dfs(int from)
{
//    deb(from, "start");
    int i, to;
    REP(i, SZ(adj[from]))
    {
        to= adj[from][i];
        if(col[to]==-1)
        {
            col[to]= (col[from]^1);
//            bug(col[to]);
            dfs(to);

            if(col[from])
                edge[from].pb(to);
            else
                edge[to].pb(from);
        }
    }
}

void create_edge()
{
    int i, j, k;
    for(i=1; i<=n; i++)
    {
        if(col[i]==-1)
        {
            col[i]=1;
            dfs(i);
        }
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, result, t=0, tcase,u, v, cnt;


    cin>>tcase;
    while(tcase--)
    {
        scanf("%d %d", &n, &m);
        REP(i, m)
        {
            scanf("%d %d", &u, &v);

            adj[u].pb(v);
            adj[v].pb(u);
        }
      //  deb("ok");

        mset(col, -1);
        create_edge();

//        REP(i, n+1)
//            deb(i), deb(edge[i]);

        mset(par, -1);
        result=BPM();

        printf("Case %d: %d\n", ++t, (n-result) );

        REP(i, n+1)
        {
            edge[i].clear();
            adj[i].clear();
        }
    }
}

/*
Problem Statement:
"Yes, I am the murderer. No doubt" I had to confess it in front of all. But wait, why I am confessing? Nobody wants to go to jail, neither do I. As you have suspected there is something fishy. So, let me explain a bit.

The murder was happened in 19th June, at 11:30 pm this year (2009) according to the medical report. So, I was asking the judge "Can you find the time 19th June 11:30 pm in Bangladesh?" The judge informed other reporters to find the time. But alas! There was no time - "2009, 19th June, 11:30 pm". So, the judge got a bit confused about my confession. So, I began to tell them, "The time the murder was happened, is not a valid time according to you. So, how can you claim that I am the murderer?"

And what happened next, you all know. I am in the streets again with a clean sheet.

But now I have planned to kill again. I have a list of N mosquitoes which are to be killed. But there is a small problem. If I kill a mosquito, all of his friends will be informed, so they will be prepared for my attack, thus they will be impossible to kill. But there is a surprising fact. That is if I denote them as a node and their friendship relations as edges, the graph becomes acyclic.

Now I am planning when and how to kill them (how to get rid of the law!) and you have to write a program that will help me to find the maximum number of mosquito I can kill. Don't worry too much, if anything goes wrong I will not mention your name, trust me!

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with a blank line and two integers N (1 ≤ N ≤ 1000) denoting the number of mosquito I want to kill and M denoting the number of friendship configurations. Each of the next M lines contains two integers a and b denoting that ath and bth mosquitoes are friends. You can assume that (1 ≤ a, b ≤ N, a ≠ b) and each friendship relation is given only once. As I have already mentioned, you will not find any cycle in the relations.

Output
For each case, print the case number and the maximum number of mosquitoes I can kill considering the conditions described above.

Sample Input
Output for Sample Input
3

4 3
1 2
1 3
1 4

3 2
1 2
2 3

5 4
1 2
1 3
2 4
2 5
Case 1: 3
Case 2: 2
Case 3: 3
*/
