//使用scanf不会超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    map<int,int> col;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            scanf("%d",&t);
            auto tt=col.find(t);
            if(tt!=col.end()) {
                tt->second++;
            }
            else col.emplace(t,1);

        }
    }
    for(auto i:col){
        if(i.second>m*n/2){
            cout<<i.first;
            return 0;
        }
    }
    return 0;
}

