//特判f=-1，不存在f!=-1,但是没有对应初试节点的情况
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,f;
    cin>>n>>f;
    int data[100001],nex[100001];
    fill_n(nex,100001,-2);
    map<int,int> all;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cin>>data[tmp]>>nex[tmp];
    }
    if(f==-1){
        printf("0 -1");
        return 0;
    }
    while(f!=-1){
        all.emplace(data[f],f);
        f=nex[f];
    }
    printf("%d %05d\n",(int)all.size(),all.begin()->second);
    int sum=0;
    for(auto i=all.begin();i!=all.end();i++){
        sum++;
        if(sum!=all.size()){
            printf("%05d %d ",i->second,i->first);
            i++;
            printf("%05d\n",i->second);
            i--;
        } 
        else printf("%05d %d -1\n",i->second,i->first);
    }
    return 0;
}

