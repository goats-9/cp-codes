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
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	int t;
	cin >> t;
	while (t--) { 
        int m;
        string s, l ,r;
        cin >> s >> m >> l >> r;
        int i = 0, ptr = 0;
        int n = s.size();
        while (i < m) {
            vi vis(10);
            int chk = r[i] - l[i] + 1, cur = 0;
            while (ptr < n) {
                if (s[ptr] >= l[i] && s[ptr] <= r[i]) {
                    int d = s[ptr] - '0';
                    cur += (1 - vis[d]);
                    vis[d] = 1;
                }
                ptr++;
                if (chk == cur) {
                    i++;
                    break;
                }
            }
            if (ptr == n) break;
        }
        if (i == m) cout << "NO\n";
        else cout << "YES\n";
	}
	return 0;
}
