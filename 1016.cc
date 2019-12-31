//一天24小时，别犯傻，oj一次通过
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct custom{
    int time;
    string origin_time;
    int flag;//0表示呼叫，1表示挂断
};
int rate[24];
bool cmp(custom a,custom b){
    return a.time<b.time;
}
int time_talk(int a,int b){
    return b-a;
}
float fee_talk(int a,int b){
    int sum=0;
    while(a<b){
        sum=sum+rate[(a/60)%24];
        a++;
    }
    return ((float)sum)/100;
}
int main()
{
    for(int i=0;i<24;++i){
        scanf("%d",&rate[i]);
    }
    int n,month;
    scanf("%d",&n);
    map<string,vector<custom>> name;
    for(int i=0;i<n;++i){
        string t1,t2;
        int t3,t4,t5,t6;
        cin>>t1;
        scanf("%d:%d:%d:%d",&t3,&t4,&t5,&t6);
        cin>>t2;
        custom tmp;
        tmp.origin_time="";
        if(t4<10) tmp.origin_time.append("0");
        tmp.origin_time.append(to_string(t4));
        tmp.origin_time.append(":");
        if(t5<10) tmp.origin_time.append("0");
        tmp.origin_time.append(to_string(t5));
        tmp.origin_time.append(":");
        if(t6<10) tmp.origin_time.append("0");
        tmp.origin_time.append(to_string(t6));
        tmp.time=t4*24*60+t5*60+t6;
        tmp.flag=((t2=="on-line")?0:1);
        name[t1].push_back(tmp);
        month=t3;
    }
    int c=0;
    for(auto i=name.begin();i!=name.end();++i){
        float sum=0,count=0;
        sort(i->second.begin(),i->second.end(),cmp);
        for(auto j=((decltype(i->second.size()))0);j<i->second.size();j++){
            if(j==0&&i->second[j].flag==1){continue;}
            else if(i->second[j].flag==0){continue;}
            else if(i->second[j].flag){
                if(i->second[j-1].flag==0){
                    if(0==count) {
                        if(c!=0)cout<<endl;
                        cout<<(i->first)<<" ";
                        printf("%02d",month);
                        cout<<endl;
                        count++;
                        c++;
                    }
                    float tmpf;
                    tmpf=fee_talk(i->second[j-1].time,i->second[j].time);
                    cout<<i->second[j-1].origin_time<<" "<<i->second[j].origin_time<<" "
                        <<time_talk(i->second[j-1].time,i->second[j].time)<<" $";
                    printf("%.2f",tmpf);
                    cout<<endl;
                    sum+=tmpf;

            }
        }
    }
        if(sum>0){
            printf("Total amount: $%.2f",sum);
        }

    }
    cout<<endl;
    return 0;
}

