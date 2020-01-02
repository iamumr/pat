//按总分排序，逐一录取
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    int ge,gi,sum,id;
    int rank,prefer[5];
}st[40001];
struct school{
    int quota,admission,lastone;
    vector<int> id;
}sc[101];
int cmp(student a,student b){
    if(a.sum!=b.sum){
        return a.sum>b.sum;
    }else{
        return a.ge>b.ge;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        cin>>sc[i].quota;
        sc[i].admission=0;
        sc[i].lastone=-1;
    }
    for(int i=0;i<n;++i){
        cin>>st[i].ge>>st[i].gi;
        for(int j=0;j<k;++j){
            cin>>st[i].prefer[j];
        }
        st[i].sum=st[i].ge+st[i].gi;
        st[i].id=i;
    }
    sort(st,st+n,cmp);
    st[0].rank=1;
    for(int i=1;i<n;++i){
        if(st[i].sum!=st[i-1].sum){
            st[i].rank=i+1;
        }else{
            if(st[i].ge==st[i-1].ge) st[i].rank=st[i-1].rank;
            else st[i].rank=i+1;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            int t1=st[i].prefer[j];
            int t2=sc[t1].admission;
            if(t2<sc[t1].quota){
                sc[t1].admission++;
                sc[t1].lastone=i;
                sc[t1].id.push_back(st[i].id);
                break;
            }else{
                if(st[i].rank==st[sc[st[i].prefer[j]].lastone].rank){
                    sc[t1].admission++;
                    sc[t1].id.push_back(st[i].id);
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;++i){
        sort(sc[i].id.begin(),sc[i].id.end(),less<int>());
        for(int j=0;j<sc[i].id.size();++j){
            cout<<sc[i].id[j];
            if(j!=sc[i].admission-1)cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}

