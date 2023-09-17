#include <bits/stdc++.h>
using namespace std;
string s, cp;
int ret = 1;

int main() {
    cin >> s;
    cp = s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (char(* (s.begin() + i)) != char(*(cp.begin() + i))) {
            ret = 0;
            break;
        }
    }
    
    cout << ret;
    return 0;
}