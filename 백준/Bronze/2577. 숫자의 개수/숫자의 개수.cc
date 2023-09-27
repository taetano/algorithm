#include <bits/stdc++.h>
using namespace std;
int a, b, c, ret, cnt[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    ret = a * b * c;
    while (ret > 0) {
        int mod = ret % 10;
        cnt[mod]++;
        ret = ret / 10;
    }
    for (int n : cnt) cout << n << "\n";
    return 0;
}