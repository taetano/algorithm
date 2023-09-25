#include <bits/stdc++.h>
using namespace std;
int n, k, tmp, psum[100004], mx = -10000000;
int main() {
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++) {
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    for (int i = k; i < n + 1; i++) {
        int candi = psum[i] - psum[i - k];
        if (mx < candi) {
            mx = candi;
        }
    }
    cout << mx;
    return 0;
}