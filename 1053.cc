#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct node{
    int w;
    vector<int> children;
}Node[101];
int cmp(int a,int b){
    return Node[a].w>Node[b].w;
}
int n,m,s;
vector<int> ans;
void dfs(int root,int sum){
    if(Node[root].children.size()==0){
        if(sum+Node[root].w==s){
            for(int i=0;i<ans.size();i++){
                printf("%d ",ans[i]);
            }
            printf("%d\n",Node[root].w);
        }
        return;
    }
    sort(Node[root].children.begin(),Node[root].children.end(),cmp);
    for(int i=0;i<Node[root].children.size();i++){
        ans.push_back(Node[root].w);
        dfs(Node[root].children[i],sum+Node[root].w);
        ans.pop_back();
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        cin>>Node[i].w;
    }
    for(int i=0;i<m;i++){
        int p,num;
        cin>>p>>num;
        for(int j=0;j<num;j++){
            int tmp;
            cin>>tmp;
            Node[p].children.push_back(tmp);
        }
    }
    dfs(0,0);
    return 0;
}

