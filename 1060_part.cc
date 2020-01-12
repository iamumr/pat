#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int change(string &a,int n){
    while(1){
        if(a[0]==0) a.erase(0,1);
    }
    auto d=a.find('.');
    if(d==string::npos){
        d=a.size();
        a.insert(0,1,'.');
        if(a.size()>=n+1)a.erase(n+1);
        return d;
    }else{
        a.erase(find(a.begin(),a.end(),'.'));
        a.insert(0,1,'.');
        if(a.size()>=n+1)a.erase(n+1);
        return d;
    }
}
bool cmp(string a,int b,string c,int d){
    if(b!=d) return false;
    if(a!=c) return false;
    return true;
}
int main()
{
    int n;
    string a,b;
    cin>>n>>a>>b;
    int d1=change(a,n);
    int d2=change(b,n);
    if(cmp(a,d1,b,d2)){
        cout<<"YES"<<" 0"<<a<<"*10^"<<d1;
    }else{
        cout<<"NO"<<" 0"<<a<<"*10^"<<d1<<" 0"<<b<<"*10^"<<d2;
    }
    return 0;
}

