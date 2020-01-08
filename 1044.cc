//也可以在读入数据时，计算前n个珠子的价值总和，然后时候二分法查找
//以下代码采用双指针遍历
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> d(n);
    for(int i=0;i<n;++i){
        cin>>d[i];
    }
    int min=1000000000;
    vector<int> mint;
    int j=0,flag=0;
    while(j<n){
        int k=j;
        int sum=d[j];
        while(k<n&&sum<m){
            k++;
            sum+=d[k];
        }
            if(sum==m){
                cout<<j+1<<"-"<<k+1<<endl;
                flag=1;
            } 
            else if(sum>m) {
                if(flag==0&&sum<min){
                    mint.clear();
                    min=sum;
                    mint.push_back(j+1);
                    mint.push_back(k+1);
                }else if(flag==0&&sum==min){
                    mint.push_back(j+1);
                    mint.push_back(k+1);
                }
            }else{break;}
            j++;
    }
    if(0==flag){
        for(int i=0;i<mint.size();i+=2){
            cout<<mint[i]<<"-"<<mint[i+1]<<endl;
        }
    }
    return 0;
}

