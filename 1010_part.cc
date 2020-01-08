#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
long long deci(string a,int n){
    long long tmp=0;
    for(int i=0;i<a.size();++i){
        tmp+=a[i]*pow(n,a.size()-i-1);
    }
    return tmp;
}
int main()
{
    string t1,t2;
    int t3,t4;
    cin>>t1>>t2>>t3>>t4;
    for(int i=0;i<t1.length();++i){
        if(t1[i]>='0'&&t1[i]<='9'){
            t1[i]-='0';
        }else{
            t1[i]=t1[i]-'a'+10;
        }
    }
    for(int i=0;i<t2.length();++i){
        if(t2[i]>='0'&&t2[i]<='9'){
            t2[i]-='0';
        }else{
            t2[i]=t2[i]-'a'+10;
        }
    }
    if(2==t3) swap(t1,t2);
    long long a=deci(t1,t4);
    int j=2,k=36;
    while(j<=k){
        int mid=(j+k)/2;
        long long tt2=deci(t2,mid);
        if(a==tt2){
            cout<<mid;
            return 0;
        }else if(a<tt2){
            k=mid-1;
        }else if(a>tt2){
            j=mid+1;
        }
    }
    cout<<"Impossible";
    return 0;
}

