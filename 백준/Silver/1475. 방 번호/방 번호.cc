#include <bits/stdc++.h>
using namespace std;
int N, cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N > 0) {
        int mod = N % 10;

        if (mod == 6 || mod == 9) {
            if (cnt[6] < cnt[9]) cnt[6]++;
            else cnt[9]++;
        } else cnt[mod]++;

        N = N / 10;
    }
    cout << *max_element(cnt, cnt + 10);
    return 0;
}