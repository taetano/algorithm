#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main() {
    cin >> a >> b;
    while (a-- > 0) {
        cin >> c;
        if (b > c) cout << c << " ";
    }
    return 0;
}