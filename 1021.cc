#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<vector<int>> G;
vector<bool> vis,is_root;
vector<int> ans;
int maxdep=0;
vector<int> father;
int find_father(int v){
    int z=v;
    while(father[v]!=v){
        v=father[v];
    }
    while(z!=father[z]){
        int a=father[z];
        father[z]=v;
        z=a;
    }
    return v;
}
void Union(int a,int b){
    int fa=find_father(a);
    int fb=find_father(b);
    father[fb]=fa;
}
void dfs1(int root,int depth){
    is_root[root]=true;
    if(depth>maxdep){
        ans.clear();
        maxdep=depth;
        ans.push_back(root);
    }else if(depth==maxdep){
        ans.push_back(root);
    }
    for(int i=0;i<G[root].size();i++){
        if(is_root[G[root][i]]==false) dfs1(G[root][i],depth+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    G.resize(n+1);
    father.resize(n+1);
    is_root.resize(n+1);
    for(int i=0;i<=n;i++) father[i]=i;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        is_root[find_father(i)]=true;
    }
    for(int i=1;i<=n;i++){
        if(is_root[i]) count++;
    }
    if(1!=count){
        cout<<"Error: "<<count<<" components";
    }else{
        for(int i=1;i<=n;i++){
            fill_n(is_root.begin(),n+1,false);
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

