#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
long long measure(long long a,long long b){
    if(a<0) a=-a;
    return b==0?a:measure(b,a%b);
}
void add1(long long a,long long b,long long &c,long long &d){
    c=a*d+b*c;
    d=b*d;
    int m=measure(c,d);
    c/=m;d/=m;
}
void output(long long a,long long b){
    if(b<0){
        b=-b;
        a=-a;
    }
    if(a<0){
        cout<<"-";
        a=-a;
    }
    long long m=measure(a,b);
    a=a/m;b=b/m;
    if(a/b>=1){
        cout<<a/b;
        a=a-(a/b)*b;
        if(a==0) return;
        cout<<" "<<a<<"/"<<b;
    }else{
        if(a==0) {
            cout<<"0";
            return;
        }
        cout<<a<<"/"<<b;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    long long a,b,ans1=0,ans2=1;
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&a,&b);
        add1(a,b,ans1,ans2);
    }
    output(ans1,ans2);
    return 0;
}

