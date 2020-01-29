#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> ori;
int n,m,flag=0;
vector<int> path;
void dfs(int root,int sum){
    if(sum+ori[root]==m&&flag==0){
        flag++;
        path.push_back(ori[root]);
        for(int i=0;i<path.size();i++){
            if(i!=0) printf(" %d",path[i]);
            else printf("%d",path[i]);
        }
        return;
    }else if(sum+ori[root]>m){
        return;
    }else{
        path.push_back(ori[root]);
        dfs(root+1,sum+ori[root]);
        path.pop_back();
        dfs(root+1,sum);
    }

    
}
int main()
{
    scanf("%d%d",&n,&m);
    ori.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&ori[i]);
    }
    sort(ori.begin(),ori.end());
    dfs(0,0);
    if(flag==0) printf("No Solution");
    return 0;
}

