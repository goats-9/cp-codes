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

int num_ones(string s) {
    int n = s.size(), ctr = 0;
    f(i, 0, n, 1) if (s[i] == '1') ++ctr;
    return ctr;
}

string dec_to_bin(int d) {
    string b = "";
    while (d != 0) {
        b += char(d%2 + '0');
        d /= 2;
    }
    reverse(b.begin(), b.end());
    return b;
}

int hex_to_dec(int h) {
    int d = 0;
    while (h != 0) {
        d = 16*d + (h%10);
        h /= 10;
    } 
    return d;
} 

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d %d\n", num_ones(dec_to_bin(n)), num_ones(dec_to_bin(hex_to_dec(n))));
    }
    return 0;
}