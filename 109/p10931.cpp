#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

string dec_to_bin(int d) {
    string s = "";
    while (d != 0) {
        s += (d%2 ? '1' : '0');
        d /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int nz(string s) {
    int k = s.size(), ans = 0;
    f(i, 0, k, 1) ans += s[i] - '0';
    return ans;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        cout << "The parity of " << dec_to_bin(n) << " is " << nz(dec_to_bin(n)) << " (mod 2).\n";
    }
    return 0;
}