#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int d[100001];
    int sum=0,dis[100001];
    int need;
    int two[2];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>d[i+1];
        sum+=d[i+1];
        dis[i+1]=sum;
    }
    cin>>need;
    for(int i=0;i<need;++i){
        cin>>two[0]>>two[1];
        if(two[0]>two[1]){
            swap(two[0],two[1]);
        }
        int result=dis[two[1]-1]-dis[two[0]-1];
        int result2=sum-result;
        cout<<min(result,result2);
        if(i!=need-1) cout<<endl;
    }
    return 0;
}
