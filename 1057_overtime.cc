#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    vector<int> path;
    int n;
    scanf("%d",&n);
    getchar();
    set<int> s;
    for(int i=0;i<n;i++){
        string tmp;
        getline(cin,tmp);
        if(tmp[1]=='u'){
            path.push_back(stoi(tmp.substr(5)));
        }else if(tmp[1]=='o'){
            if(path.size()!=0){
                cout<<path.back()<<endl;
                path.pop_back();
            }
            else cout<<"Invalid"<<endl;
        }else{
            if(path.size()==0) cout<<"Invalid"<<endl;
            else{
                auto t=path;
                sort(t.begin(),t.end());
                cout<<t[(path.size()+1)/2-1]<<endl;}
        }
    }
    return 0;
}

