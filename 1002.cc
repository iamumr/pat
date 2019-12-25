#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    map<int,float> poly;
    int n,a;
    float b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        //if(poly.find(a)!=poly.end()){
            //poly[a]=poly[a]+b;
        //}else{
            poly[a]=b;
        //}
        //if(poly[a]==0) poly.erase(a);
    }
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(poly.find(a)!=poly.end()){
            poly[a]=poly[a]+b;
        }else{
            poly[a]=b;
        }
        if(poly[a]==0) poly.erase(a);
    }
    cout<<poly.size();
    for(auto pair=poly.rbegin();pair!=poly.rend();){
        cout<<" "<<pair->first<<" ";
        printf("%.1f",pair->second);
        pair++;
    }
    return 0;
}
