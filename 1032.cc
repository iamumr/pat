//通过两个数组模拟链表，其实本体中data完全不需要
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
    int lf=0,ls=0,tmp;
    tmp=f;
    while(tmp!=-1){
        lf++;
        tmp=nex[tmp];
    }
    tmp=s;
    while(tmp!=-1){
        ls++;
        tmp=nex[tmp];
    }
    if(lf>ls){
        for(int i=0;i<lf-ls;i++){
            f=nex[f];
        }
    }else if(ls>lf){
        for(int i=0;i<ls-lf;i++){
            s=nex[s];
        }
    }
    while(f!=-1){
        if(f==s) {
            printf("%05d",f);
            break;
        }
        f=nex[f];
        s=nex[s];
    }
    if(f==-1) cout<<"-1";
    return 0;
}

