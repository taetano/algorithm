#include <bits/stdc++.h>
using namespace std;
string rev, origin; 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> rev;
	origin = rev;
	reverse(rev.begin(), rev.end());
	cout << (origin == rev);
    return 0;
}