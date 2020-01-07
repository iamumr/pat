#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct mooncakes{
    double n;
    double price;
    double oneprice;
};
int main()
{
    int n;
    double need;
    cin>>n>>need;
    mooncakes mooncake[1000];
    for(int i=0;i<n;++i){
        cin>>mooncake[i].n;
    }
    for(int i=0;i<n;++i){
        cin>>mooncake[i].price;
        if(mooncake[i].n!=0) mooncake[i].oneprice=mooncake[i].price/mooncake[i].n;
    }
    sort(mooncake,mooncake+n,[](mooncakes a,mooncakes b){return a.oneprice>b.oneprice;});
    int p=0;
    double price=0;
    while(p<n){
        if(need>=mooncake[p].n){
            price+=mooncake[p].price;
            need-=mooncake[p].n;
        }else{
            price=price+mooncake[p].oneprice*need;
            need=0;
            break;
        }
        ++p;
    }
    printf("%.2f",price);
    
    return 0;
}

