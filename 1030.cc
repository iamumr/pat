#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX=1<<20;
int n,m,s,d;
int G[501][501];
bool vis[501];
int cost[501][501],dis[501];
vector<int> pre[501];
void dijkstra(int root){
    fill(dis,dis+501,MAX);    
    dis[root]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=MAX;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(-1==u) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&G[u][j]!=0){
                if(dis[u]+G[u][j]<dis[j]){
                    pre[j].clear();
                    pre[j].push_back(u);
                    dis[j]=dis[u]+G[u][j];
                }else if(dis[u]+G[u][j]==dis[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}
vector<int> path,tmp;
int mincost=MAX,mindis=0;
void dfs(int root){
    if(root==s){
        tmp.push_back(root);
        int tmpcost=0;
        mindis=0;
        for(int i=tmp.size()-2;i>=0;i--){
            int a=tmp[i+1],b=tmp[i];
            tmpcost+=cost[a][b];
            mindis+=G[a][b];
        }
        if(tmpcost<mincost){
            path=tmp;
            mincost=tmpcost;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(root);
    for(int i=0;i<pre[root].size();i++){
        dfs(pre[root][i]);
    }
    tmp.pop_back();
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        G[a][b]=c;
        G[b][a]=c;
        cost[a][b]=d;
        cost[b][a]=d;
    }
    dijkstra(s);
    dfs(d);
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<mindis<<" "<<mincost;
    return 0;
}

