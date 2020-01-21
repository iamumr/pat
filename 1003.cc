#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int G[501][501];
int n,m,c1,c2,persons[501];
int d[501],w[501],num[501];
bool vis[501];
int minp=1<<20;
vector<int> t;
void dijkatra(int root){
    fill(d,d+501,minp);
    d[root]=0;
    w[root]=persons[root];
    num[root]=1;
    for(int i=0;i<n;i++){
        int u=-1,MIN=1<<20;
        for(int j=0;j<n;j++){//找路径最短未访问节点
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&G[u][j]!=0&&d[u]+G[u][j]<d[j]){
                d[j]=d[u]+G[u][j];
                w[j]=w[u]+persons[j];
                num[j]=num[u];
            }else if(vis[j]==false&&G[u][j]!=0&&d[u]+G[u][j]==d[j]){
                if(w[u]+persons[j]>w[j]){
                    w[j]=w[u]+persons[j];
                }
                num[j]+=num[u];
        }
    }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++){
        scanf("%d",&persons[i]);
    }
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        G[t1][t2]=t3;
        G[t2][t1]=t3;
    }
    dijkatra(c1);
    cout<<num[c2]<<" "<<w[c2]<<endl;
    return 0;
}

