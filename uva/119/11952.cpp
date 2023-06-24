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
        string a, b, c, s1, s2;
        cin >> a >> s1 >> b >> s2 >> c;
        bool onefl = true;
        for (char x : a) if (x != '1') onefl = false;
        for (char x : b) if (x != '1') onefl = false;
        for (char x : c) if (x != '1') onefl = false;
        if (onefl && (a.size() + b.size() == c.size())) {cout << 1 << nl; continue;}
        vi da, db, dc;
        int mn = 2;
        for (char x : a) da.pb(x-'0'), mn = max(mn, 1+x-'0');
        for (char x : b) db.pb(x-'0'), mn = max(mn, 1+x-'0');
        for (char x : c) dc.pb(x-'0'), mn = max(mn, 1+x-'0');
        bool fl = false;
        f(i,mn,19,1) {
            ll A = 0, B = 0, C = 0;
            for (auto d : da) A = i*A + d;
            for (auto d : db) B = i*B + d;
            for (auto d : dc) C = i*C + d;
            if (A + B == C) {
                cout << i << nl;
                fl = true;
                break;
            }
        }
        if (!fl) cout << 0 << nl;
	}
	return 0;
}
