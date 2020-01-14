#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
vector<int> fac,ans,tmp;
int n,k,p,maxFac=0;
void DFS(int index,int nowk,int sum,int facsum){
    if(nowk>k||sum>>n) return;
    if(sum==n&&nowk==k){
        if(facsum>maxFac){
            ans=tmp;
            maxFac=facsum;
        }
        return;
    }
    if(index>=1){
        tmp.push_back(index);
        DFS(index,nowk+1,sum+fac[index],facsum+index);
        tmp.pop_back();
        DFS(index-1,nowk,sum,facsum);
    }
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;;i++){
        int t=pow(i,p);
        if(t>n) break;
        fac.push_back(t);
    }
    DFS(fac.size()-1,0,0,0);
    if(ans.size()==0) printf("Impossible");
    else{
        printf("%d =",n);
        for(int i=0;i<ans.size();i++){
            printf(" %d^%d",ans[i],p);
            if(i!=ans.size()-1) printf(" +");
        }
    }
    return 0;
}

