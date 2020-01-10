//根号折中，暴力循环
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
    long long n;
    cin>>n;
    long long len=0,start=-1;
    for(long long i=2;i<=sqrt(n);i++){
        auto m=n;//别傻，把m放到下层循环就没有用了
        for(long long j=i;j<=sqrt(n)+1;j++){
            if(m%j!=0){
                if(j-i>len){
                    len=j-i;
                    start=i;
                }
                break;
            }else{
                m/=j;
            }
        }
    }
    if(0==len){
        cout<<"1"<<endl<<n;
    }else{
        cout<<len<<endl;
        for(long long i=start;i<start+len;i++){
            cout<<i;
            if(i!=start+len-1) cout<<"*";
        }
    }
    return 0;
}

