#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct node{
    int data,height;
    node* lchild;
    node* rchild;
};
int get_height(node* root){
    if(root==NULL) return 0;
    else return root->height;
}
void update_height(node* root){
    root->height=max(get_height(root->lchild),get_height(root->rchild))+1;
}
void L(node* &root){//左旋
    auto tmp=root->rchild;
    root->rchild=tmp->lchild;
    tmp->lchild=root;
    update_height(root);
    update_height(tmp);
    root=tmp;
}
void R(node* &root){
    auto tmp=root->lchild;
    root->lchild=tmp->rchild;
    tmp->rchild=root;
    update_height(root);
    update_height(tmp);
    root=tmp;
}
node* new_node(int data){
    node* tmp=new node;
    tmp->data=data;
    tmp->height=1;
    tmp->lchild=tmp->rchild=NULL;
    return tmp;
}
int balance(node* root){
    return get_height(root->lchild)-get_height(root->rchild);
}
void create(node* &root,int data){
    if(root==NULL){
        root=new_node(data);
        return;
    }
    if(data<root->data){
        create(root->lchild,data);
        update_height(root);
        if(balance(root)==2){
            if(balance(root->lchild)==1){
                R(root);
            }else if(balance(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        create(root->rchild,data);
        update_height(root);
        if(balance(root)==-2){
            if(balance(root->rchild)==-1){
                L(root);
            }else if(balance(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    node* root=NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        create(root,data);
    }
    cout<<root->data;
    return 0;
}

