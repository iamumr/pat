//这里的平方探测法只考虑正向，没注意审题耽误很多时间，公式为(n+p*p)/m,n为要插入的数，m为容量
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
bool isPrime(int n){
    if(n<=1) return false;
    int t=sqrt(1.0*n);
    for(int i=2;i<=t;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int m,n,realn;
    cin>>m>>n;
    realn=m;
    set<int> used;
    while(isPrime(realn)==false){
        realn++;
    }
    int num=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(used.find(tmp%realn)!=used.end()){
            int p=1,flag=0;
            while((tmp+p*p)%realn>=0&&(tmp+p*p)%realn<realn){
                if(used.find((tmp+p*p)%realn)==used.end()){
                    used.emplace((tmp+p*p)%realn);
                    cout<<" "<<(tmp+p*p)%realn;
                    flag=1;
                    break;
                }
                p++;
            }
            if(flag==0)cout<<" -";
        }else{
            if(num!=0) cout<<" ";
            cout<<tmp%realn;
            used.emplace(tmp%realn);
        }
        num++;
    }
    return 0;
}
