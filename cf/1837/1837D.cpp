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
        int n;
        string s;
        cin >> n >> s;
        vi a(n+1);
        f(i,1,n+1,1) {
            if (s[i-1] == '(') a[i] = a[i-1] + 1;
            else a[i] = a[i-1] - 1;
        }
        if (a.back() != 0) {cout << -1 << nl; continue;}
        V<P<pii, int>> ints;
        bool has2 = false, has1 = false;
        ints.pb({{0,0},-1});
        f(i,1,n+1,1) {
            if (!a[i]) {
                int x = (a[i-1] > 0) ? 1 : 2;
                int prev = ints.back().first.second + 1;
                ints.pb({{prev, i}, x});
                if (x == 2) has2 = true;
                if (x == 1) has1 = true;
            }
        }
        int sz = ints.size();
        if (has1 && has2) cout << 2 << nl;
        else cout << 1 << nl;
        f(i,1,sz,1) {
            int num = ints[i].first.second + 1 - ints[i].first.first;
            int clr = (has1 && has2) ? ints[i].second : 1;
            f(j,0,num,1) cout << clr << ' ';
        }
        cout << nl;
	}
	return 0;
}
