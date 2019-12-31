//同分同名次是关键，否则3、4测试点报错
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    string name;
    int grade[4];
    int rank[4];
};
int now=0;
bool cmp(student a,student b){
    return a.grade[now]>b.grade[now];
}
int main()
{
    vector<student> st;
    int n,m;
    string b[4]={"A","C","M","E"};
    student tmp;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>tmp.name>>tmp.grade[1]>>tmp.grade[2]>>tmp.grade[3];
        tmp.grade[0]=(tmp.grade[1]+tmp.grade[2]+tmp.grade[3])/3;
        st.push_back(tmp);
    }
    for(;now<4;now++){
        sort(st.begin(),st.end(),cmp);
        for(auto j=(decltype(st.size()))0;j<st.size();++j){
            if(j!=0&&st[j].grade[now]==st[j-1].grade[now]){
                st[j].rank[now]=st[j-1].rank[now];
            }else{
                st[j].rank[now]=j+1;
            }
        }
    }
    map<string,string> r;
    for(auto i=(decltype(st.size()))0;i<st.size();++i){
        string t3="";
        int t4=0;
        for(int j=0;j<4;++j){
            if(st[i].rank[j]<st[i].rank[t4]){
                t4=j;
            }
        }
        t3.append(to_string(st[i].rank[t4]));
        t3.append(" ");
        t3.append(b[t4]);
        r.emplace(st[i].name,t3);
    }
    for(int i=0;i<m;++i){
        string t2;
        cin>>t2;
        if(r.find(t2)!=r.end()){
            cout<<r[t2];
        }else{
            cout<<"N/A";
        }
        if(i!=m-1) cout<<endl;
    }
    return 0;
}

