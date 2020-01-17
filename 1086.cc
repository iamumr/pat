#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int pre[31],in[32];
struct node{
    int data;
    node* lchild;
    node* rchild;
}Node;
node* create(int pl,int pr,int il,int ir){
    if(pl>pr) return NULL;
    node* root=new node;
    root->data=pre[pl];
    int k=il;
    for(;k<=ir;k++){
        if(in[k]==pre[pl]) break;
    }
    root->lchild=create(pl+1,pl+k-il,il,k-1);
    root->rchild=create(pl+k-il+1,pr,k+1,ir);
    return root;
}
int n=0;
void post_order(node* root){
    if(root->lchild!=NULL) post_order(root->lchild);
    if(root->rchild!=NULL) post_order(root->rchild);
    if(n!=0) printf(" %d",root->data);
    else{
        printf("%d",root->data);
        n++;
    }
}
int main()
{
    int n;
    string tmp;
    cin>>n;
    getchar();
    stack<int> s;
    int k=0,j=0;
    for(int i=0;i<n*2;i++){
        getline(cin,tmp);
        int t;
        if(tmp.size()>3) {
            t=stoi(tmp.substr(5));
            pre[k++]=t;
            s.push(t);
        }else{
            t=s.top();
            s.pop();
            in[j++]=t;
        }
    }
/*    for(int i=0;i<n;i++){
        printf("%d",pre[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d",in[i]);
    }
    return 0; */
    node* root=create(0,n-1,0,n-1);
    post_order(root);
    return 0;
}

