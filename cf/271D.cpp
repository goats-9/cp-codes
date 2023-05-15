#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

vi zfunc(string &s) { 
    int n = s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s, a; int k;
    cin >> s >> a >> k;
    ll ans = 0;
    f(i, 0, s.size(), 1) {
        string t = s.substr(0, i + 1);
        reverse(all(t));
        vi z = zfunc(t);
        int mx = *max_element(all(z)), cnt = 0;
        f(j, 0, i + 1, 1) {
            cnt += !(a[t[j] - 'a'] - '0');
            if (cnt > k) break;
            ans += (j >= mx);
        }
    }
    cout << ans << nl;
	return 0;
}
