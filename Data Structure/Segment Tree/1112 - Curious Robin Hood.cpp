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
#define MAX 100050

int n, num_query;
int tree[4*MAX], sack[MAX];

int seg_tree(int node, int left, int right)
{
    if(left==right)
    {
        return tree[node]= sack[left];
    }
    int mid= (left+right)/2;
    int ret=0;
    ret+= seg_tree(node*2, left, mid);
    ret+= seg_tree( (node*2)+1, mid+1, right);
    return tree[node]= ret;
}

int query(int node, int left, int right, int left_lim, int right_lim)
{
    if(left>right_lim || right<left_lim)
        return 0;

    if(left>= left_lim && right<= right_lim)
        return tree[node];

    int mid= ((left+right)/2);
    int sum=0;
    sum+= query(node*2, left, mid, left_lim, right_lim);
    sum+= query( (node*2)+1, mid+1, right, left_lim, right_lim);

    return sum;
}

int _done(int node, int left, int right, int indx, int tk)
{
    if(left==right && left==indx)
    {
        tree[node]= tk;
        return tree[node];
    }
    int mid= ((left+right)/2);
    if(indx<=mid)
        _done(node*2, left, mid, indx, tk);
    else
        _done((node*2)+1, mid+1, right, indx, tk);

    tree[node]= tree[node*2]+ tree[((node*2)+1)];
    return tree[node];
}

int main()
{
    int i, j, k, result, t, tcase, _selector, x, ammount, a, b, indx;

    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        scanf("%d %d", &n, &num_query);
        for(i=0; i<n; i++)
        {
            scanf("%d", &sack[i]);
        }
        seg_tree(1, 0, n-1);
        printf("Case %d:\n", t);
        for(i=0; i<num_query; i++)
        {
            scanf("%d", &_selector);

            if(_selector==1)
            {
                scanf("%d", &indx);
                x= query(1, 0, n-1, indx, indx);
                _done(1, 0, n-1, indx, 0);
                printf("%d\n", x);
            }
            else if(_selector==2)
            {
                scanf("%d %d", &indx, &ammount);
                x=query(1, 0, n-1, indx, indx);
                _done(1, 0, n-1, indx, (x+ammount) );
            }
            else if(_selector==3)
            {
                scanf("%d %d", &a, &b);
                x= query(1, 0, n-1, a, b);
                printf("%d\n", x);
            }
        }
    }
}


VOLUME
Volume Home
Problem Set
Problem Category
Problem Setters
Submit Problem
My Submissions
Judge Status
Ranklist
User Statistics
Compare User Statistics

