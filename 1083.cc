#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    string name,id;
    int grade;
};
int cmp(student a,student b){
    return a.grade>b.grade;
}
int main()
{
    vector<student>st;
    int n;
    cin>>n;
    for(int i =0;i<n;++i){
        student tmp;
        cin>>tmp.name>>tmp.id>>tmp.grade;
        st.push_back(tmp);
    }
    int a,b;
    cin>>a>>b;
    sort(st.begin(),st.end(),cmp);
    int count=0;
    for(int i=0;i<st.size();++i){
        if(st[i].grade>=a&&st[i].grade<=b){
            cout<<st[i].name<<" "<<st[i].id<<endl;
            count++;
        }
    }
    if(0==count) cout<<"NONE";
    return 0;
}

