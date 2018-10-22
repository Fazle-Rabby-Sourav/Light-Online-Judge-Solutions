/*
OJ: Light OJ
Name Fazle Rabby Sourav

Problem Link: http:http://www.lightoj.com/volume_showproblem.php?problem=1209
Problem Name: 1209 - Strange Voting
Rank: 41
*/


/*
Solution Method:
It seems to me a tricky BPM problem. At the first look, one may think about the Candidates. but here the data of candidates is useless. it is used for
making the problem difficult to dissect. we will concern about the data of male and female voters. at first we make two sets , one is male and another is female, and
save the input data in it. and we assume every person as a single node. then if a male voter prefer i-th candidates and any other female voter wants that i-th cadidates
to be thrown, then we will make an edge between them. after making setting up all edges we will run bipartite matching function. thus we will get maximum matching of that graph.

now we get the maximum matching. but in this case what does it mean by maximum matching??
it is the number of voters whom cant be satisfied.... so the final ans will be number of voters minus the maximum matching.
Thus we can get the maximum number of voters to be satisfied.

*/

 /*
 Complexity Analysis:
 if n is the number of voters. complexity of DFS is O(V+E). here edge/nodes can be at most n. the complexity of this solution will be O(n*(n+n)). or O(n^2);
 */

///********************************************Code******************************************///

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

#define CLR(p) memset(p, 0, sizeof(p))
#define mset(p, v) memset(p, v, sizeof(p))
#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)

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

int m, f, v, taken[MAX], par[MAX];
vi edge[MAX];
vii male, fem;

bool dfs(int from)
{
    if(taken[from]==1)  return false;
    int i, to;
    taken[from]=1;

    REP(i, SZ(edge[from]))
    {
        to= edge[from][i];
        if(par[to]==-1 || dfs(par[to]))
        {
            taken[to]=1;
            par[to]= from;
            return true;
        }

    }
    return false;
}

int matching()
{
    int i, j, k, cnt=0;
    mset(par, -1);
    for(i=0; i<SZ(male); i++)
    {
        CLR(taken);
        if(dfs(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int i, j, k, result, t=0, tcase, n, cnt, x, y;
    string str1, str2;

    cin>>tcase;
    while(tcase--)
    {
        cin>>m>>f>>v;
        male.clear();
        fem.clear();
        REP(i, v)
        {
            cin>>str1>>str2;

            if(str1[0]=='M')
            {
                str1= str1.substr(1);
                str2= str2.substr(1);
                stringstream strm;

                strm<<str1;                strm>>x;
                strm.clear();
                strm<<str2;                strm>>y;

                male.pb(MP(x, y));
            }
            else
            {
                str1= str1.substr(1);
                str2= str2.substr(1);
                stringstream strm;

                strm<<str1;                strm>>x;
                strm.clear();
                strm<<str2;                strm>>y;

                fem.pb(MP(y, x));
            }
        }

        REP(i, SZ(male))
        {
            REP(k, SZ(fem))
            {
                if(male[i].fs==fem[k].fs)
                {
                    edge[i].pb(k+500);                    edge[k+500].pb(i);
                }
                else if(male[i].sc==fem[k].sc)
                {
                    edge[i].pb(k+500);                    edge[k+500].pb(i);
                }
            }
        }
        result= matching();
        printf("Case %d: %d\n", ++t, v-result);

        REP(i, MAX)
        {
            edge[i].clear();
        }
    }
}

/*

problem Statement:
Its year 3000, and the voting system in Ajobdesh has changed to a new era. Instead of the boring old style voting, the new style voting is applied as follows:

1.      Initially there are m male candidates and f female candidates for the parliament. For simplicity the male candidates are numbered as 'M1', 'M2' ... 'Mm' and the female candidates are numbered as 'F1', 'F2' ... 'Ff'.
2.      There are v voters, and each of them can vote like 'P Q', which means, he wants to see P in the parliament and he wants Q to be thrown out of the parliament. For example, if a person voted like, 'M3 F7', that means he wants M3 to be elected and F7 to be thrown out.
3.      The parliament will be formed in such a way that the maximum number of votes is satisfied. A voter, who voted 'P Q', is said to be satisfied if P is in the parliament and Q is not. For example, let the parliament be {M1, M3, F3}, then voter who voted 'M1 F4' is satisfied but neither of 'M1 F3', 'F3 M3' or 'M2 F3' is satisfied.

Since Men don't want to see any Woman in the parliament, each man always votes like 'Mx Fy'. And Women don't want Men in the parliament, so each woman always votes like 'Fy Mx'. Assume that only Men and Women are eligible for voting.

Since you are the leading programmer in Ajobdesh, you have to form the parliament such that maximum number of voters is satisfied. Just report the maximum number of satisfied voters.

Input
Input starts with an integer T (≤ 25), denoting the number of test cases.

Each case starts with a line containing three integers: m, f, v (1 ≤ m, f ≤ 100, 0 ≤ v ≤ 500). Each of the next v lines contains a vote either in the form 'Mx Fy' or 'Fy Mx' (1 ≤ x ≤ m, 1 ≤ y ≤ f).

Output
For each case, print the case number and the maximum number of satisfied voters.

Sample Input
Output for Sample Input
2
1 1 2
M1 F1
F1 M1
1 2 5
M1 F1
M1 F1
M1 F2
F2 M1
F1 M1
Case 1: 1
Case 2: 3
*/
