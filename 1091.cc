#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct node{
    int x,y,z;
}Node;
int m,n,l,t;
int pixel[1287][129][61];
bool used[1287][129][61];
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
    if(x<0||x>=m||y<0||y>=n||z<0||z>=l) return false;
    if(used[x][y][z]==1||pixel[x][y][z]==0) return false;
    return true;
}
int bfs(int x,int y,int z){
    queue<node> q;
    Node.x=x;Node.y=y;Node.z=z;
    q.push(Node);
    used[x][y][z]=true;
    int count=0;
    while(!q.empty()){
        node top=q.front();
        q.pop();
        count++;
        for(int i=0;i<6;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            int newz=top.z+Z[i];
            if(judge(newx,newy,newz)){
                Node.x=newx;Node.y=newy;Node.z=newz;
                q.push(Node);
                used[newx][newy][newz]=true;
            }
        }
    }
    if(count>=t) return count;
    else return 0;
}
int main()
{
    cin>>m>>n>>l>>t;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                scanf("%d",&pixel[j][k][i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(pixel[j][k][i]==1&&used[j][k][i]==false){
                    ans+=bfs(j,k,i);
                }
            }
        }
    }
    printf("%d\n",ans);
    

    return 0;
}

