#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct person{
    int id,virtue,grade;
};
bool cmp(person a,person b){
    auto as=a.virtue+a.grade;
    auto bs=b.virtue+b.grade;
    if(as!=bs){
        return as>bs;
    }else if(a.virtue!=b.virtue){
        return a.virtue>b.virtue;
    }
    else{
        return a.id<b.id;
    }
}
int main()
{
    int n,low,high;
    cin>>n>>low>>high;
    vector<person> sage,noble,fool,other;
    int t1,t2,t3;
    person tmp;
    for(int i=0;i<n;++i){
        cin>>t1>>t2>>t3;
        if(t2<low||t3<low){
            continue;
        }else if(t2>=high&&t3>=high){
            tmp.id=t1;tmp.virtue=t2;tmp.grade=t3;
            sage.push_back(tmp);
        }else if(t2>=high&&t3>=low){
            tmp.id=t1;tmp.virtue=t2;tmp.grade=t3;
            noble.push_back(tmp);
        }else if(t2>=t3&&t2<high&&t3<high){
            tmp.id=t1;tmp.virtue=t2;tmp.grade=t3;
            fool.push_back(tmp);
        }else{
            tmp.id=t1;tmp.virtue=t2;tmp.grade=t3;
            other.push_back(tmp);
        }
    }
    cout<<sage.size()+noble.size()+fool.size()+other.size()<<endl;
    sort(sage.begin(),sage.end(),cmp);
    sort(noble.begin(),noble.end(),cmp);
    sort(fool.begin(),fool.end(),cmp);
    sort(other.begin(),other.end(),cmp);
    for(decltype(sage.size())i=0;i<sage.size();++i){
        cout<<sage[i].id<<" "<<sage[i].virtue<<" "<<sage[i].grade<<endl;
    }
    for(decltype(sage.size())i=0;i<noble.size();++i){
        cout<<noble[i].id<<" "<<noble[i].virtue<<" "<<noble[i].grade<<endl;
    }
    for(decltype(sage.size())i=0;i<fool.size();++i){
        cout<<fool[i].id<<" "<<fool[i].virtue<<" "<<fool[i].grade<<endl;
    }
    for(decltype(sage.size())i=0;i<other.size();++i){
        cout<<other[i].id<<" "<<other[i].virtue<<" "<<other[i].grade<<endl;
    }
    return 0;
}

