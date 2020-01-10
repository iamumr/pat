//暴力会超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    int n,a=0;
    cin>>n;
    int l,r,now,ans=0;
    while(n/pow(10,a)!=0){
        l=n/pow(10,a+1);
        int tmp=pow(10,a);
        r=n%tmp;
        now=n/tmp%10;
        ans+=(now==0)?l*pow(10,a):((now==1)?l*pow(10,a)+r+1:(l+1)*pow(10,a));
        a++;
    }
    cout<<ans;
    return 0;
}

