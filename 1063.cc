#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
void simrate(unordered_set<int> a,unordered_set<int> b){
    int nc=0,nt=0;
    for(auto i:a){
        if(b.find(i)!=b.end()){
            nc++;
        }
    }
    nt=a.size()+b.size()-nc;
    printf("%.1f%%\n",nc*100.0/nt);
}
int main()
{
    int n;
    scanf("%d",&n);
    unordered_set<int> m[n];
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        for(int j=0;j<tmp;j++){
            int t;
            cin>>t;
            m[i].emplace(t);
        }
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        simrate(m[a-1],m[b-1]);
    }
    return 0;
}

