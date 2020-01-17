#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n,ori[101];
struct node{
    int data,lchild,rchild;
}Node[101];
int fi=0;
void in_order(int root){
    if(Node[root].lchild!=-1) in_order(Node[root].lchild);
    Node[root].data=ori[fi++];
    if(Node[root].rchild!=-1) in_order(Node[root].rchild);
}
void level_order(int root){
    int count=0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(Node[tmp].lchild!=-1) q.push(Node[tmp].lchild);
        if(Node[tmp].rchild!=-1) q.push(Node[tmp].rchild);
        if(count!=0) printf(" %d",Node[tmp].data);
        else{printf("%d",Node[tmp].data);}
        count++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&Node[i].lchild,&Node[i].rchild);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&ori[i]);
    }
    sort(ori,ori+n);
    in_order(0);
    level_order(0);
    return 0;
}

