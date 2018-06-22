
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long gethappy[55],losspow[55],ans[55][2001]={0};
    for(int i=1;i<=n;i++) cin>>gethappy[i];
    for(int i=1;i<=n;i++) cin>>losspow[i];
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= 1999; j++) {
            if(j>=losspow[i])
                ans[i][j]=max(ans[i-1][j],ans[i-1][j-losspow[i]]+gethappy[i]);
            else
                ans[i][j]=ans[i-1][j];
        }
    }
    cout<<ans[n][1999]+1<<endl;
    return 0;
}
