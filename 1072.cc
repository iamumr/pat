//注意住房序号是从1开始的，给的参考输出貌似是四舍五入，直接舍去依旧正确
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int maxn=1020;
const int MAX=1<<20;
int n,m,k,ds;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
int getid(string a){
    if(a[0]=='G')return n+stoi(a.substr(1));
    else return stoi(a);
}
void dijkstera(int root){
    fill(d,d+1020,MAX);
    fill(vis,vis+maxn,false);
    d[root]=0;
    for(int i=0;i<n+m;i++){
        int u=-1,MIN=MAX;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(-1==u) return;
        vis[u]=true;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false&&G[u][j]!=0&&d[u]+G[u][j]<d[j]){
                d[j]=d[u]+G[u][j];
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    for(int i=0;i<k;i++){
        string a,b;
        int c;
        cin>>a>>b>>c;
        int aa=getid(a);
        int bb=getid(b);
        G[aa][bb]=c;
        G[bb][aa]=c;
    }
    int mindis=0,ansid=-1;
    double avg=MAX;
    for(int i=0;i<m;i++){
        dijkstera(n+i+1);
        int tmpdis=MAX;
        double tmpavg=0;
        for(int j=1;j<=n;j++){//找加油站距离最近住户距离
            if(d[j]>ds){
                tmpdis=-1;
                break;
            }
            if(d[j]<tmpdis) tmpdis=d[j];
            tmpavg+=d[j];
        }
        if(-1==tmpdis) continue;
        if(tmpdis>mindis){
            ansid=i+1;
            mindis=tmpdis;
            avg=tmpavg/n;
        }else if(tmpdis==mindis){
            if(tmpavg/n<avg){
                ansid=i+1;
                avg=tmpavg/n;
            }
        }
    }
    if(-1==ansid) cout<<"No Solution";
    else{
        cout<<"G"<<ansid<<endl;
        printf("%.1f %.1f",(double)mindis,avg);
    }
    return 0;
}

