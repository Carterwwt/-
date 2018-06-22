/*
每行一个评判结果，格式为：时间（第几分钟提交的）+半角空格+队名+半角空格+题号+半角空格+评判结果（0通过，其它为出错）

题号由大写A字符开始，第2题是B，依次类推，最多不超过15题
所有评判结果已经按时间排序好


输出格式
输出排名，一行一个，格式为队名+半角空格+通过题数+半角空格+罚时

注：0题的队伍不需要输出
测试数据中，没有同题且同罚时的情况


输入样例
2 abc A 4
5 abc B 0
6 def A 0
10 abc A 0
13 xyx A 4
20 def B 5


输出样例
abc 2 35
def 1 6
*/
#include <iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

struct SCORE
{
    char name[50];
    int acnum;
    int ifac[15];
    int time;
};

int cmp(struct SCORE a,struct SCORE b)
{
    if(a.acnum>b.acnum) return 1;
    else if(a.acnum==b.acnum && a.time<b.time)
        return 1;
    else if(a.acnum==b.acnum && a.time==b.time && strcmp(a.name,b.name)<0)
        return 1;
    else
        return 0;
}

vector<struct SCORE> scores;

int main()
{
    //freopen("data.txt","r",stdin);
    int time,count=0,i,k;
    char name[50];
    char question;
    int result;
    while(scanf("%d %s %c %d",&time,name,&question,&result)==4)
    {
        if(time==0) break;// test
        for(i=0;i<count;i++)
            if(strcmp(scores[i].name,name)==0)
                break;
        if(i==count)
        {
            count++;
            struct SCORE tmp;
            for(k=0;k<15;k++)
                tmp.ifac[k]=0;
            strcpy(tmp.name,name);
            tmp.acnum=0;
            tmp.time=0;
            scores.push_back(tmp);
        }
        if(scores[i].ifac[question-65]!=-1)
            if(result==0)
            {
                scores[i].acnum++;
                scores[i].time=scores[i].time+scores[i].ifac[question-65]*20+time;
                scores[i].ifac[question-65]=-1;

            }
            else
                scores[i].ifac[question-65]+=1;
        //printf("%s %d %d\n",scores[i].name,scores[i].acnum,scores[i].time);
    }
    sort(scores.begin(),scores.end(),cmp);
    //printf("name  ac  time\n");
    for(int i=0;i<count;i++)
    {
        if(scores[i].acnum==0) break;
        printf("%s %d %d\n",scores[i].name,scores[i].acnum,scores[i].time);
    }
}
