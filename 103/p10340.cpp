#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    string s, t;
    while (cin >> s >> t) {
        if (cin.eof()) break;
        int x = t.size();
        int y = 0;
        for (int i = 0; i < x; i++) if (s[y] == t[i]) ++y;
        if (y == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}