#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int L[1001][1001] = {0};
char A[1001],B[1001];
int main()
{
    cin>>A>>B;
    int lena = strlen(A);
    int lenb = strlen(B);
    for(int i = 0;i<lena;i++) L[i][0] = 0;
    for(int i = 0;i<lenb;i++) L[0][i] = 0;
    for(int i = 1;i<=lena;i++)
    {
        for(int j = 1;j<=lenb;j++)
            if(A[i-1]==B[j-1]) L[i][j] = L[i-1][j-1] +1;
            else L[i][j] = max(L[i-1][j],L[i][j-1]);
    }
    printf("%d\n",L[lena][lenb]);
    return 0;
}
