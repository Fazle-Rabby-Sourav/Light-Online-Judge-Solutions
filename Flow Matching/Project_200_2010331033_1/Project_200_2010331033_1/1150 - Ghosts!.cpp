/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1150
Problem Name: 1150 - Ghosts!
Rank: 26
*/

 /*
 Solution Method:
 I have used Matching algorithm with Binary search and Breadh-first search to solve this problem.

 For each ghost we have to find the minimum distance between ghost and human. it can be done by BFS. then we need to create edge
 from the ghost to reachable human. the weight of the edge will be the minimum distance. Then I have used B- search to find the
 minumum time to frigten\reach every human. with the help of binary search, for every mid value [time] I have run Matching algo to
 check that if it is possible to reach every human in that time or not. if that is possible we decrease upper limit to mid value.
 or that's not possible then we change lower limit to mid_value+1. thus we can find the minimum required time.
 */

/*
Complexity Analysis:
time complexity of BFS is O(|V|+|E) . BPM with binary search its need O(lgN) and Fo BPM its nedded O(V*(V+E)).
So the Complexity of the solution will be O( (|V|+|E|) + lgN*(V*(V+E))) or  O(lgN*(V*(V+E)))
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

#define MAX 55

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
//template< class T > inline T MOD(T n, T m){    return (n%m+m)%m;}

//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int xx[]={1,0,-1,0};				int yy[]={0,1,0,-1}; //4 Direction
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

#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)

//Type Definition
//typedef long long ll;
//typedef pair<int,int> pii;
//typedef vector<int> vi;
//typedef vector<vi>vvi;
//typedef vector< pair<int , int> > vii;
//typedef vector<string> vs;
//typedef map<string,int> msi;
//typedef map<int,int>mii;

///#define type
#define ll long long int
#define vs vector<string>
#define vi vector<int>
#define vii vector< pair<int, int> >
#define pii pair< int, int >
#define psi pair< string, int >

#define fs first
#define sc second
#define MP(x, y) make_pair(x, y)
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

int n, par[ 150 ], dist[MAX][MAX];
bool taken[MAX][MAX], col[150];
char grid[30][30];


vii edge[MAX];
vii ghost, human;

void BFS(int st_x, int st_y)
{
    int i, to_x, to_y, n_x, n_y, from_x, from_y;
    queue <pair <int , int > > Q;
    CLR(taken);
    CLR(dist);

    Q.push(MP(st_x, st_y));
    dist[st_x][st_y]=0;

    while(!Q.empty())
    {
        from_x= Q.front().fs;
        from_y= Q.front().sc;
        Q.pop();

        REP(i, 4)
        {
            to_x= from_x+xx[i];
            to_y= from_y+yy[i];

            if(to_x>=0 && to_x<n && to_y>=0 && to_y<n && grid[to_x][to_y]!='#' && taken[to_x][to_y]==false)
            {
                Q.push(MP(to_x, to_y));
                dist[to_x][to_y]= dist[from_x][from_y]+1;
                taken[to_x][to_y]=true;
            }
        }
    }
    return;
}


bool dfs(int from, int val)
{
    if(col[from])   return false;
    col[from]=1;
    int i, to, w;
    REP(i, SZ(edge[from]))
    {
        to= edge[from][i].fs;
        w= edge[from][i].sc;
        if(w<=val)
        {
            if(par[to]==-1 || dfs(par[to], val))
            {
                par[to]= from;
                return true;
            }
        }
    }
    return false;
}


int BPM(int val)
{
    int i, k, cnt=0;
    mset(par, -1);
    REP(i, SZ(ghost))
    {
        CLR(col);
        if(dfs(i, val))
            cnt++;
    }
    return cnt;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i, j, k, result, t=0, tcase, m, cnt, max_t;

    cin>>tcase;
    while(tcase--)
    {
        cin>>n;

        REP(i, n)
            scanf("%s", grid[i]);

        REP(i, n)
        {
            REP(k, n)
            {
                if(grid[i][k]=='G') ghost.pb(MP(i, k));
                if(grid[i][k]=='H') human.pb(MP(i, k));
            }
        }
        max_t= -1;
        REP(i, SZ(ghost))
        {
            BFS(ghost[i].fs, ghost[i].sc);
            REP(k, SZ(human))
            {
                int x, y;
                x= human[k].fs;
                y= human[k].sc;
                if(dist[x][y])
                {
                    edge[i].pb(MP(k+MAX, ( (dist[x][y]*2)+2) ));
                   // deb(ghost[i].fs, ghost[i].sc, x, y, dist[x][y]);
                   // max_t= max(max_t, ( (dist[x][y]*2)+2));
                }
            }
        }

        int upper= n*n, lower=0, mid, x;
        while(lower<upper)
        {
            mid= (lower+upper)/2;
         //   bug(mid);
            x=BPM(mid);
        //    bug(x);
            if(x==SZ(human))    upper= mid;
            else        lower= mid+1;
        }

        printf("Case %d: ", ++t);

        if(lower== n*n)
            printf("Vuter Dol Kupokat\n");
        else
            printf("%d\n", lower);
    //    deb(SZ(human), max_t, mid);

        ghost.clear();
        human.clear();
    //    CLR(grid);
        REP(i, MAX)
        {
            edge[i].clear();
        }
    }

}

/*
problem Statement:
1150 - Ghosts!
Time Limit: 2 second(s)	 Memory Limit: 32 MB

It's a dark, cloudy and spooky night. The ghosts of 'VutPara' graveyard have awakened. They are planning to take revenge against humans. They are dead but the humans are alive that's their main headache. So, they want to frighten all the people nearby.

'Vutpara' can be described as an n x n grid. Each cell can be one of the following types:

'.' - The cell is empty
'G' - The cell contains a ghost
'H' - The cell contains a human
'#' - The cell contains over-polluted air, the ghosts can't fly over this cell

The ghosts can move vertically or horizontally but not diagonally. And they can fly to any cell if the air is not over-polluted. It takes one minute to move to an adjacent cell. And it takes two minutes to frighten a human if the ghost is flying over the human (means that the position of the ghost and the human is same). But the ghosts are quite lazy, so any ghost can frighten at most one human. And after their work is done they want to go back to their grave (Initial position).

The night is getting over and they have a little time left. As they are smart enough they know all the human positions and the map. Now they want to frighten all the humans in the map using minimum time.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case starts with a blank line and an integer n (5 ≤ n ≤ 25). Then n lines follow. Each of the line contains n characters each describing 'Vutpara'. You can assume that number of ghosts is always greater than or equal to the number of humans and the number of ghosts is no more than 50. And there is at least one human in the map.

Output
For each case of input, print the case number and the minimum time needed to frighten all the people or 'Vuter Dol Kupokat' if it's not possible to frighten all the people.

Sample Input
Output for Sample Input
4

8
....##..
.....#..
..#...G.
G...####
H#..HG.G
#....#.#
H.#G..H.
..##...#

6
......
G.....
......
......
......
.....H

6
.....G
.H....
......
......
....H.
G.....

6
#.#G#.
G....#
G..##.
H###.#
...#H#
..#GHH
Case 1: 12
Case 2: 20
Case 3: 12
Case 4: Vuter Dol Kupokat
 */
