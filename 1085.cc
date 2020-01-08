#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int n,p;
    vector<int> sequ;
    cin>>n>>p;
    int tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        sequ.push_back(tmp);
    }
    sort(sequ.begin(),sequ.end());
    int result=1;
    for(auto i=sequ.begin();i!=sequ.end();++i){
        int rtmp=upper_bound(i+1,sequ.end(),(long long)*i*p)-i;
        result=max(result,rtmp);
    }
    cout<<result;

    return 0;
}

