#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a[55];
    int b[55];
    for(int i=1;i<=54;++i){
        cin>>b[i];
    }
    for(int i=1;i<=13;++i){
        a[i]='S'+to_string(i);
        a[i+13]='H'+to_string(i);
        a[i+26]='C'+to_string(i);
        a[i+39]='D'+to_string(i);
    }
    string re[55];
    a[53]="J1";a[54]="J2";
    for(int i=0;i<n;++i){
        for(int j=1;j<=54;++j){
            re[b[j]]=a[j];
        }
        for(int k=1;k<=54;++k){
            a[k]=re[k];
        }
    }
    for(int i=1;i<=54;++i){
        if(i==54){cout<<a[i];break;}
        cout<<a[i]<<" ";
    }
    return 0;
}
