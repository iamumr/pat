#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    char data[100001];
    int nex[100001];
    int f,s,n;
    cin>>f>>s>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cin>>data[tmp]>>nex[tmp];
    }
    string ff="",ss="";
    while(f!=-1){
        ff+=data[f];
        f=nex[f];
    }
    while(s!=-1){
        ss+=data[s];
        s=nex[s];
    }
    cout<<ff<<" "<<ss<<endl;
    int j=ff.size()-1,k=ss.size()-1;
    int same=0;
    char an;
    while(j>=0&&k>=0){
        if(ff[j]==ss[k]){
            same++;
            an=ff[j];
            j--;k--;
        }else{
            break;
        }
    }
    if(same==0) cout<<"-1";
    else{
        for(int i=0;i<100001;i++){
            if(data[i]==an){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}

