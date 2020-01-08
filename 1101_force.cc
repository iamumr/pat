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
    vector<int> m(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    for(int i=0;i<n;i++){
        int t,p;
        if(i!=n) t=*min_element(m.begin()+i+1,m.end());
        if(i!=0) p=*max_element(m.begin(),m.begin()+i);
        if(i==0&&t>m[i]) ans.push_back(m[i]);
        else if(i==n-1&&p<m[i]) ans.push_back(m[i]);
        else if(i!=0&&i!=n-1&&p<m[i]&&t>m[i]) ans.push_back(m[i]);
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1) cout<<" ";
    }
    return 0;
}

