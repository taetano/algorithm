#include <bits/stdc++.h>
using namespace std;

string s;
int cnt1, cnt2;
bool vowel, flag;
char pre;

void ans1(string s) {
	cout << '<' << s << '>' << " is acceptable." << "\n";
}

void ans2(string s) {
	cout << '<' << s << '>' << " is not acceptable." << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> s;
        if (s == "end") break;
        for (char c : s) {
            if (c != 'e' && c != 'o' && pre == c) {
                flag = true;
                break;
            }
            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') {
                if (++cnt1 == 3) flag = true;
                pre = c;
                cnt2 = 0;
                vowel = true;
            } else {
                if (++cnt2 == 3) flag = true;
                pre = c;
                cnt1 = 0;
            }
            
            if (flag) break;
        }
        
        if (!vowel || flag) ans2(s);
        else if (!flag) ans1(s);
        
        cnt1 = 0; cnt2 = 0; vowel = 0; flag = 0; pre = '0';
    }
    
    return 0;
}