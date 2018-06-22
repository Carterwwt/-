/*
第一行一个整数N，1<=N<=100,000，表示坑的数量
此后N行，每一行三个double实数，前两个数是圆心的坐标x和y，最后一个数是圆半径（不大于1000）
(数据随机产生，分布均匀)


输出格式
湖的个数


输入样例
3
0 0 5
10 0 5
11.1 0 2.5


输出样例
2
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 100050
long long  p[MAXN];
CIRCLE circle[MAXN];

typedef struct{
    double x,y,r;
    double left;
}CIRCLE;


long long findset(long long x){
    if(p[x]==x) return x;
    return p[x]=findset(p[x]);
}//查找父亲节点并压缩路径


int cmp(CIRCLE a,CIRCLE b){
    return (a.left<b.left);
}

int ifunion(CIRCLE A,CIRCLE B){
    return (((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))<(A.r+B.r)*(A.r+B.r));
}//判断两圆是否相交

int main(){
    long long n;
    scanf("%lld",&n);
    long long count=n;
    for(long long i=0;i<n;i++) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
        circle[i].left=circle[i].x-circle[i].r;
        p[i]=i;
    }
    sort(circle,circle+n,cmp);
    for(long long i=0;i<n;i++) {
        for (long long j = i + 1; j < n; j++) {
            if (circle[i].x + circle[i].r <= circle[j].left) break;
            else {
                if (ifunion(circle[i], circle[j])) {
                    long long x = findset(i), y = findset(j);
                    if (x!= y)
                        count--;
                    p[y] = x;
                }
            }
        }
    }
    printf("%lld\n",count);
    return 0;
}
