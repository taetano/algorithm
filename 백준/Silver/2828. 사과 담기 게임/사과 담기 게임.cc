#include <bits/stdc++.h>
using namespace std;

int n, m, j, p, l, r, ret;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> j;
    int l = 1; r = m;
    while (j--) {
        cin >> p;
        if (p < l) {
            ret += l - p;
            l = p;
            r = l + m - 1;
        } else if (p > r) {
            ret += p - r;
            r = p;
            l = r - m + 1;
        } else continue;
    }
    
    cout << ret;
    return 0;
}