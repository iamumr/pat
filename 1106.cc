#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct node{
    double price;
    vector<int> customer;
}Node[100001];
int n;
double p,r;
double lp=1e12;
int lpn=0;
void dfs(int root){
    if(Node[root].customer.size()==0){
    if(Node[root].price==lp){
        lpn++;
    }else if(Node[root].price<lp){
        lp=Node[root].price;
        lpn=1;
    }
    return;
    }
    for(int i=0;i<Node[root].customer.size();i++){
        Node[Node[root].customer[i]].price=Node[root].price*(1+r/100);
        dfs(Node[root].customer[i]);
    }
}
int main()
{
    cin>>n>>p>>r;
    for(int i=0;i<n;i++){
        int num;
        double tmp;
        cin>>num;
        if(0!=num){
            for(int j=0;j<num;j++){
                cin>>tmp;
                Node[i].customer.push_back(tmp);
            }
        }
    }
    Node[0].price=p;
    dfs(0);
    printf("%.4lf %d",lp,lpn);
    return 0;
}

