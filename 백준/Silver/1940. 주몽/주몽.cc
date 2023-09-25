#include <bits/stdc++.h>
using namespace std;
int n, m, k, ret;
map<int, int> mp;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (n-- > 0) {
        cin >> k;
        if (mp.find(m - k) != mp.end()) {
            ret++; 
            continue; // 고유한 번호이고 자연수이기에 다른케이스 신경x
        }
        mp[k] = 1;
    }
    cout << ret;
    return 0;
}