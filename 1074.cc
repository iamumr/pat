//也可以实现链表，思路好像，代码难写
//要考虑到有冗余元素
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
int main() {
    int first, k, n, adress,count=0;
    cin >> first >> n >> k;
    int data[maxn], next[maxn], order[maxn];
    for (int i = 0; i < n; i++) {
        cin >> adress;
        cin >> data[adress] >> next[adress];
    }
    while (first != -1) {
        order[count++] = first;
        first = next[first];
    }
    n=count;
    for (int i = 0; i < (n - n % k); i += k)
        reverse(order + i, order + i + k);
    for (int i = 0; i < n - 1; i++)
        printf("%05d %d %05d\n", order[i], data[order[i]], order[i + 1]);
    printf("%05d %d -1", order[n - 1], data[order[n - 1]]);
    return 0;
}
