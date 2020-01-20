#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<vector<int>> G;
vector<bool> vis;
vector<int> ans;
int maxdep=0;
void dfs(int root,int depth){
    vis[root]=true;
    if(depth>maxdep){
        ans.clear();
        maxdep=depth;
        ans.push_back(root);
    }else if(depth==maxdep){
        ans.push_back(root);
    }
    for(int i=0;i<G[root].size();i++){
        if(vis[G[root][i]]==false) dfs(G[root][i],depth+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    G.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i,1);
            count++;
        }
    }
    if(1!=count){
        cout<<"Error: "<<count<<" components";
    }else{
        fill(vis.begin(),vis.end(),false);
        auto tmp=ans;
        dfs(ans[0],1);
        for(int i=0;i<tmp.size();i++){
            ans.push_back(tmp[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i==0) cout<<ans[i]<<endl;
            else if(ans[i]!=ans[i-1]) cout<<ans[i]<<endl;
        }
    }
    return 0;
}

