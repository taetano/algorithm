#include<bits/stdc++.h>
using namespace std;
string s, ret;

int main() {
    getline(cin, s);
    for (char c: s) {
        if ('a' <= c && c <= 'z') {
            ret += (c - 'a' + 13) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            ret += (c - 'A' + 13) % 26 + 'A';
        } else {
            ret += c;
        }
    }
    cout << ret;
    return 0;
}