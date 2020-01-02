#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct car{
    string plate_number;
    int time;
    int status;
};
struct thecar{
    string id;
    int all_time;
    vector<int> time;//储存停车时间段
};
int cmp(car a,car b){
    if(a.plate_number!=b.plate_number){
        return a.plate_number<b.plate_number;
    }else{
        return a.time<b.time;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<car> c;
    vector<thecar> cc;
    for(int i=0;i<n;i++){
        car tmp;
        int t1,t2,t3;
        string t4;
        cin>>tmp.plate_number;
        scanf("%d:%d:%d",&t1,&t2,&t3);
        tmp.time=t1*60*60+t2*60+t3;
        cin>>t4;
        tmp.status=(t4=="in")?0:1;
        c.push_back(tmp);
    }
    sort(c.begin(),c.end(),cmp); 
    for(int i=1;i<c.size();++i){
        if(c[i].plate_number==c[i-1].plate_number){
            if(c[i].status==1){
                if(c[i-1].status==0){
                    if(cc.size()!=0&&cc.rbegin()->id==c[i].plate_number){
                        cc.rbegin()->all_time+=(c[i].time-c[i-1].time);
                        cc.rbegin()->time.push_back(c[i-1].time);
                        cc.rbegin()->time.push_back(c[i].time);
                        
                    }else{
                        thecar t;
                        t.id=c[i].plate_number;
                        t.all_time=c[i].time-c[i-1].time;
                        t.time.push_back(c[i-1].time);
                        t.time.push_back(c[i].time);
                        cc.push_back(t);
                    }
                }
            }
        }
    }
    for(int i=0;i<k;++i){
        int t1,t2,t3;
        int ans=0;
        scanf("%d:%d:%d",&t1,&t2,&t3);
        t1=t1*60*60+t2*60+t3;
        for(int j=0;j<cc.size();++j){
            for(int k=0;k<cc[j].time.size();k=k+2){
                if(t1>=cc[j].time[k]&&t1<cc[j].time[k+1]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    int maxtime=-1;
    vector<thecar> max_time_car;
    for(int i=0;i<cc.size();++i){
        if(cc[i].all_time>maxtime){
            maxtime=cc[i].all_time;
            max_time_car.clear();
            max_time_car.push_back(cc[i]);
        }else if(cc[i].all_time==maxtime){
            max_time_car.push_back(cc[i]);
        }
    }
    for(int i=0;i<max_time_car.size();++i){
        cout<<max_time_car[i].id<<" ";
    }
    printf("%02d:%02d:%02d",maxtime/3600,(maxtime%3600)/60,maxtime%60);
    return 0;
}

