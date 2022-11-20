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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
    vi tr;
    int tr_num = 0;
    f(i, 0, 100, 1) { 
        tr_num += i; tr.pb(tr_num);
    }
	int t, m, s;
    scanf("%d", &t);
    while (t--) { 
        cin >> m >> s;
        int mx = 0, x;
        f(i, 0, m, 1) {cin >> x; mx = max(x, m); s += x;}
        auto it = lower_bound(all(tr), s);
        int pos = it - tr.begin();
        int smc = *it;
        if (s == smc && pos + 1 >= mx) cout << "YES\n";
        else cout << "NO\n";     
	}
	return 0;
}
