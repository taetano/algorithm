#include <bits/stdc++.h>
using namespace std;

int h, w, a[101][101];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			s[j] == 'c' ? a[i][j] = 0 : a[i][j] = -1;
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) {
				while (j < w && a[i][j + 1]) {
					a[i][j + 1] = a[i][j] + 1;
					j++;
				}
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
    return 0;
}