#include <bits/stdc++.h>
using namespace std;

int total, a[9];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    
    sort(a, a + 9);
    do {
        total = 0;
        for (int i = 0; i < 7; i++) total += a[i];
        if (total != 100) continue;
        
        for (int i = 0; i < 7; i++) {
            cout << a[i] << "\n";
        }
        break;
    } while (next_permutation(a, a + 9));
    
    return 0;
}