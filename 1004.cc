#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int n,m;
vector<int> children[100];
vector<int> ans(100);
int g=0;
void dfs(int root,int depth){
    if(children[root].size()==0){
        ans[depth]++;
        if(depth>g) g=depth;
//        cout<<g<<endl;
        return;
    }
    for(int i=0;i<children[root].size();i++){
//        cout<<depth<<endl;
        dfs(children[root][i],depth+1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int p,pn,tmp;
        cin>>p>>pn;
        for(int j=0;j<pn;j++){
            cin>>tmp;
            children[p].push_back(tmp);
        }
    }
    //cout<<children[0].size()<<endl;
    dfs(1,1);
    for(int i=1;i<=g;i++){
        cout<<ans[i];
        if(i!=g) cout<<" ";
    }
    
    return 0;
}

