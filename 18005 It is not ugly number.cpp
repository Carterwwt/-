/*
First line is T（T<=10000）, the number of cases.
The T lines following. Each line of the input contains a positive integer n (n <= 100000000).


输出格式
For each case, output the n'th Not ugly number .


输入样例
3
1
2
9


输出样例
7
11
23
*/
#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
ll ugly[1500];
priority_queue<ll,vector<ll>,greater<ll> > qu;
set<ll> s;
const int coeff[]={2,3,5};

int main()
{
    qu.push(1);
    s.insert(1);
    for(int i=1;i<=1500;i++){
        ll tmp=qu.top();
        qu.pop();
        ugly[i-1]=tmp;
        for(int j=0;j<3;j++){
            ll result=tmp*coeff[j];
            if(!s.count(result)){
                s.insert(result);
                qu.push(result);
            }
        }
    }
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll d,f=0,k,i;
        for(i=0;i<1499;i++){
            d=ugly[i+1]-ugly[i];
            if(d>1){
                d--;
                if(f+d<n)
                    f+=d;
                else{
                    k=ugly[i]+n-f;
                    cout<<k<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
