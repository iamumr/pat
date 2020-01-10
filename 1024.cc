#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
bool isPalindromic(string a){
    int i=0,j=a.size()-1;
    while(i<j){
        if(a[i]!=a[j]) return false;
        i++;j--;
    }
    return true;
}
string add(string a){
    int i=0,j=a.size()-1;
    string t;
    int jw=0;
    while(j>=0){
        int now=a[i]+a[j]-'0'-'0'+jw;
        jw=0;
        if(now>9){
            now-=10;
            jw=1;
        }
        t.insert(0,1,now+'0');
        if(0==j&&1==jw) t.insert(0,1,'1');
        j--;i++;
    }
    return t;
}
int main()
{
    string n;
    int k,t=0;
    cin>>n>>k;
    while(t<k){
        if(isPalindromic(n)){
            cout<<n<<endl<<t;
            return 0;
        }
        else{
            n=add(n);
            t++;
        }
    }
    cout<<n<<endl<<k;
    return 0;
}

