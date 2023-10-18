#include <bits/stdc++.h>
using namespace std;

string s;

bool isAlpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool isSpace(char c) {
	return c == ' ';
}

bool isDot(char c) {
	return c == '.';
}

bool isBracket(char c) {
	return !(isAlpha(c) || isSpace(c) || isDot(c));
}

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	while (true) {
		getline(cin, s);
		stack<char> S;
		if (s == ".") break;
		
		for (char c : s) {
			if (!isBracket(c)) continue;
			
			if (S.empty()) S.push(c);
			else if (S.top() == '(' && c == ']') break;
			else if (S.top() == '[' && c == ')') break;
			else if (S.top() == ')' || S.top() == ']') break;
			else if (S.top() == '(' && c == ')') S.pop();
			else if (S.top() == '[' && c == ']') S.pop();
			else S.push(c);
		}
		
		if (S.empty()) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	
	return 0;
}