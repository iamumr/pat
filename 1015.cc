#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
int radix_change(int n,int d){
    string ans;
    int t;
    while(n!=0){
        t=n%d;
        n/=d;
        ans.append(1,t);
    }
    int sum=0;
    for(int i=0;i<ans.size();++i){
        sum=sum*d+ans[i];
    }
    return sum;
}
bool isPrime(int n){
    if(n<=1) return false;
    int q=sqrt(n*1.0);
    for(int i=2;i<=q;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n,d;
    while(1){
        cin>>n;
        if(n<0) return 0;
        cin>>d;
        if(isPrime(n)==false) cout<<"No"<<endl;
        else{
            if(isPrime(radix_change(n,d))==false) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}

