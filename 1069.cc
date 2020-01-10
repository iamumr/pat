#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string number;
    cin>>number;
    if(number.size()<4){number.insert(number.begin(),4-number.size(),'0');}
    do{
        string big,small;
        big=number;small=number;
        sort(big.begin(),big.end(),greater<int>());
        sort(small.begin(),small.end(),less<int>());
        number=to_string(stoi(big)-stoi(small));
        if(number.size()<4){number.insert(number.begin(),4-number.size(),'0');}
        printf("%04d - %04d = %04d\n",stoi(big),stoi(small),stoi(number));
    }while(stoi(number)!=0000&&stoi(number)!=6174);
    return 0;
}
