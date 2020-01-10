#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b){                     //求最大公约数
    if(b==0) return a;
    else return gcd(b,a%b);
}
void OutputNum(long long a,long long b){
    if(a%b==0){
        if(a/b<0){
            cout<<"("<<a/b<<")";
        }else{
            cout<<a/b;
        }
    }else if(a>b){
        cout<<a/b<<" "<<a-b*(a/b)<<"/"<<b;
    }else if((-a)>b){
        cout<<"("<<(a/b)<<" "<<(-a)+(a/b)*b<<"/"<<b<<")";
    }else{
        if(a<0){
            cout<<"("<<a<<"/"<<b<<")";
        }else{
            cout<<a<<"/"<<b;
        }
    }
}
void hj(long long a,long long b){
    //OutputNum(a,b);
    int  gys=gcd(abs(a),b);
    //cout<<t1<<" "<<t2<<" "<<flag<<endl;
    OutputNum(a/gys,b/gys);
}
int main()
{
    long long numerator1,numerator2,denominator1,denominator2;
    scanf("%lld/%lld",&numerator1,&denominator1);
    scanf("%lld/%lld",&numerator2,&denominator2);
    //sum
    hj(numerator1,denominator1);
    cout<<" + ";
    hj(numerator2,denominator2);
    cout<<" = ";
    hj(numerator1*denominator2+numerator2*denominator1,denominator1*denominator2);
    cout<<endl;
    //difference
    hj(numerator1,denominator1);
    cout<<" - ";
    hj(numerator2,denominator2);
    cout<<" = ";
    //cout<<numerator1*denominator2-numerator2*denominator1<<" "<<denominator1*denominator2<<endl;
    hj(numerator1*denominator2-numerator2*denominator1,denominator1*denominator2);
    cout<<endl;
    //product
    hj(numerator1,denominator1);
    cout<<" * ";
    hj(numerator2,denominator2);
    cout<<" = ";
    hj(numerator1*numerator2,denominator1*denominator2);
    cout<<endl;
    //quotient
    hj(numerator1,denominator1);
    cout<<" / ";
    hj(numerator2,denominator2);
    cout<<" = ";
    if(numerator2==0){
        cout<<"Inf";
    }else{
        hj(numerator1*denominator2*(numerator2>0?1:-1),(numerator2>0?numerator2:-numerator2)*denominator1);
    }
    return 0;
}
