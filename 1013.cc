#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> G[1001];
int del;
bool vis[1001];
void dfs(int root){
    vis[root]=true;
    if(G[root].size()==0||root==del) return;
    for(int i=0;i<G[root].size();i++){
        if(vis[G[root][i]]==false) dfs(G[root][i]);
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        G[t1].push_back(t2);
        G[t2].push_back(t1);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&del);
        int count=0;
        fill_n(vis,1001,false);
        for(int j=1;j<=n;j++){
            if(j!=del&&vis[j]==false){
                dfs(j);
                count++;
            }
        }
        cout<<count-1<<endl;
    }
    return 0;
}

