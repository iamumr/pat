#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char a[3]={'W','T','L'};
    float b,tmp=0.0;
    float ans=1.0;
    int max_e=0;
    for(int i=0;i<3;++i){
        tmp=0.0;
        for(int j=0;j<3;j++){
            cin>>b;
            if(b>tmp){
                tmp=b;
                max_e=j;
            }
        }
        printf("%c ",a[max_e]);
        ans*=tmp;
    }
    ans=(ans*0.65-1)*2;
    printf("%.2f",ans);
    return 0;
}

