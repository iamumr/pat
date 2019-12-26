//b会超过10，不能用单个字节，直接输出数字
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;
    vector<int> a;
    string c[2]={"No","Yes"};
    do{
        a.push_back(n%b);
        n/=b;
    }while(n!=0);
    int i=0,j=a.size()-1;
    int flag=1;
    while(i<=j){
        if(a[i]!=a[j]&&i<j){
            flag =0;
            break;
        }
        i++;
        j--;
    }
    cout<<c[flag]<<endl;
    //cout<<a;
    for(auto i=a.rbegin();i!=a.rend();++i){
        if(i!=a.rbegin())cout<<" ";
        cout<<*i;
    }
    return 0;
}

