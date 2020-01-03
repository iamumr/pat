#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    map<int,int> num;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        if(num.find(tmp)!=num.end()){
            num[tmp]++;
        }else{
            num.emplace(tmp,1);
        }
    }
    for(auto i=num.begin();i!=num.end();++i){
        i->second--;
        if(num.find(m-i->first)!=num.end()&&num[m-i->first]>0){
            cout<<i->first<<" "<<m-i->first;
            return 0;
        }
    }
    cout<<"No Solution";
    return 0;
}

