#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
struct line{
    int time;
    int status;
};
int cmp(line a,line b){
    return a.time<b.time;
}
int main()
{
    unordered_map<string,vector<line>>car;
    map<string,int> all_time;
    int n,k;
    scanf("%d %d",n,k);
    for(int i=0;i<n;++i){
        string tmp,t5;
        int t1,t2,t3;
        line t4;
        cin>>tmp;
        scanf("%d:%d:%d",&t1,&t2,&t3);
        cin>>t5;
        t4.time=t1*3600+t2*60+t3;
        t4.status=(t5=="in")?0:1;
        if(car.find(tmp)!=car.end()){
            car.find(tmp)->second.push_back(t4);
        }else{
            vector<line> t6;
            t6.push_back(t4);
            car.emplace(tmp,t6);
            all_time.emplace(tmp,0);
        }
    }
    for(auto i=car.begin();i!=car.end();++i){
        sort(i->second.begin(),i->second.end(),cmp);
        int j=0;
        while(j<i->second.size()){
            if(j==0){
                if(i->second[0].status==1) (i->second).erase(i->second.begin());
                else {
                    j++;
                    continue;
                }
            }
            if(i->second[j].status==1&&i->second[j-1].status==0){
                int now=all_time[i->first];
                all_time.emplace(i->first,now+i->second[j].time-i->second[j-1].time);
                j++;    
            }else if(i->second[j].status==0&&i->second[j-1].status==0){
                i->second.erase(i->second.begin()+j-1);
            }else if(i->second[j].status==1&&i->second[j-1].status==1){
                i->second.erase(i->second.begin()+j);
            }
        }
    }
    for(int i=0;i<k;++i){
        int t1,t2,t3;
        scanf("%d:%d:%d",&t1,&t2,&t3);
        t1=t1*3600+t2*60+t3;
        
    }
    
    return 0;
}

