//flag完全不需要，直接判断最终栈是否为空即可，中间当爆栈的时候退出循环即可
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        vector<int> real(n);
        stack<int> st;
        int flag=1;
        for(int j=0;j<n;j++){
            cin>>real[j];
        }
        int k=0;
        for(int j=1;j<=n;j++){
            st.push(j);
            if(st.size()>m){
//                flag=0;
                //cout<<j<<" "<<st.size()<<endl;
                break;
            }else{
                //cout<<k<<" "<<st.top()<<" "<<real[k]<<endl;
                while(st.size()>0&&st.top()==real[k]){
                    st.pop();
                    k++;
                }
            }
        }
        cout<<((flag&&st.empty())?"YES":"NO")<<endl;

    }
    return 0;
}

