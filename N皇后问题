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
