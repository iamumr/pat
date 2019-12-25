#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    string name;
    string id;
    int grade;
};
int main()
{
    student man,female;
    man.grade=100;female.grade=0;
    man.name="NULL";female.name="NULL";
    int n;
    string name,id;
    char gender;
    int grade;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>name>>gender>>id>>grade;
        if(gender=='M'){
            if(grade<=man.grade){
                man.name=name;
                man.id=id;
                man.grade=grade;
            }
        }else{
            if(grade>=female.grade){
                female.name=name;
                female.id=id;
                female.grade=grade;
            }
        }
    }
    if(female.name!="NULL"){
        cout<<female.name<<" "<<female.id<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    if(man.name!="NULL"){
        cout<<man.name<<" "<<man.id<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    if(female.name!="NULL"&&man.name!="NULL"){
        cout<<female.grade-man.grade;
    }else{
        cout<<"NA";
    }

    return 0;
}

