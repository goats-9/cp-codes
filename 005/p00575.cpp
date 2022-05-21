#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int toSkew(string &s) {
    int n = s.size();
    int ans = 0;
    f(i, 0, n, 1) ans += (s[i] - '0')*((1 << (n - i)) - 1);
    return ans;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "0") break;
        cout << toSkew(s) << "\n";
    }
    return 0;
}