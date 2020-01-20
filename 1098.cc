//不比较原序列和目标序列，否则给出俩序列一致时会导致答案错误
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
void down_adjust(vector<int> &arr,int low,int high){
    int i=low,j=(low+1)*2-1;
    while(j<high){
        if(j+1<high&&arr[j+1]>arr[j]) j++;
        if(arr[j]>arr[i]){
            swap(arr[i],arr[j]);
            i=j;
            j=(i+1)*2-1;
        }else break;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> ori(n),after(n);
    for(int i=0;i<n;i++){
        scanf("%d",&ori[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&after[i]);
    }
    int flag=-1,ins;
        vector<int> tmp=ori;
        for(int i=1;i<n;i++){
            if(i!=1&&tmp==after) flag=2;
            sort(tmp.begin(),tmp.begin()+i+1);
            if(flag==2){
                cout<<"Insertion Sort"<<endl;
            for(int i=0;i<n;i++){
                cout<<tmp[i];
                if(i!=n-1) cout<<" ";
            }
                return 0;
            }
        }    
        for(int i=n/2-1;i>=0;i--){
            down_adjust(ori,i,n);
        }
        for(int i=0;i<n;i++){
            int f=1;
            if(ori==after) f=2;
            swap(ori[0],ori[n-1-i]);
            down_adjust(ori,0,n-i-1);
            if(2==f){
                cout<<"Heap Sort"<<endl;
                break;
            }
        }
    for(int i=0;i<n;i++){
            cout<<ori[i];
            if(i!=n-1) cout<<" ";
    }
    return 0;
}

