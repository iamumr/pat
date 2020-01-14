#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int f,n;
    cin>>f>>n;
    int data[100001],nex[100001];
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cin>>data[tmp]>>nex[tmp];
    }
    set<int> used;
    vector<int> ans1,ans2;
    while(f!=-1){
        if(used.find(abs(data[f]))==used.end()){
            used.emplace(abs(data[f]));
            ans1.push_back(f);
        }else{
            ans2.push_back(f);
        }
        f=nex[f];
    }
    for(int i=0;i<ans1.size();i++){
        if(i!=ans1.size()-1){
            printf("%05d %d %05d\n",ans1[i],data[ans1[i]],ans1[i+1]);
        }else{
            printf("%05d %d -1\n",ans1[i],data[ans1[i]]);
        }
    }
    for(int i=0;i<ans2.size();i++){
        if(i!=ans2.size()-1){
            printf("%05d %d %05d\n",ans2[i],data[ans2[i]],ans2[i+1]);
        }else{
            printf("%05d %d -1\n",ans2[i],data[ans2[i]]);
        }
    }
    return 0;
}

