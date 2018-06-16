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
