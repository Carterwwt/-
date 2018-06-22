/*
第一行有一个整数n，代表有多少个数据（1<=n<=20）。接下来有n行，每行代表一个数据。一个数据就是一个整数r，内切圆半径（1<=r<=100）。


输出格式
每个数据都必须有相应的输出。两个数据的输出之间有一个空行。
对于每一个数据，如果找不到解，则输出一个空行。如果找到解，就把符合条件的所有直角三角形输出。每个三角形占一行，输出该三角形三边，按由短到长，
必须先输出短边，然后一个逗号，再输出长边。两个三角形之间不能有空行，而且必须按照短边升序排列。


输入样例
2
5
10


输出样例
11,60,61
12,35,37
15,20,25

21,220,221
22,120,122
24,70,74
25,60,65
28,45,53
30,40,50
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int r,a;
        double b,c;
        cin>>r;
        for(int k=1;;k++){
            a=r*2+k;
            b=(2*a*r-2*r*r)*1.0/(a-2*r);
            if(a>b) break;
            if(b!=(int)b) continue;
            c=sqrt(a*a+b*b);
            if(c!=(int)c) continue;
            cout<<a<<","<<(int)b<<","<<(int)c<<endl;
        }
        if(n) cout<<"\n";
    }
    return 0;
}
