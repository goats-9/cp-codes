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
    int t;
    scanf("%d", &t);
    map<string, int> c;
    string s;
    while (t--) {
        cin >> s;
        if (c.find(s) == c.end()) c[s] = 1;
        else ++c[s];
        getline(cin, s);
    }
    vector<pair<string, int>> ans;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ans.push_back({it->first, it->second});
    }
    sort(ans.begin(), ans.end());
    int k = ans.size();
    f(i, 0, k, 1) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}