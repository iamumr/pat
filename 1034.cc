//图的遍历，为了防止多算通话时间，加了主叫时间，累加时累加各自主叫时间
//比较时使用通话时间比较，否则会错误
//也可以把邻接矩阵的边权值定义为通话时长，但是要注意有环时不要多算时间
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int weight[2001],G[2001][2001],singlew[2001];
map<string,int> idtoint;
map<int,string> inttoid;
int persons=0;
vector<bool> vis;
void dfs(int root,int &head,int &total,int &p){
    vis[root]=true;
    p++;
    total+=singlew[root];
    if(weight[root]>weight[head]){
        head=root;
    }
    for(int i=0;i<persons;i++){
        if(G[root][i]!=0&&vis[i]==false) dfs(i,head,total,p);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        string a,b;int t;
        cin>>a>>b>>t;
        if(idtoint.find(a)==idtoint.end()){
            inttoid[persons]=a;
            idtoint[a]=persons++;
        } 
        if(idtoint.find(b)==idtoint.end()){
            inttoid[persons]=b;
            idtoint[b]=persons++;
        } 
        G[idtoint[a]][idtoint[b]]=1;
        G[idtoint[b]][idtoint[a]]=1;
        weight[idtoint[a]]+=t;
        weight[idtoint[b]]+=t;
        singlew[idtoint[a]]+=t;
    }
    vis.resize(persons);
    map<string,int> ans;
    for(int i=0;i<persons;i++){
        if(vis[i]==false) {
            int a=i,b=0,c=0;
            dfs(i,a,b,c);
            if(c>2&&b>k){
                ans[inttoid[a]]=c;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    return 0;
}

