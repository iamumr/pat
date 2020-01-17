#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> children[100];
int n,m;
vector<int> ans(100);
void dfs(int root,int depth){
    ans[depth]++;
    if(children[root].size()==0) return;
    for(int i=0;i<children[root].size();i++){
        dfs(children[root][i],depth+1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int id,num;
        cin>>id>>num;
        for(int j=0;j<num;j++){
            int tmp;
            cin>>tmp;
            children[id].push_back(tmp);
        }
    }
    dfs(1,1);
    int maxg=0,maxp=0;
    for(int i=1;i<=n;i++){
        if(ans[i]>maxp){
            maxp=ans[i];
            maxg=i;
        }
    }
    cout<<maxp<<" "<<maxg;
    return 0;
}

