#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
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
    int n, m, q;
    string s;
    cin >> n >> m >> q >> s;
    set<int> rem;
    f(i,0,n,1) rem.insert(i);
    vi prio;
    f(i,0,m,1) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto it = rem.lower_bound(l);
        while ((it != rem.end()) && (*it <= r)) {
            int x = *it;
            ++it;
            prio.pb(x);
            rem.erase(rem.find(x));
        }
    }
    vi pt(n, -1);
    f(i,0,prio.size(),1) pt[prio[i]] = i;
    ordered_set p1, p0;
    int np1 = 0, np0 = 0;
    f(i,0,n,1) {
        if (pt[i] == -1) {
            if (s[i] == '1') ++np1;
            else ++np0;
        } else {
            if (s[i] == '1') p1.insert(pt[i]);
            else p0.insert(pt[i]);
        }
    }
    f(i,0,q,1) {
        int pos;
        cin >> pos;
        pos--;
        if (pt[pos] == -1) {
            if (s[pos] == '0') --np0, ++np1;
            else --np1, ++np0;
        } else {
            int x = pt[pos];
            if (s[pos] == '0') p0.erase(x), p1.insert(x);
            else p1.erase(x), p0.insert(x);
        }
        s[pos] = '0' + ('1' - s[pos]);
        int num = min(prio.size(), np1 + p1.size());
        int inpos = p1.order_of_key(num);
        int outpos = p1.size() - inpos + np1;
        int rep = p0.order_of_key(num);
        cout << min(outpos, rep) << nl;
    }
	return 0;
}
