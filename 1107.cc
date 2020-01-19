#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int father[1001],isRoot[1001],course[1001];
int find_father(int n){
    while(father[n]!=n){
        n=father[n];
    }
    return n;
}
void Union(int a,int b){
    int fa=find_father(a);
    int fb=find_father(b);
    father[fa]=fb;
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        father[i+1]=i+1;
    }
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d:",&num);
        for(int j=0;j<num;j++){
            int c;
            scanf("%d",&c);
            if(course[c]==0){
                course[c]=i;
            }
            Union(i,find_father(course[c]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        isRoot[find_father(i)]++;
    }
    for(int i=1;i<=n;i++){
        if(isRoot[i]!=0) ans++;
    }
    cout<<ans<<endl;
    sort(isRoot+1,isRoot+n,greater<int>());
    for(int i=1;i<=ans;i++){
        printf("%d",isRoot[i]);
        if(i!=ans) printf(" ");
    }
    return 0;
}

