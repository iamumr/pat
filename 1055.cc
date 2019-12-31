//因为至多输出100个人，所以要对数据进行预处理，否则1测试点会超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct person{
    string name;
    int age;
    int worth;
};
int cmp(person a,person b){
    if(a.worth!=b.worth){
        return a.worth>b.worth;
    }else{
        if(a.age!=b.age){
            return a.age<b.age;
        }else{
            return a.name<b.name;
        }
    }
}
int age[201]={0};
int main()
{
    int n,q;
    vector<person>p,p1;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        person tmp;
        cin>>tmp.name>>tmp.age>>tmp.worth;
        p.push_back(tmp);
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<n;++i){
        if(age[p[i].age]<100){
            age[p[i].age]++;
            p1.push_back(p[i]);
        }
    }
    int a,b,c;
    for(int i=0;i<q;++i){
        cin>>a>>b>>c;
        cout<<"Case #"<<i+1<<":"<<endl;
        int count=0;
        for(int j=0;j<p1.size()&&count<a;++j){
            if(p1[j].age>=b&&p1[j].age<=c){
                cout<<p1[j].name<<" "<<p1[j].age<<" "<<p1[j].worth<<endl;
                count++;
            }
        }
        if(0==count) cout<<"None"<<endl;
    }
    
    return 0;
}

