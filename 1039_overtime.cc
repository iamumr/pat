//时长压线，有时能过，有时不能过
//本题使用map会超时，可以使用unordered_map,底层原理分别是红黑树和
//hash，后者速度更快
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<string,vector<int>> st_co;
    for(int i=0;i<k;i++){
        int c,num;
        string tmp;
        cin>>c>>num;
        for(int j=0;j<num;j++){
            cin>>tmp;
            if(st_co.find(tmp)==st_co.end()){
                vector<int> tt;
                tt.push_back(c);
                st_co.emplace(tmp,tt);
            }else{
                st_co[tmp].push_back(c);
            }
        }
    }
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        sort(st_co[tmp].begin(),st_co[tmp].end());
        cout<<tmp<<" "<<st_co[tmp].size();
        for(int j=0;j<st_co[tmp].size();j++){
            cout<<" "<<st_co[tmp][j];
        }
        cout<<endl;
    }
    return 0;
}

