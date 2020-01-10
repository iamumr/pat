//注意审题，是重新排列，并不是新数所有出现的数，原数里面有就行
//一定及得用0==i的形式，不然差错太耽误时间了
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
void dup(string &a){
    int jw=0;
    int i=a.size()-1;
    for(i;i>=0;i--){
        a[i]-='0';
        a[i]=a[i]*2+jw;
        jw=0;
        if(a[i]>9){
            a[i]-=10;
            jw=1;
        }
        a[i]+='0';
        if(0==i&&jw==1) a.insert(0,"1");
    }
}
int main()
{
    string s;
    cin>>s;
    int used[10]={0};
    for(int i=0;i<s.length();i++){
        used[s[i]-'0']++;
    }
    int now=s.length();
    dup(s);
    if(s.length()>now){
        cout<<"No"<<endl<<s;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(used[s[i]-'0']<1){
            cout<<"No"<<endl<<s;
            return 0;
        }else{
            used[s[i]-'0']--;
        }
    }
    cout<<"Yes"<<endl<<s;
    return 0;
}

