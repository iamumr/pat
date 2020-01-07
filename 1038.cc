#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int cmp(string a,string b){
    return a+b<b+a;
}
int main()
{
    int n;
    cin>>n;
    vector<string> m(n);
    for(int i=0;i<n;++i){
        cin>>m[i];
    }
    sort(m.begin(),m.end(),cmp);
    for(int i=0;i<n;++i){
        if(0==i){
            cout<<stoi(m[i]);
        }else{
            cout<<m[i];
        }
    }
    return 0;
}

