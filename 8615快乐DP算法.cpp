/*
Lian是一个喜欢看动画片的人，自从成为ACMer（ACM爱好者）之后，他又迷上了网上做题。做题让他快乐，不过这也是需要付出精力的！！
假设有n道题，Lian做出第i道题后，他可以获得的快乐指数将增加gethappy[i]，而消耗掉的精力将是losspow[i]。
假设Lian初始的快乐指数为1，精力为2000。可以理解，如果他消耗完了所有的精力那他得到再多的快乐都没有用。
你的任务就是帮他计算他所能得到的最多的快乐指数，且最后他依然有多余的精力（即至少为1）。



输入格式
第一行输入一个整数n，表示有n个人。(n<=50)
第二行输入n个整数，表示gethappy[1]到gethappy[n]
第三行输入n个整数，表示losspow[1]到losspow[n]。


输出格式
一个整数，表示Lian所能获得的最大快乐指数。


输入样例
3
15 23 61
350 1301 1513



输出样例
77
*/
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
