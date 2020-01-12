//存在多余的0，例如0002，指数存在负数0.0001
//存在各种形式的0，例如000.00
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int change(string &a,int n){
    int t=0;
    while(a.length()>=0&&a[0]=='0'){
        a.erase(0,1);
    }
    if(a.length()==0) return 200;
    if(a[0]=='.'){
        a.erase(0,1);
        t=0;
        while(a.length()>=0&&a[0]=='0'){
            a.erase(0,1);
            t--;
        }
        if(a.length()==0) return 200;
    }else{
        t=a.find('.');
        if(t==string::npos) t=a.size();
        else a.erase(find(a.begin(),a.end(),'.'));

    }
    if(a.length()<n){
        a.append(n-a.length(),'0');
    }
    if(a.length()>n){
        a.erase(n);
    }
    return t;
}
void cmp(string a,int b,string c,int d,int n){
    if(200==b&&200==d){
        string tmp(n,'0');
        cout<<"YES 0."<<tmp<<"*10^0";
    }else if(b==d&&a==c){
            cout<<"YES 0."<<a<<"*10^"<<b;
    }else{
            cout<<"NO 0."<<a<<"*10^"<<b<<" 0."<<c<<"*10^"<<d;
    }

}
int main(){
    string a,b;
    int n;
    cin>>n>>a>>b;
    int d1=change(a,n);
    int d2=change(b,n);
    cmp(a,d1,b,d2,n);
}
