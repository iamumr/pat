//此题各个查询参数没有重合，不需要区分，一个map搞定，否则需要多个map作为索引
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar();
    map<string,vector<string>> query;
    for(int i=0;i<n;i++){
        string id,tmp;
        cin>>id;
        getchar();
        for(int j=0;j<5;j++){
            getline(cin,tmp);
            if(2==j){
                istringstream record(tmp);
                while(record>>tmp){
                    if(query.find(tmp)!=query.end()){
                        query.find(tmp)->second.push_back(id);
                    }else{
                        vector<string> tt{id};
                        query[tmp]=tt;
                    }
                }
            }else{
                if(query.find(tmp)!=query.end()){
                    query.find(tmp)->second.push_back(id);
                }else{
                    vector<string> tt{id};
                    query[tmp]=tt;
                }
            }
        }
    }
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string tmp;
        getline(cin,tmp);
        cout<<tmp<<endl;
        tmp=tmp.substr(3);
        if(query.find(tmp)!=query.end()){
            sort(query.find(tmp)->second.begin(),query.find(tmp)->second.end());
            for(auto j:query.find(tmp)->second){
                cout<<j<<endl;
            }
        }else{cout<<"Not Found"<<endl;}
    }
    return 0;
}

