#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
bool isPrime(long long n){
    if(n<=1) return false;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    vector<long long> ans;
    long long n;
    cin>>n;
    cout<<n<<"=";
    if(n==1) {
        cout<<"1";
        return 0;//特判1，否则会报错，因为1不是素数
    }
    long long i=2;
    while(n>1&&i<=50000){
        long long nowt=0;
        while(n>1){
            if(isPrime(i)&&n%i==0){
                nowt++;
                n/=i;
            }else{break;}
        }
        if(nowt!=0){
            ans.push_back(i);
            ans.push_back(nowt);
        }
        i++;
    }
    for(int i=0;i<ans.size();i+=2){
        if(i!=0)cout<<"*";
        cout<<ans[i];
        if(ans[i+1]!=1)cout<<"^"<<ans[i+1];
    }
    if(n>1) cout<<n;
    return 0;
}

