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
	f(k,1,t+1,1) { 
        string s;
        ll n;
        cin >> s >> n; n--;
        int sz = s.size();
        vll fac(sz, 1);
        vi ord(sz), pos(sz);
        f(i,1,sz,1) fac[i] = i*fac[i - 1];
        for (int i = sz - 1; i >= 0; i--) {
            ll q = n / fac[i];
            n = n % fac[i];
            int idx = 0;
            q++;
            while (q) {
                q -= (1 - ord[idx]);
                idx++;
            }
            idx--;
            ord[idx] = 1;
            pos[idx] = sz - 1 - i;
        }
        cout << "Case " << k << ": ";
        for (auto x : pos) cout << s[x];
        cout << nl;
	}
	return 0;
}
