#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int dp[1001][1001];
int main()
{
    string a;
    getline(cin,a);
    int ans=1;//默认值要为1，因为最小也是1，除非没有输入
    for(int i=0;i<a.size();i++){
        dp[i][i]=1;
        if(i<a.size()-1&&a[i]==a[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    for(int L=3;L<=a.size();L++){
        for(int i=0;i+L-1<a.size();i++){
            if(a[i]==a[i+L-1]&&dp[i+1][i+L-2]==1){
                dp[i][i+L-1]=1;
                ans=L;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

