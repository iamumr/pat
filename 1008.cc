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
    int ans=0,pre=0;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        if(tmp-pre>0) ans+=(tmp-pre)*6;
        else ans+=(tmp-pre)*(-4);
        pre=tmp;
        ans+=5;
    }
    cout<<ans;
    return 0;
}

