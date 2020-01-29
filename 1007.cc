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
    vector<int> ori(n);
    vector<int> sum(n);
    int flag=0;
    int tmp=0,MAX=-(1<<20),ansi=0,ansj=0;
    for(int i=0;i<n;i++){
        cin>>ori[i];
        tmp+=ori[i];
        sum[i]=tmp;
        if(ori[i]>=0) flag=1;
    }
    if(0==flag){
        cout<<"0 "<<ori[0]<<" "<<ori[n-1];
    }else{
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int t;
                if(i>0) t=sum[i-1];
                else t=0;
                if(sum[j]-t>MAX){
                    MAX=sum[j]-t;
                    ansi=i;
                    ansj=j;
                }
            }
        }
        cout<<MAX<<" "<<ori[ansi]<<" "<<ori[ansj];
    }
    
    return 0;
}

