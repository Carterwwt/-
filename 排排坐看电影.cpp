#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
long long slove(int n,int m,int p,int pp)
{
    if(!n&&!m) return 1;
    if(n>0)
    {
        if(p!=1&&pp!=1) return n*slove(n-1,m,1,p);
        else return m*slove(n,m-1,0,p) + n*slove(n-1,m,1,p);
    }
    else if(m>0)
    {
        if(p==1&&m==1) return 1;
        else return 0;
    }
}

int main()
{
    int t,n,m;
    long long ans = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m>(n<<1)||!n) ans = 0;
        else ans = m*slove(n,m-1,0,-1) + n*slove(n-1,m,1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}
