#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int l=a.size();
    int n1,n2;
    for(n2=3;n2<l;++n2){
        n1=l-n2+2;
        if((n1/2)<=n2&&(n1%2)==0) break;
    }
    n1=n1/2;
    for(int i=0;i<n1-1;++i){
        cout<<a[i];
        for(int j=0;j<n2-2;++j){
            cout<<" ";
        }
        cout<<a[l-1-i]<<endl;
    }
    for(int i=n1-1;i<n1+n2-1;++i){
        cout<<a[i];
    }
    return 0;
}

