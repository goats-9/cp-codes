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

void disp(vvll &v) { 
    f(i, 0, v.size(), 1) { 
        f(j, 0, v[i].size(), 1) cout << v[i][j] << " ";
        cout << nl;
    }
    cout << "-\n";
}

int main() {
	int n, m;
    cin >> n >> m;
    vvll a(n, vll(m));
    f(i, 0, n, 1) f(j, 0, m, 1) cin >> a[i][j];
    vvll dp1m(n, vll(m)), dp1f(n, vll(m)), dp2m(n, vll(m)), dp2f(n, vll(m));
    for (int i = n - 1; i >= 0; i--) { 
        for (int j = m - 1; j >= 0; j--) { 
            int mx = 0;
            if (i + 1 == n && j + 1 == m);
            else if (i + 1 == n) mx = dp1m[i][j + 1];
            else if (j + 1 == m) mx = dp1m[i + 1][j];
            else mx = max(dp1m[i + 1][j], dp1m[i][j + 1]);
            dp1m[i][j] = a[i][j] + mx;
        }
    }
    for (int i = 0; i < n; i++) { 
        for (int j = m - 1; j >= 0; j--) { 
            ll mx = 0;
            if (i == 0 && j + 1 == m);
            else if (i == 0) mx = dp1f[i][j + 1];
            else if (j + 1 == m) mx = dp1f[i - 1][j];
            else mx = max(dp1f[i - 1][j], dp1f[i][j + 1]);
            dp1f[i][j] = a[i][j] + mx;
        }
    }
    f(i, 0, n, 1) { 
        f(j, 0, m, 1) { 
            ll mx = 0;
            if (i == 0 && j == 0);
            else if (i == 0) mx = dp2m[i][j - 1];
            else if (j == 0) mx = dp2m[i - 1][j];
            else mx = max(dp2m[i][j - 1], dp2m[i - 1][j]);
            dp2m[i][j] = a[i][j] + mx;
        }
    }
    for (int i = n - 1; i >= 0; i--) { 
        f(j, 0, m, 1) { 
            ll mx = 0;
            if (i + 1 == n && j == 0);
            else if (i + 1 == n) mx = dp2f[i][j - 1];
            else if (j == 0) mx = dp2f[i + 1][j];
            else mx = max(dp2f[i + 1][j], dp2f[i][j - 1]);
            dp2f[i][j] = a[i][j] + mx;
        }
    }
    ll ans = 0;
    f(i, 1, n - 1, 1) f(j, 1, m - 1, 1) {
        ans = max(ans, max(dp1m[i + 1][j] + dp2m[i - 1][j] + dp1f[i][j + 1] + dp2f[i][j - 1], dp1f[i - 1][j] + dp2f[i + 1][j] + dp2m[i][j - 1] + dp1m[i][j + 1]));
    }
    cout << ans << nl;
	return 0;
}
