#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int nc,np,tmp;
    vector<int> ncc,npp;
    cin>>nc;
    for(int i=0;i<nc;++i){
        cin>>tmp;
        ncc.push_back(tmp);
    }
    cin>>np;
    for(int i=0;i<np;++i){
        cin>>tmp;
        npp.push_back(tmp);
    }
    sort(ncc.begin(),ncc.end(),greater<int>());
    sort(npp.begin(),npp.end(),greater<int>());
    int sum=0;
    for(int i=0;i<nc;++i){
        if(ncc[i]>0&&npp[i]>0){
            sum+=(ncc[i]*npp[i]);
        }else{
            break;
        }
    }
    for(int i=nc-1,j=np-1;i>=0&&j>=0;i--,j--){
        if(ncc[i]<0&&npp[j]<0){
            sum+=(ncc[i]*npp[j]);//别眼瞎啊，j写成i也是没谁了。
        }else{
            break;
        }
    }
    cout<<sum;
    return 0;
}

