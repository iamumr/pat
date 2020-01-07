//策略：找比目前加油站价格更低的第一个加油站前往，没有比当前价格低的
//加满油后，找行驶里程内价格最低的加油站
//把终点设为油价为0，距离为d的一个加油站即可
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct gas{
    float p,d;
};
int main()
{
    float c,d,davy;
    int n;
    cin>>c>>d>>davy>>n;
    vector<gas> g;
    gas tmp;
    tmp.p=0;
    tmp.d=d;
    g.push_back(tmp);
    for(int i=0;i<n;++i){
        cin>>tmp.p>>tmp.d;
        g.push_back(tmp);
    }
    sort(g.begin(),g.end(),[](gas a,gas b){return a.d<b.d;});
    if(g[0].d!=0){
        cout<<"The maximum travel distance = 0.00";
        return 0;
    }
    float sum=0,price=0.0;
    float nowg=0;
    int now=0;
    while(now<n){
        float minp=g[now+1].p;
        int mint=now+1,flag=0;
        for(int i=now+1;i<=n&&g[i].d-g[now].d<=c*davy;++i){
            if(g[i].p<g[now].p){
                sum=g[i].d;
                price=price+g[now].p*((g[i].d-g[now].d)/davy-nowg);
                //nowg=(g[i].d-g[now].d)/davy;
                nowg=0;
                now=i;
                flag=1;
                break;
            }else{
                if(minp>g[i].p){
                    minp=g[i].p;
                    mint=i;
                }
                flag=2;
            }
        }
        if(2==flag){
            price=price+g[now].p*(c-nowg);
            nowg=c-(g[mint].d-g[now].d)/davy;
            now=mint;
            sum=g[now].p;
        }
        if(0==flag){
            sum+=(c*davy);
            printf("The maximum travel distance = %.2f",sum);
            return 0;
        } 
    }
        printf("%.2f",price);
    return 0;
}

