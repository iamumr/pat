#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct applicant{
    int ge,gi;
    int flag,id;
    vector<int> prefer;
};
struct school{
    vector<int> admission;
};
int cmp(applicant a,applicant b){
    if((a.ge+b.gi)!=(a.ge+b.gi)){
        return (a.ge+a.gi)>(b.ge+b.gi);
    }else{
        return a.ge>b.ge;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>quota;
    vector<applicant> app;
    vector<vector<int>> sc;
    for(int i=0;i<m;++i){
        int tmp;
        cin>>tmp;
        quota.push_back(tmp);
        vector<int> t;
        sc.push_back(t);
    }
    for(int i=0;i<n;i++){
        applicant tmp;
        tmp.id=i;
        tmp.flag=0;
        cin>>tmp.ge>>tmp.gi;
        for(int j=0;j<k;++j){
            int t;
            cin>>t;
            tmp.prefer.push_back(t);
        }
        app.push_back(tmp);
    }
    sort(app.begin(),app.end(),cmp);
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            if(quota[app[i].prefer[j]]>0){
                quota[app[i].prefer[j]]--;
                sc[app[i].prefer[j]].push_back(app[i].id);
                break;
            }else{
                if(app[i].ge==app[sc[app[i].prefer[j]].back()].ge&&app[i].gi==app[sc[app[i].prefer[j]].back()].gi){
                    sc[app[i].prefer[j]].push_back(app[i].id);
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;++i){
        sort(sc[i].begin(),sc[i].end(),less<int>());
        for(int j=0;i<sc[i].size();++j){
            cout<<sc[i][j];
            if(j!=sc[i].size()-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}

