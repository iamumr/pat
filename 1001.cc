#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long int a,b;
    cin>>a>>b;
    a=a+b;
    //cout<<a<<endl;
    string c=to_string(a);
    if(c[0]=='-'){
        cout<<'-';
    for(int i=1;i<c.size();i++){
        cout<<c[i];
        if((c.size()-i-1)%3==0&&i!=(c.size()-1)){
            cout<<',';
        }
    }
    }else{
    for(int i=0;i<c.size();i++){
        cout<<c[i];
        if((c.size()-i-1)%3==0&&i!=(c.size()-1)){
            cout<<',';
        }
    }
    }
    return 0;
}

