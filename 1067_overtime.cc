#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main()
{
    int n,ans=0;
    map<int,int> m;
    cin>>n;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        m.emplace(tmp,i);
    }
    while(1){
        if(m[0]==0){
            auto i=m.begin();
            for(;i!=m.end();++i){
                if(i->first!=i->second){
                    int tmp=i->second;
                    i->second=m[0];
                    m[0]=tmp;
                    ans++;
                    break;
                }
            }
            if(i==m.end()) {
                cout<<ans;
                return 0;
            }
        }else{
            int p0=m[0],p1=m[m[0]];
            m[0]=p1;m[p0]=p0;
            ans++;
        }
    }
    return 0;
}

