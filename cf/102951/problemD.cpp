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
	int n, q, l, r, v;
    cin >> n >> q;
    M<ll, ll> vals, prefix;
    f(i,0,n,1) {
        cin >> l >> r >> v;
        vals[l] += v;
        vals[r] -= v;
    }
    ll sm = 0, pkey = 0, pval = 0;
    for (auto &[_, val] : vals) {
        sm += val;
        val = sm;
    }
    sm = 0;
    for (auto &[key, val]: vals) {
        sm += pval*(key-pkey);
        prefix[key] = sm;
        pkey = key, pval = val;
    }
    f(i,0,q,1) {
        cin >> l >> r;
        ll sml = 0, smr = 0;
        auto itl = prefix.upper_bound(l);
        if (itl == prefix.begin()) sml = 0;
        else {
            --itl;
            ll key = (*itl).first, val = (*itl).second;
            sml = val + (l - key)*vals[key];
        }
        auto itr = prefix.upper_bound(r);
        if (itr == prefix.begin()) smr = 0;
        else {
            --itr;
            ll key = (*itr).first, val = (*itr).second;
            smr = val + (r - key)*vals[key];
        }
        cout << smr - sml << nl;
    }
	return 0;
}
