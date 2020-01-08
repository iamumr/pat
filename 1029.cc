//用scanf和printf读入输出，否则最后一个测试点超时
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    long n,tmp;
    scanf("%ld",&n);
    vector<long> m;
    for(long i=0;i<n;i++){
        scanf("%ld",&tmp);
        m.push_back(tmp);
    }
    cin>>n;
    for(long i=0;i<n;i++){
        scanf("%ld",&tmp);
        m.push_back(tmp);
    }
    sort(m.begin(),m.end());
    printf("%ld",m[(m.size()-1)/2]);
    
    return 0;

}

