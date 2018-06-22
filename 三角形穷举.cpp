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
