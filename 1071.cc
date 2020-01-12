//学会用istringstream事半功倍
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    string a;
    map<string,int> num;
    getline(cin,a);
//    cout<<a<<endl;
    for(int i=0;i<a.length();i++){
        if(a[i]>='A'&&a[i]<='Z'){
            a[i]=a[i]-'A'+'a';
        }else if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')){
        }else{
            a[i]=' ';
        }
    }
//    cout<<a<<endl;
    istringstream record(a);
    while(record>>a){
        if(num.find(a)!=num.end()){
            num.find(a)->second++;
        }else{
            num[a]=1;
        }
    }
    int maxt=0;
    for(auto i:num){
        if(i.second>maxt){
            maxt=i.second;
            a=i.first;
        }
    }
    cout<<a<<" "<<maxt;
    return 0;
}

