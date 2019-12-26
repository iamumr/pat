#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    string t1,t2;
    cin>>n;
    vector<string> pwd1;
    vector<string> pwd2;
    for(int i=0;i<n;++i){
        cin>>t1>>t2;
        int flag=0;
        for(int j=0;j<t2.size();++j){
            if(t2[j]=='1'){t2[j]='@';flag++;}
            else if(t2[j]=='0'){t2[j]='%';flag++;}
            else if(t2[j]=='l'){t2[j]='L';flag++;}
            else if(t2[j]=='O'){t2[j]='o';flag++;}
        }
        if(flag){
            pwd1.push_back(t1);
            pwd2.push_back(t2);
        }
    }
    if(pwd1.size()==0){
        if(n==1){
        cout<<"There is "<<n<<" account and no account is modified";
        }else{
        cout<<"There are "<<n<<" accounts and no account is modified";}
        }
    else{
        cout<<pwd1.size();
        for(auto i=0;i<pwd1.size();++i){
            cout<<endl;
            cout<<pwd1[i]<<" "<<pwd2[i];

        }
    }

    return 0;
}

