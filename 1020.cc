#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=35;
int post[maxn],in[maxn],n;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* create(int pl,int pr,int il,int ir){
    if(pl>pr) return NULL;
    node* root=new node;
    root->data=post[pr];
    int k;
    for(k=il;k<=ir;k++){
        if(in[k]==post[pr]){
            break;
        }
    }
    root->lchild=create(pl,pl+k-il-1,il,k-1);
    root->rchild=create(pl+k-il,pr-1,k+1,ir);
    return root;
}
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp=q.front();
        q.pop();
        printf("%d",tmp->data);
        if(tmp->lchild!=NULL) q.push(tmp->lchild);
        if(tmp->rchild!=NULL) q.push(tmp->rchild);
        if(!q.empty()) printf(" ");
        
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root=create(0,n-1,0,n-1);
    bfs(root);
    return 0;
}

