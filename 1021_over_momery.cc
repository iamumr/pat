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
void dfs(int root){
    vis[root]=true;
    for(int i=0;i<G[root].size();i++){
        if(vis[G[root][i]]==false) dfs(G[root][i]);
    }
}
void dfs1(int root,int depth){
    vis[root]=true;
    if(depth>maxdep){
        ans.clear();
        maxdep=depth;
        ans.push_back(root);
    }else if(depth==maxdep){
        ans.push_back(root);
    }
    for(int i=0;i<G[root].size();i++){
        if(vis[G[root][i]]==false) dfs1(G[root][i],depth+1);
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
            dfs(i);
            count++;
        }
    }
    if(1!=count){
        cout<<"Error: "<<count<<" components";
    }else{
        for(int i=1;i<=n;i++){
            fill_n(vis.begin(),n+1,false);
            dfs1(i,1);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i==0) cout<<ans[i]<<endl;
            else if(ans[i]!=ans[i-1]) cout<<ans[i]<<endl;
        }
    }
    return 0;
}

