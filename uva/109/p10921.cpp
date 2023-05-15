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

int main() {
    string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ints = "22233344455566677778889999";
    map<char, char> m;
    f(i, 0, 26, 1) m[cs[i]] = ints[i];
    string s;
    while (cin >> s) {
        int n = s.size();
        f(i, 0, n, 1) {
            if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", m[s[i]]);
            else printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}