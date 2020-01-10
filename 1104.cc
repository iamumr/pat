//找规律，妹子数组出现(i-1)*(n-i)次，i为该数字的序号
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
    double ans=0,tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        ans+=tmp*(i+1)*(n-i);
    }
    printf("%.2f",ans);
    return 0;
}

