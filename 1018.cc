//使用dijkstra寻找单点最短路径
//使用dfs反向恢复路径，并计算送出和运回的自行车数量，比较得出最终路径
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int cmax,n,sp,m;
int c[501],G[501][501];
int vis[501],d[501],bikes[501];
vector<int> path[501];
const int MAX=1<<20;
void dijkstra(int root){
    fill(d,d+501,MAX);
    d[root]=0;
    for(int i=0;i<=n;i++){
        int u=-1,MIN=MAX;
        for(int j=0;j<=n;j++){
            if(d[j]<MIN&&vis[j]==false){
                u=j;
                MIN=d[j];
            }
        }
        if(-1==u) return;
        vis[u]=true;
        for(int j=0;j<=n;j++){
            if(vis[j]==false&&G[u][j]!=0){
                if(d[u]+G[u][j]<d[j]){
                    d[j]=d[u]+G[u][j];
                    path[j].clear();
                    path[j].push_back(u);
                }else if(d[u]+G[u][j]==d[j]){
                    path[j].push_back(u);
                }
            }
        }
    }
}
vector<int> ans,tmp;
int minneed=MAX,minremain=MAX;
void dfs(int root){
    if(root==0){
        tmp.push_back(root);
        int need=0,remain=0;
        for(int i=tmp.size()-1;i>=0;i--){
            int id=tmp[i];
            if(c[id]>0){
                remain+=c[id];
            } else{
                if(remain>-c[id]){
                    remain+=c[id];
                }else{
                    need=-c[id]-remain+need;
                    remain=0;
                }
            }
        }
        if(need<minneed){
            minneed=need;
            minremain=remain;
            ans=tmp;
        }else if(need==minneed&&remain<minremain){
            minneed=need;
            minremain=remain;
            ans=tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(root);
    for(int i=0;i<path[root].size();i++){
        dfs(path[root][i]);
    }
    tmp.pop_back();
}
int main()
{
    scanf("%d%d%d%d",&cmax,&n,&sp,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        c[i]-=cmax/2;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a][b]=c;
        G[b][a]=c;
    }
    dijkstra(0);
    dfs(sp);
    cout<<minneed<<" ";
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
        if(i!=0) cout<<"->";
    }
    cout<<" "<<minremain;
    return 0;
}

