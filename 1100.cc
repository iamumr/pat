#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
string num[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string nn[12]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> mar_e;
void etom(int n){
/*    if(n==0){
        cout<<"tret"<<endl;
        return;
    }
    while(n>=13){ //一定要是大于等于，细节啊
        int t=n/13;
        n=n%13;
        cout<<nn[t-1];
        if(n!=0) cout<<" ";
    }
    if(n!=0) cout<<num[n];
    cout<<endl; */
    if(n/13) cout<<nn[n/13-1];
    if((n/13)&&(n%13)) cout<<" ";
    if(n%13||0==n) cout<<num[n%13];
    cout<<endl;
}
void mtoe(string n){
   int t=n.find(' ');
   if(t==string::npos){
        cout<<mar_e[n]<<endl;
   }else{
       cout<<mar_e[n.substr(0,t)]+mar_e[n.substr(t+1)]<<endl;
   }
}
int main()
{
    for(int i=0;i<13;i++){
        mar_e.emplace(num[i],i);
    }
    for(int i=1;i<=12;i++){
        mar_e.emplace(nn[i-1],i*13);
    }
/*    for(int i=0;i<169;i++){
        etom(i);
    }
    return 0; */
    int n;
    cin>>n;
    getchar();
    string t;
    for(int i=0;i<n;i++){
        getline(cin,t);
        if(t[0]>='0'&&t[0]<='9'){
            etom(stoi(t));
        }else{
            mtoe(t);
        }
    }
    return 0;
}

