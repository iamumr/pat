//特判0；边读边删除已阅读字节最简单。
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
    string nn[4]={"Qian","","Shi","Bai"};
    string num;
    cin>>num;
    if('-'==num[0]){
        cout<<"Fu ";
        num.erase(0,1);
    }
    if(stoi(num)==0) cout<<"ling";
    if(9==num.length()){
        if(num[0]!='0')cout<<n[num[0]-'0']<<" Yi";
        num.erase(0,1);
        if(stoi(num)!=0) cout<<" ";
    }
    int i=0;
    int flag=(stoi(num)>=10000)?1:0;
    while(num.length()>0){
        if(num[i]!='0'){
            cout<<n[num[i]-'0'];
            if(nn[(num.length()-i)%4]!="")cout<<" "<<nn[(num.length()-i)%4];
            if(num.length()==5&&flag) cout<<" Wan";
            num.erase(0,1);
            if(num.length()>0&&stoi(num)!=0) cout<<" ";
        }else{
            if(num.length()==5&&flag) cout<<"Wan";
            num.erase(0,1);
            if(num.length()==4&&flag&&stoi(num)!=0) cout<<" ";
            if(num.length()!=0&&num[i]!='0') cout<<"ling ";
        }
    } 
    return 0;
}

