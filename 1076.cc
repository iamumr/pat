//dfs存在不同路线的坑，bfs较容易实现
//限时应该是300ms，而不是3000ms，否则不应该超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n,k;
vector<int> G[1001];
vector<bool> vis;
struct node{
    int depth,id;
}Node;
int bfs(int root){
    queue<node> q;
    Node.id=root;
    Node.depth=0;
    int ans=0;
    vis[root]=true;
    q.push(Node);
    while(!q.empty()){
        auto tmp=q.front();
        q.pop();
//        if(tmp.depth<=k&&tmp.depth>0){
            //cout<<tmp.id<<" "<<tmp.depth<<endl;
//            if(vis[tmp.id]==false)ans++;
//            vis[tmp.id]=true;
//        } 
        if(tmp.depth+1<=k){
        for(int i=0;i<G[tmp.id].size();i++){
            Node.id=G[tmp.id][i];
            Node.depth=tmp.depth+1;
            if(vis[G[tmp.id][i]]==false){
                q.push(Node);
                vis[Node.id]=true;
                ans++;
            } 
        }
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    vis.resize(n+1);
    for(int i=1;i<=n;i++){
        int num,tmp;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&tmp);
            G[tmp].push_back(i);
        }
    }
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        fill(vis.begin(),vis.end(),false);
        int tmp;
        scanf("%d",&tmp);
        int ans=0;
        ans=bfs(tmp);
        cout<<ans<<endl;
    }
    return 0;
}

