//关键变量，该注释注释，别弄混
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int np,ng;
    cin>>np>>ng;
    vector<int> mice(np);
    vector<int> mice_rank(np);
    queue<int> q;
    for(int i=0;i<np;i++){
        cin>>mice[i];
    }
    for(int i=0;i<np;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    int temp=np,g;
    while(q.size()>1){
        g=(temp%ng)?temp/ng+1:temp/ng;
        for(int i=0;i<g;i++){
            int maxt=q.front();
            for(int j=0;j<ng;j++){
                if(i*ng+j>=temp) break;
                if(mice[q.front()]>mice[maxt]){
                    maxt=q.front();
                }
                mice_rank[q.front()]=g+1;
                q.pop();
            }
                q.push(maxt);
        }
        temp=g;
    }
    mice_rank[q.front()]=1;
    for(int i=0;i<np;i++){
        cout<<mice_rank[i];
        if(np-1!=i) cout<<" ";
    }
    return 0;
}

