//必须使用scanf和printf，否则最后一个测试点会超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include<cstring>
using namespace std;
struct person{
    int id;
    char name[10];
    int grade;
};
int cmp1(person a,person b){
    return a.id<b.id;
}
int cmp2(person a,person b){
    int s=strcmp(a.name,b.name);
    if(s!=0){
        return s<0;
    }else{
        return a.id<b.id;
    }
}
int cmp3(person a,person b){
    if(a.grade!=b.grade){
        return a.grade<b.grade;
    }else{
        return a.id<b.id;
    }
}
int main()
{
    int n,c;
    vector<person> p;
    char name[10];
    cin>>n>>c;
    for(int i=0;i<n;++i){
        person tmp;
        scanf("%d %s %d",&tmp.id,tmp.name,&tmp.grade);
        //cin>>tmp.id>>tmp.name>>tmp.grade;
        p.push_back(tmp);
    }
    if(1==c){sort(p.begin(),p.end(),cmp1);}
    else if(2==c){sort(p.begin(),p.end(),cmp2);}
    else if(3==c){sort(p.begin(),p.end(),cmp3);}
    for(int i=0;i<p.size();++i){
        printf("%06d %s %d\n",p[i].id,p[i].name,p[i].grade);
        //cout<<p[i].id<<" "<<p[i].name<<" "<<p[i].grade;
        //if(i!=p.size()-1) printf("\n");
    }
    return 0;
}
remove_all_extents
