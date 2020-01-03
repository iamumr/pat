#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string good,bad;
    cin>>good>>bad;
    unordered_set<char> goo;
    for(decltype(bad.size()) i=0;i<bad.size();++i){
        goo.emplace(bad[i]);
    }
    string result;
    //cout<<result.size()<<endl;
    for(auto t:good){
        if(goo.find(t)==goo.end()){
            //cout<<result.find(t)<<" "<<result.size()<<endl;
            if(result.size()==0||result.find(toupper(t))==string::npos){
                result.push_back(toupper(t));
            }
        }
    }
    cout<<result;
    return 0;
}

