//少用相似的变量，以免低级错误不好检查
//完全二叉树，左孩子序号等于父节点序号的二倍（起始位1），用序号判断是否越界
//中序遍历为递增排序，用中序遍历构件二叉树
//也可以使用静态链表，数组模拟
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int ori[1001];
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int n,fi=0;;
void in_order(node* root,int num){
    if(num*2<=n){
        root->lchild=new node;
        in_order(root->lchild,num*2);
    }
    root->data=ori[fi++];
    if(num*2+1<=n){
        root->rchild=new node;
        in_order(root->rchild,num*2+1);
    } 

}
void level_order(node* root){
    int count=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(t->lchild!=NULL) q.push(t->lchild);
        if(t->rchild!=NULL) q.push(t->rchild);
        if(count!=0) printf(" %d",t->data);
        else printf("%d",t->data);
        count++;

    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ori[i]);
    }
    sort(ori,ori+n);
    node* root=new node;
    in_order(root,1);
    //cout<<root->data<<endl;
    level_order(root);
    return 0;
}

