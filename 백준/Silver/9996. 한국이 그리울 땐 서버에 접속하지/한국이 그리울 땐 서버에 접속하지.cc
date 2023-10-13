#include <bits/stdc++.h>
using namespace std;

int n, targetIdx;
string pre, suf, s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	targetIdx = s.find("*");
	pre = s.substr(0, targetIdx);
	suf = s.substr(targetIdx + 1);
	while (n--) {
		cin >> s;
		if (s.size() < pre.size() + suf.size()) cout << "NE" << "\n";
		else {
			string front = s.substr(0, pre.size());
			string end = s.substr(s.size() - suf.size());
			if (pre == front && suf == end) cout << "DA" << "\n";
			else cout << "NE" << "\n";
		}
	}

    return 0;
}