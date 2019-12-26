#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    string a;
    string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cin>>a;
    int sum=0;
    for(int i=0;i<a.size();++i){
        sum+=(a[i]-'0');
    }
    string s=to_string(sum);
    for(int i=0;i<s.size();++i){
        if(i!=0)cout<<" ";
        cout<<num[s[i]-'0'];
    }
    return 0;
}

