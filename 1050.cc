//第二行也可能有空格
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    set<char> bb;
    for(int i=0;i<b.length();++i){
        bb.insert(b[i]);
    }
    for(int i=0;i<a.length();++i){
        if(bb.find(a[i])==bb.end()) cout<<a[i];
    }
    return 0;
}

