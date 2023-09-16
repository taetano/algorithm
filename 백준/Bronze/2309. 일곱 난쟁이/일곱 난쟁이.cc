#include<bits/stdc++.h>
using namespace std;
int a[9], sum;
pair<int, int> p;
void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - a[i] - a[j] == 100) {
                p = {a[i], a[j]};
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }
    solve();
    sort(a, a + 9);
    for (int n : a) {
        if (p.second == n || p.first == n) continue;
        cout << n << "\n";
    }
    return 0;
}