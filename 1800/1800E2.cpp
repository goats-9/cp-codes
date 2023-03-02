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

int main() {
	int tc;
    int n, k;
    string s, t;
	cin >> tc;
    while (tc--) { 
        cin >> n >> k >> s >> t;
        vi a(26), b(26);
        f(i,0,n,1) ++a[s[i]-'a'], ++b[t[i]-'a'];
        if (a != b) {
            cout << "NO\n";
            continue;
        }
        if (n <= k) {
            if (s == t) cout << "YES\n";
            else cout << "NO\n";
        } else if (n <= 2*k) {
            int l = n - k;
            vi c(26), d(26);
            f(i,0,l,1) ++c[s[i]-'a'], ++d[s[i]-'a'], ++c[s[i+k]-'a'], ++d[s[i+k]-'a'];
            if (c == d) {
                bool fl = true;
                f(i, l, k, 1) if (s[i] != t[i]) {fl = false; break;}
                if (fl) cout << "YES\n";
                else cout << "NO\n";
            } else cout << "NO\n";
        } else cout << "YES\n";
	}
	return 0;
}
