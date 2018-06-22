/*
输入格式
每一个数为T，代表CASE的数量，T<=13
此后，每行一个数N（13>=N>0）


输出格式
每一个CASE，输出对应答案


输入样例
2
4
5


输出样例
2
10
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX 13

using namespace std;
int count=0;

void permutation(int n,int A[],int cur)
{
    if(cur==n)
        count++;
    else
    {
        for(int i=1;i<=n;i++)
        {
            int OK=1;
            for(int j=0;j<cur;j++)
            {
                if(A[j]==i||abs(A[j]-i)==abs(j-cur)){OK=0;break;}
            }
            if(OK)
            {
                A[cur]=i;
                permutation(n,A,cur+1);
            }
        }
    }
}

int main()
{
    int T,A[MAX];
    cin>>T;
    while(T--)
    {
        count=0;
        int n;
        cin>>n;
        permutation(n,A,0);
        cout<<count<<endl;
    }
    return 0;
}
