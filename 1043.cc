//递归复制粘贴的时候别忘了改内部的递归函数
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
vector<int> pre_order,post_order;
void preo(node* root){
    if(root==NULL) return;
    pre_order.push_back(root->data);
    preo(root->lchild);
    preo(root->rchild);
}
void posto(node* root){
    if(root==NULL) return;
    posto(root->lchild);
    posto(root->rchild);
    post_order.push_back(root->data);
}
void preo1(node* root){
    if(root==NULL) return;
    pre_order.push_back(root->data);
    preo1(root->rchild);
    preo1(root->lchild);
}
void posto1(node* root){
    if(root==NULL) return;
    posto1(root->rchild);
    posto1(root->lchild);
    post_order.push_back(root->data);
}
int main()
{
    node* root=new node;
    int n;
    scanf("%d",&n);
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    root->data=pre[0];
    auto p=root;
    for(int i=1;i<n;i++){
        p=root;
        while(1){
            if(pre[i]<p->data){
                if(p->lchild==NULL){
                    p->lchild=new node;
                    p->lchild->data=pre[i];
                    break;
                }else{
                    p=p->lchild;
                }
            }else{
                if(p->rchild==NULL){
                    p->rchild=new node;
                    p->rchild->data=pre[i];
                    break;
                }else{
                    p=p->rchild;
                }
            }
        }
    }
//    cout<<root->rchild->lchild->data;
//    return 0;
    if(pre[1]<pre[0]){
        preo(root);
        posto(root);
        if(pre==pre_order){ 
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<post_order[i];
                if(i!=n-1) cout<<" ";
            }
        }else{
            cout<<"NO";
        }
    }else{
        preo1(root);
        posto1(root);
        if(pre==pre_order){ 
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<post_order[i];
                if(i!=n-1) cout<<" ";
            }
        }else{
            cout<<"NO";
        }
        
    }
    return 0;
}

