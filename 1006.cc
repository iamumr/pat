#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    string number,sign_in,sign_out;
    int n,tmp[2],intime,outtime;
    string unlockn,lockn;
    tmp[0]=0;tmp[1]=240000;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>number>>sign_in>>sign_out;
        sign_in.erase(2,1);
        sign_in.erase(4,1);
        sign_out.erase(2,1);
        sign_out.erase(4,1);
        intime=stoi(sign_in);
        outtime=stoi(sign_out);
        if(intime<tmp[1]){
            unlockn=number;
            tmp[1]=intime;
        }
        if(outtime>tmp[0]){
            lockn=number;
            tmp[0]=outtime;
        }
    }
    cout<<unlockn<<" "<<lockn;
    return 0;
}

