#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<int,int>like;
    vector<int> strip;
    int n,m,l;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d",&tmp);
        like[tmp]=i;
    }
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        int tmp;
        scanf("%d",&tmp);
        if(like.find(tmp)!=like.end()){
            strip.push_back(like[tmp]);
        }
    }
    int ans=-1;
    vector<int> dp(strip.size());
    for(int i=0;i<strip.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(strip[i]>=strip[j]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}

