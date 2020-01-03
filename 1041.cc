#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> num;
    map<int,int> oc;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
        if(oc.find(tmp)!=oc.end()){
            oc[tmp]++;
        }else{
            oc.emplace(tmp,1);
        }
    }
    for(int i=0;i<n;i++){
        if(oc[num[i]]==1){
            cout<<num[i];
            return 0;
        }
    }
    cout<<"None";
    return 0;
}

