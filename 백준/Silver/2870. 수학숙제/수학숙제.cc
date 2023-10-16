#include <bits/stdc++.h>
using namespace std;

int n;
string s, tmp;
vector<string> v;

int cmp(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n--) {
        cin >> s;
        for (char c : s) {
            if ('0' <= c && c <= '9') {
                tmp == "0" ? tmp = c : tmp += c;
            } else if(!tmp.empty()){
                v.push_back(tmp);
                tmp = "";
            }
        }
        if (!tmp.empty()) v.push_back(tmp);
        tmp = "";
    }
    sort(v.begin(), v.end(), cmp);
    for (string each : v) {
        cout << each << "\n";
    }
    return 0;
}