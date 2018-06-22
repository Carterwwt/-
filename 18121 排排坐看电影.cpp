/*
某理工学校A班全为男生，另有某师范学校B班全为女生。一次，两个班组织了一次联谊活动，观看电影
《美人鱼》，订完票发现所有位置为同一排且从1到T号（T为人的总数），为了让参加活动的每一个女生都有机会同
男生有对话的机会，组织者在安排座位时，让女生左或右，至少有一个男生。现在告诉你男生人数n，女生
人数m，问一共有多少种不同的座位安排方法。



输入格式
每一行一个数W（W<=100），为case数量
此后W行，每行两个数n和m


输出格式
每个case输出一个结果（使用long long）


输入样例
7
3 0
3 1
0 1
1 1
2 2
2 3
2 4


输出样例
6
24
0
2
16
36
48
*/
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
