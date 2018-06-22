/*
该程序为多CASE，第1行为CASE的数量
每一个CASE，第1行为两个数N（行）和M（列）
然后N行每行M个数
之后是一个数W，为传送门的数量
之后每行一个传送门的入口坐标c1(行),r1(列)和出口坐标c2,r2
之后是起点坐标和终点坐标sc(行) sr(列) ec(行) er(列)

注：传送门出入口和起点坐标和终点坐标不会出现在墙的位置
所有数字不超过100


输出格式
如题


输入样例
2
4 3
011
011
110
110
1
1 0 2 2
0 0 3 2
2 2
01
10
0
0 0 1 1



输出样例
3
die
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
char map[100][100]={0};
pair<int ,int> gate[100][100]; // pass gate 
queue<pair<pair<int ,int>,int > > qu;

void addpos(int col,int row,int steps){
    qu.push(make_pair(make_pair(col,row),steps));
    if(map[col][row]!='3') map[col][row]='2';
}

int main(){
    int caseall;
    cin>>caseall;
    while(caseall--){
        int col,row,sc,sr,ec,er;
        cin>>col>>row;
        getchar();
        for(int i=0;i<col;i++) gets(map[i]); // input map
        int gatenum;
        cin>>gatenum;
        while(gatenum--){// input gate
            int c1,r1,c2,r2;
            cin>>c1>>r1>>c2>>r2;
            gate[c1][r1].first=c2;
            gate[c1][r1].second=r2;
            map[c1][r1]='3';
        }
        cin>>sc>>sr>>ec>>er; // input entrance exit
        addpos(sc,sr,0);
        int flag=1;
        while(!qu.empty()){
            pair<pair<int ,int>,int> tmp;
            tmp=qu.front();
            qu.pop();
            int tmpc=tmp.first.first,tmpr=tmp.first.second,tmpstep=tmp.second;
            if(tmpc==ec && tmpr==er){
                cout<<tmpstep<<endl;
                flag=0;
                break;
            }// exit
            else if(map[tmpc][tmpr]=='3')
                addpos(gate[tmpc][tmpr].first,gate[tmpc][tmpr].second,tmpstep+1);
            else{
                int c=tmpc+1,r=tmpr;
                if(c<col&&map[c][r]!='2'&&map[c][r]!='1')
                    addpos(c,r,tmpstep+1);
                c=tmpc-1,r=tmpr;
                if(c>=0&&map[c][r]!='2'&&map[c][r]!='1')
                    addpos(c,r,tmpstep+1);
                c=tmpc,r=tmpr+1;
                if(r<row&&map[c][r]!='2'&&map[c][r]!='1')
                    addpos(c,r,tmpstep+1);
                c=tmpc,r=tmpr-1;
                if(r>=0&&map[c][r]!='2'&&map[c][r]!='1')
                    addpos(c,r,tmpstep+1);
            }
        }
        if(flag) cout<<"die"<<endl;
    }
}
