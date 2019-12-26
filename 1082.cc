#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    string n[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string nn[5]={"","","Shi","Bai","Qian"};
    string num;
    cin>>num;
    if('-'==num[0]){
        cout<<"Fu ";
        num.erase(0,1);
    }
    if(9==num.length()){
        cout<<n[num[0]-'0']<<" Yi ";
        num.erase(0,1);
    }
    if(num.length()>4&&num.length()<=8){
        for(int i=0;i<num.length()-4;i++){
            if(num[i]!='0'){
                cout<<n[num[i]-'0']<<" ";
                if(nn[num.length()-4-i]!="")cout<<nn[num.length()-4-i]<<" ";
            }else{
                if(num[i+1]!='0') cout<<"ling ";
            }
        }
        if(stoi(num)>=10000)cout<<"Wan ";
        num.erase(0,num.length()-4);
    }
    
        for(int i=0;i<num.length();i++){
            if(num[i]!='0'){
                cout<<n[num[i]-'0'];
                if(i!=num.length()-1) cout<<" ";
                cout<<nn[num.length()-i];
                if(i!=num.length()-1) cout<<" ";
            }else{
                if((i+1)<num.length()-1&&num[i+1]!=0) cout<<"ling ";
            }
        }
    return 0;
}

