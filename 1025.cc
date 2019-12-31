#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    string  reg_number;//用字符串，测试点3应该是前面有多个0，导致输出错误
    int final_rank;
    int location_number;
    int local_rank;
    int grade;
};
int cmp(student a,student b){
    if(a.grade!=b.grade){
        return a.grade>b.grade;
    }else{
        return a.reg_number<b.reg_number;
    }
}
int cmp1(student a,student b){
    if(a.location_number!=b.location_number){
        return a.location_number<b.location_number;
    }else{
        return a.grade>b.grade;
    }
}
int main()
{
    vector<student> stu;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            student tmp;
            cin>>tmp.reg_number>>tmp.grade;
            tmp.location_number=i+1;
            stu.push_back(tmp);
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    stu[0].final_rank=1;
    for(auto i=(decltype(stu.size()))1;i<stu.size();++i){
        if(stu[i].grade==stu[i-1].grade){
            stu[i].final_rank=stu[i-1].final_rank;
        }else{
            stu[i].final_rank=(i+1);
        }
    }
    sort(stu.begin(),stu.end(),cmp1);
    int pre=0;//指示前面有几个不同考点的考生
    stu[0].local_rank=1;
    for(auto i=(decltype(stu.size()))1;i<stu.size();++i){
        if(stu[i-1].location_number==stu[i].location_number){
            if(stu[i-1].grade==stu[i].grade){
                stu[i].local_rank=stu[i-1].local_rank;
            }else{
                stu[i].local_rank=i+1-pre;
            }
        }else{
            stu[i].local_rank=1;
            pre=i;
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    cout<<stu.size()<<endl;
    for(auto i=(decltype(stu.size()))0;i<stu.size();++i){
        cout<<stu[i].reg_number<<" "<<stu[i].final_rank<<" "<<stu[i].location_number
            <<" "<<stu[i].local_rank;
        if(i!=stu.size()-1) cout<<endl;
    }
    
    return 0;
}

