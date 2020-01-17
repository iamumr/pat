#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> child[100001];
int maxdep, num;
void DFS(int root, int depth) {
	if (child[root].size() == 0) {
		if (depth > maxdep) {
			maxdep = depth;
			num = 1;
		}
		else if (depth == maxdep) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[root].size(); i++) {
		DFS(child[root][i], depth + 1);
	}
}
int main() {
	int n,root;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == -1) {
			root = i;
		}
		else {
			child[tmp].push_back(i);
		}
	}
	DFS(root, 0);
	printf("%.2f %d", p*pow((1 + r), maxdep), num);
}
