//不一定真的交换左右子树，层次遍历先入队右子树即可，中序遍历变成右根左即可
//也可以用遍历的方法交换所有的左右子树
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct node{
    int data;
    int lchild;
    int rchild;
}Node[10];
int c=0;
void level(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(c!=0) printf(" %d",tmp);
        else{
            printf("%d",tmp);
            c++;
        }
        if(Node[tmp].rchild!=-1) q.push(Node[tmp].rchild);
        if(Node[tmp].lchild!=-1) q.push(Node[tmp].lchild);
    }
}
void in_order(int root){
    if(Node[root].rchild!=-1) in_order(Node[root].rchild);
    if(c==0) {
        printf("%d",root);
        c++;
    }
    else{
        printf(" %d",root);
    }
    if(Node[root].lchild!=-1) in_order(Node[root].lchild);
}
int n;
int main()
{
    bool father[10];//没有父节点的为root
    //fill_n(father,father+10,0);
    scanf("%d",&n);
    for(int i=0;i<n;i++) father[i]=false;//记得初始化，或者写在全局变量，自动初始化
    for(int i=0;i<n;i++){
        char tmpl,tmpr;
        cin>>tmpl>>tmpr;
        if(tmpl>='0'&&tmpl<='9'){
            Node[i].lchild=tmpl-'0';
            father[tmpl-'0']=1;
        }else{
            Node[i].lchild=-1;
        }
        if(tmpr>='0'&&tmpr<='9'){
            Node[i].rchild=tmpr-'0';
            father[tmpr-'0']=1;
        }else{
            Node[i].rchild=-1;
        }
    }
    int root=0;
    for(;root<n;root++){
        if(father[root]==false) break;
    }
//    cout<<root;
    level(root);
    printf("\n");
    c=0;
    in_order(root);
    return 0;
}

