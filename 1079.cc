#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct node{
    double price,data;
    vector<int> custumor;
}Node[100001];
double ans=0;
double p,r;
void dfs(int root){
    if(Node[root].data>0){
        ans+=Node[root].data*Node[root].price;
        return;
    }
    if(Node[root].custumor.size()>0){
        for(int i=0;i<Node[root].custumor.size();i++){
            Node[Node[root].custumor[i]].price=Node[root].price*(1+r/100);
            dfs(Node[root].custumor[i]);
        }
    }
}
int main()
{
    int n;
    cin>>n>>p>>r;
    Node[0].price=p;
    for(int i=0;i<n;i++){
        int tmp,tmp1;
        cin>>tmp;
        if(0==tmp){
            cin>>Node[i].data;
        }else{
            for(int j=0;j<tmp;j++){
                cin>>tmp1;
                Node[i].custumor.push_back(tmp1);
            }
        }
    }
    dfs(0);
    printf("%.1lf",ans);
    return 0;
}

