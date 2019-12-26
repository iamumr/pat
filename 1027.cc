#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int r;
    char c[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    printf("#");
    for(int i=0;i<3;i++){
        cin>>r;
        string r1;
        do{
            r1.push_back(c[r%13]);
            r/=13;
        }while(r!=0);
        reverse(r1.begin(),r1.end());
        if(r1.size()==1) printf("0");
        cout<<r1;
    }
    return 0;
}

