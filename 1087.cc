#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX=1<<20;
int n,k;
int happiness[202],G[202][202];
string start_city;
map<string,int> nametoid;
map<int,string> idtoname;
vector<int> pre[202];
int d[202];
bool vis[202];
void dijkstera(int root){
    fill(d,d+202,MAX);
    d[root]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=MAX;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(-1==u) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&G[u][j]!=0&&d[u]+G[u][j]<d[j]){
                d[j]=d[u]+G[u][j];
                pre[j].clear();
                pre[j].push_back(u);
            }else if(vis[j]==false&&G[u][j]!=0&&d[u]+G[u][j]==d[j]){
                pre[j].push_back(u);
            }
        }
    }
}
int num=0,maxhappiness=0,avghap=0;
vector<int> path,anspath;
void dfs(int root){
    if(root==0){
        num++;
        path.push_back(root);
        int tmphap=0,tmpavg=0;
        for(int i=path.size()-1;i>=0;i--){
            tmphap+=happiness[path[i]];
            tmpavg+=happiness[path[i]];
        }
        tmpavg/=path.size()-1;
        if(tmphap>maxhappiness){
            anspath=path;
            maxhappiness=tmphap;
            avghap=tmpavg;
        }else if(tmphap==maxhappiness){
            if(tmpavg>avghap){
                anspath=path;
                avghap=tmpavg;
            }
        }
        path.pop_back();
        return;
    }
    path.push_back(root);
    for(int i=0;i<pre[root].size();i++){
        dfs(pre[root][i]);
    }
    path.pop_back();
}
int main()
{
    cin>>n>>k>>start_city;
    nametoid[start_city]=0;
    idtoname[0]=start_city;
    happiness[0]=0;
    for(int i=1;i<=n-1;i++){
        string a;
        int b;
        cin>>a>>b;
        nametoid[a]=i;
        idtoname[i]=a;
        happiness[i]=b;
    }
    for(int i=0;i<k;i++){
        string a,b;
        int c;
        cin>>a>>b>>c;
        G[nametoid[a]][nametoid[b]]=G[nametoid[b]][nametoid[a]]=c;
    }
    dijkstera(0);
    dfs(nametoid["ROM"]);
    cout<<num<<" "<<d[nametoid["ROM"]]<<" "<<maxhappiness<<" "<<avghap<<endl;
    for(int i=anspath.size()-1;i>=0;i--){
        cout<<idtoname[anspath[i]];
        if(i!=0) cout<<"->";
    }
    return 0;
}

