#include <bits/stdc++.h>
using namespace std;
int N, cnt[26];
string s;
bool b;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N-- > 0) {
        cin >> s;
        char c = s[0]; // 영어 1byte 이렇게 해도 상관없음
        cnt[c - 'a']++;
    }
   
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << (char)(i + 'a');
            b = true;
        }
    }
    
    if (!b) {
        cout << "PREDAJA";
    }
    return 0;
}