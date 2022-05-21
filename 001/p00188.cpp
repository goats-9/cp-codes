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

int weight(string s) {
    int ans = 0, n = s.size();
    f(i, 0, n, 1) {
        ans = 32*ans + (s[i] - 'a' + 1);
    }
    return ans;
}

ll r(int x, int y, int z) { return (x/y)%z; }

int check(ll &c, vi &w) {
    int m = w.size();
    f(i, 0, m, 1) {
        f(j, i + 1, m, 1) {
            if (r(c, w[i], m) == r(c, w[j], m)) {
                c = min(w[i]*(c/w[i] + 1), w[j]*(c/w[j] + 1));
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    string s;
    while (getline(cin, s)) {
        vi w;
        int n = s.size();
        string w_in = "";
        f(i, 0, n, 1) {
            if (s[i] != ' ') w_in += s[i];
            else if (w_in != "") {
                w.push_back(weight(w_in));
                w_in = "";
            }
        }
        if (w_in != "") w.push_back(weight(w_in));
        sort(w.begin(), w.end());
        ll c = w[0];
        while (!check(c, w));
        printf("%s\n%lld\n\n", s.c_str(), c);  
        if (cin.eof()) break;
    }
    return 0;
}