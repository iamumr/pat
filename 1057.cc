#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int block[316];
int table[100001];
int main()
{
    vector<int> path;
    int n;
    scanf("%d",&n);
    getchar();
    set<int> s;
    for(int i=0;i<n;i++){
        string tmp;
        getline(cin,tmp);
        if(tmp[1]=='u'){
            path.push_back(stoi(tmp.substr(5)));
            block[path.back()/316]++;
            table[path.back()]++;
        }else if(tmp[1]=='o'){
            if(path.size()!=0){
                cout<<path.back()<<endl;
                block[path.back()/316]--;
                table[path.back()]--;
                path.pop_back();
            }
            else cout<<"Invalid"<<endl;
        }else{
            if(path.size()==0) cout<<"Invalid"<<endl;
            else{
                int k=(path.size()+1)/2;
                int sum=0,i=0;
                while(sum+block[i]<k){
                    sum+=block[i++];
                }
                int num=i*316;
                while(sum+table[num]<k){
                    sum+=table[num++];
                }
                cout<<num<<endl;
            }
        }
    }
    return 0;
}

