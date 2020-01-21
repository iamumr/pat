#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int G[501][501];
int n,m,c1,c2,persons[501];
bool vis[501];
int minp=1<<20;
vector<int> t;
void dfs(int root,int path,int team){
    if(root==c2&&path<minp){
        minp=path;
        t.clear();
        t.push_back(team);
        return;
    }else if(root==c2&&path==minp){
        t.push_back(team);
        return;
    }
    for(int i=0;i<n;i++){
        if(G[root][i]>0){
            int tmp=G[root][i];
            G[root][i]=0;
            G[i][root]=0;
            dfs(i,path+tmp,team+persons[i]);
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
    dfs(c1,0,persons[c1]);
    sort(t.begin(),t.end(),greater<int>());
    cout<<t.size()<<" "<<t[0]<<endl;
    return 0;
}

