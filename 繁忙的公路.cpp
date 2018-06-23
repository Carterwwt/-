#include <iostream>

using namespace std;

long long N;
long long data[1000010],s[1000010];
long long m;

long long lowbit(long long x)
{
    return x&(-x);
}

void updata(long long x,long long num)
{
    while(x<=N)
    {
        data[x]+=num;
        x+=lowbit(x);
    }
}

long long getsum(long long x)
{
    long long s=0;
    while(x>0)
    {
        s+=data[x];
        x-=lowbit(x);
    }
    return s;
}

int main()
{
    char ch;
    long long i,m,place,numtemp;
    cin>>N;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>ch>>place>>numtemp;
        if(ch=='H') updata(place,numtemp);
        else if(ch=='Q')
        {
            if(place>1) cout<<getsum(numtemp)-getsum(place-1)<<endl;
            else cout<<getsum(numtemp)<<endl;
        }
        else {cout<<"ERROR"<<endl;return 0;}
    }
}
/*繁忙的公路
时间限制:6000MS  内存限制:65535K
提交次数:0 通过次数:0
题型: 编程题   语言: G++;GCC
Description
在一条笔直的大道（单方向行车道）上，汽车川流不息。道路从起点到终点，等距离的标记了1到N，
即起点是1，然后分别是2、3、4.....，终点是N。每一个标记处，安装了智能探头，可以感知
在该点处车辆的增减数量。
一开始，整条道路上，没有车，然后，是不断接收到的智能探头发回的信息，格式如下：
H 5 9
H表明收到的是智能探头的回传信息，5表示标记5处的车辆信息，9表示该处车辆增加了9辆。
同时，在某个时刻，需要查询在一段连续的道路上，共有多少辆车
查询格式如下：
Q 3 10
Q表明收到的是查询，3是起点，10是终点（包括3和10两处）
要求编程实现正确处理上述信息处理和查询
输入格式
第一行一个整数N（1<=N<=1,000,000），表示标记范围是1到N
第二行一个整数M（1<=M<=100,000），表示探头信息（或查询）的总数量
此后M行，每行一个探头信息或查询请求
输出格式
每逢遇到查询的时候，输出查询范围内的有多少辆车，占一行，查询结果最大不超过2的63次方
输入样例
10
4
H 5 10
Q 1 10
H 6 20
Q 1 10
输出样例
10
30
提示
开始时，整条路上没有车辆
*/
