#include <iostream>
using namespace std;
int main()
{
    long long a,b,c;
    int n;
    cin>>n;
    string d[2]={"false","true"};
    int flag=0;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        long long ab=a+b;
        if(a>0&&b>0&&ab<0){
            flag=1;
        }else if(a<0&&b<0&&ab>=0){
            flag=0;
        }else if(ab>c){
            flag=1;
        }else{
            flag=0;
        }
        cout<<"Case #"<<i+1<<": "<<d[flag];
        if(i!=n-1) cout<<endl;
    }
    return 0;
}

