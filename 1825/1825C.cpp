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
	int t, n, m, lt, rt, x;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        lt = 0, rt = 0;
        set<int> st;
        f(i,0,n,1) {
            cin >> x;
            if (x == -1) ++lt;
            else if (x == -2) ++rt;
            else st.insert(x);
        }
        int sz = st.size();
        int j = 0;
        int ans = min(m, max(lt + sz, rt + sz));
        for (int p : st) {
            int lf = min(lt + j, p - 1), rf = min(m - p + 1, rt + sz - j);
            ans = max(ans, lf + rf);
            ++j;
        }
        cout << ans << nl;
	}
	return 0;
}
