#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   float a[1001],b[1001],c[2001];
   fill_n(c,2001,0);
   fill_n(a,1001,0);
   fill_n(b,1001,0);
   int n;
   cin>>n;
    int e;
    float f;
   for(int i=0;i<n;++i){
       cin>>e>>f;
       a[e]=f;
   }
   cin>>n;
   for(int i =0;i<n;++i){
       cin>>e>>f;
       b[e]=f;
   }
   for(int i=0;i<1001;++i){
       for(int j=0;j<1001;++j){
           c[i+j]=c[i+j]+a[i]*b[j];
       }
   }
   int cout=0;
   for(int i=0;i<2001;++i){
        if(c[i]!=0) cout++;
   }
   printf("%d",cout);
   for(int i =2000;i>=0;--i){
        if(c[i]!=0) printf(" %d %.1f",i,c[i]);
   }
    return 0;
}

