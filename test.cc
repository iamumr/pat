//要考虑全为0，最终结果为0的情况
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
    for(int i=0;i<m.size();++i){
        if(0==i){
            //cout<<stoi(m[i]);
            if(stoi(m[i])==0) {
                m.erase(m.begin());
                i--;
            }else{
                cout<<stoi(m[i]);
            }
        }else{
            cout<<m[i];
        }
    }
    if(m.size()==0) cout<<"0";
    return 0;
}

