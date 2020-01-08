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
    cin>>n;
    vector<unsigned int> m(n),leftmax(n),rightmin(n);
    vector<unsigned int> ans;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    leftmax[0]=0;
    rightmin[n-1]=1000000001;
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],m[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightmin[i]=min(rightmin[i+1],m[i+1]);
    }
    for(int i=0;i<n;i++){
        if(m[i]<rightmin[i]&&m[i]>leftmax[i]) ans.push_back(m[i]);
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1) cout<<" ";
    }
    cout<<endl;//第二行必须有换行，否则有一个测试点过不去，题干没说
    return 0;
}

