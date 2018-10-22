#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include <cstdlib>
#include <algorithm>

#define MAX 1000010     //1 koti

using namespace std;

int factorial[MAX];

int extended_gcd ( int a, int b, int  &x, int  &y)
{
    if  ( a ==  0 )
    {
        x =  0 ;
        y =  1 ;
        return b ;
    }
    int x1, Y1 ;
    int d = extended_gcd( b % a, a, x1, Y1 ) ;
    x = Y1 -  ( b / a )  * x1 ;
    y = x1 ;
    return d ;
}
int inverse_modulo (int a, int m)
{
    int x, y, d;
    x=0; y=0;
    d= extended_gcd(a, m, x, y);

    if(d==1)
        return (x+m)%m;
}

void factmod(void)
{
    int i, j, mod;
    mod=1000003;
    long long int num;

    for(i=1, num=1; i<=1000005; i++)
    {
        num*=i;
        num%=mod;
        factorial[i]=num;
    }
    factorial[0]=1;
}


int main()
{
    int n, k, r, test_case, t, i, j, a, m ,x , y, k_in, r_in, mod;
    long long int result;
    factmod();
    mod=1000003;

    scanf("%d", &test_case);

    for(t=1; t<=test_case; t++)
    {
        scanf("%d %d", &n, &k);
        result=0;

        r= (n-k);

        r_in= inverse_modulo(factorial[r], mod);
        k_in= inverse_modulo(factorial[k], mod);
        result= ((long long)factorial[n]* (long long)r_in)%mod;
        result= (result*k_in)%mod;
        printf("Case %d: %lld\n",t, result);
    }

}
