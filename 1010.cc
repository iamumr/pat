//注意细节，用longlong就全用，别为了一点空间，导致强制类型转换错误
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
long long to_10(string a,long long radix){
    long long sum=0;
    for(int i=0;i<a.size();++i){
        int tmp=isdigit(a[i])?a[i]-'0':a[i]-'a'+10;
        sum+=tmp*pow(radix,a.size()-i-1);
    }
    return sum;
}
long long find_radix(string a,long long b){
    char low=*max_element(a.begin(),a.end());
    long long l=isdigit(low)?low-'0':low-'a'+10;
    l++;
    long long r=max(l,b+1);
    while(l<=r){
        long long m=(l+r)/2;
        long long t=to_10(a,m);
        if(b==t){return m;}
        else if(b<t||t<0){r=m-1;}
        else if(b>t){l=m+1;}
    }
    return -1;
}
int main(){
    string n1,n2;
    int tag;
    long long radix,ans;
    cin>>n1>>n2>>tag>>radix;
    ans=(tag==1)?find_radix(n2,to_10(n1,radix)):find_radix(n1,to_10(n2,radix));
    if(ans!=-1) cout<<ans;
    else cout<<"Impossible";
}
