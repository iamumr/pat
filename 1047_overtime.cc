#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<string>> m(k);
    for(int i=0;i<n;i++){
        int num,tmp;
        string name;
        cin>>name>>num;
        for(int j=0;j<num;j++){
            cin>>tmp;
            m[tmp-1].push_back(name);
        }
    }
    for(int i=0;i<k;i++){
        cout<<i+1<<" "<<m[i].size()<<endl;
        sort(m[i].begin(),m[i].end());
        for(auto j:m[i]){
            cout<<j<<endl;
        }
    }
    return 0;
}

