#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int g0,s0,k0,g1,s1,k1;
    scanf("%d.%d.%d %d.%d.%d",&g0,&s0,&k0,&g1,&s1,&k1);
    k0+=k1;
    s0+=s1;
    g0+=g1;
    if(k0>=29){
        k0-=29;
        s0++;
    }
    if(s0>=17){
        s0-=17;
        g0++;
    }
    printf("%d.%d.%d",g0,s0,k0);
    return 0;
}

