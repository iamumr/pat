//只有sum+fac[index]<=n的时候，进入下一层dfs，减少开销
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> fac,ans,tmp;
int n,k,p,maxFacSum=0;
void DFS(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
                ans = tmp;
                maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if (tempSum + fac[index] <= n) {
            tmp[tempK] = index;
            DFS(index, tempSum + fac[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    tmp.resize(k);
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

