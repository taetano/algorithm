#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while(n--) {
		cin >> s;
		stack<char> S;
		for (char c : s) {
			if (S.empty()) S.push(c);
			else if (S.top() == '(' && c == ')') S.pop();
			else if (S.top() == ')' && c == '(') break;
			else S.push(c);
		}
		
		if (S.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
	return 0;
}