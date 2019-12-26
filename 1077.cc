#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    string a[2];
    cin>>n;
    getchar();
    getline(cin,a[0]);
//    cout<<a[0];
    for(int i=1;i<n;++i){
        getline(cin,a[1]);
        int j=a[0].length()-1,k=a[1].length()-1;
        while(j>=0&&k>=0&&a[0][j]==a[1][k]){
            j--;
            k--;
        }
        a[0].erase(0,j+1);
    }
    if(a[0].size()==0){
        cout<<"nai";
    }else{
        cout<<a[0];
    }
    return 0;
}

