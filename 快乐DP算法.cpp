#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
    int ans[2000] = {0},v[55],w[55],n;
    scanf("%d",&n);
    for(int i = 0;i<n;scanf("%d",&v[i++]));
    for(int i = 0;i<n;scanf("%d",&w[i++]));
    for(int i = 0;i<n;i++)
        for(int j = 1999;j>=w[i];j--)
            ans[j] = max(ans[j],ans[j-w[i]]+v[i]);
    printf("%d\n",ans[1999]+1);
    return 0;
}
