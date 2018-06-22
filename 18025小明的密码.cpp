/*
小明的密码由N（1<=N<=12）个数字构成，每个数字都可以是0至9中任意一个数字，但小明的密码还有
一个特点就是密码中连续的M（1<=M<=4）个数字的和是质数，现给定M和N，求满足条件的密码共有多少
个？



输入格式
第1行是T，case数量，此后T行，每行两个数，N和M


输出格式
每个case输出一个满足条件的密码总数


输入样例
2
1 1
2 1


输出样例
4
16
*/
#include<cstdio>
#include<iostream>
#define MAXN 12

using namespace std;
int P[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
int count=0;

void permutation(int N, int A[], int cur, int M)
{
    if(cur==N)
        count++;
    else
    {
         int sum,i;
         for(i=0;i<=9;i++)
         {
             if(cur>M-2)
             {
                 sum=i;
                 for(int k=cur-M+1;k<cur;k++)
                     sum=sum+A[k];
             }
             if(cur<=M-2 || P[sum]==1)
             {
                 A[cur]=i;
                 permutation(N,A,cur+1,M);
             }
         }
    }
}

int main()
{
    int N,M,A[MAXN],T;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        count=0;
        permutation(N,A,0,M);
        cout<<count<<endl;
    }
    return 0;
}
