//通过比较前i个元素是否递增，以及后n-i和元素是够与未排序前的顺序相同判断插入或者归并
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void InsertSort(vector<int> &past,int i){
    int tmp=past[i];
    int j=i-1;
    while(j>=0&&tmp<past[j]){
        past[j+1]=past[j];
        --j;
    }
    past[j+1]=tmp;
}
int main()
{
    int num;
    vector<int> origin,past;
    cin>>num;
    for(int i=0;i<num;++i){
        int tmp;
        cin>>tmp;
        origin.push_back(tmp);
    }
    for(int i=0;i<num;++i){
        int tmp;
        cin>>tmp;
        past.push_back(tmp);
    }
    int h=1;
    while(h<num){
        if(past[h]>=past[h-1]){
            h++;
        }else{
            break;
        }
    }
    int flag=0;
    for(int i=h;i<num;++i){ //这里得出的h其实不一定是已经插入排序好的个数，歪打正着
        if(past[i]!=origin[i]){
            flag=1;
            break;
        }
    }
    if(0==flag){
        InsertSort(past,h);
        cout<<"Insertion Sort"<<endl;
        for(int i=0;i<num-1;++i){
            cout<<past[i]<<" ";
        }
        cout<<past[num-1];
    }
    if(1==flag){
        cout<<"Merge Sort"<<endl;
        int step=1;
        while(flag){
            flag=0;
            for(int i=0;i<num;++i){
                if(past[i]!=origin[i]){
                    flag=1;
                }
            }
            step*=2;
            for(int i=0;i<num;i+=step){
                sort(origin.begin()+i,origin.begin()+min(num,i+step));
            }
        }
        for(int i=0;i<num-1;++i){
            cout<<origin[i]<<" ";
        }
        cout<<origin[num-1];
    }
    return 0;
}
