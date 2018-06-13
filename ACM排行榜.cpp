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
