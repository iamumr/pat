nclude <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int k;
	cin >> k;
	double a[1001] = { 0 }, tt;
	set<int> xuhao;
	while (k--) {
		int tmp;
		cin >> tmp;
		cin >> a[tmp];
		xuhao.emplace(tmp);
	}
	cin >> k;
	while (k--) {
		int tmp;
		cin >> tmp;
		cin >> tt;
		a[tmp] += tt;
		xuhao.emplace(tmp);
	}
    int count=0;
  for(int i = 0; i < 1001; i ++){
    if(a[i] != 0){
      count ++;
    }
  }
  printf("%d", count);
	for (int i = 1000; i >= 0; i--) {
		if (a[i] != 0) printf(" %d %.1f", i, a[i]);
	}
	/*for(auto t=xuhao.rbegin();t!=xuhao.rend();t++){
		//cout<<*t<<" "<<a[*t]+b[*t];
		printf("%d %.1f",*t,a[*t]);
		if(*t!=*xuhao.begin()) printf(" ");
	}*/
	return 0;
}


