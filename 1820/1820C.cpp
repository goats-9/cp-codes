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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        vi a(n);
        set<int> st;
        f(i,0,n,1) {
            cin >> a[i];
            st.insert(a[i]);
        }
        int mex = 0;
        for (int c : st) {
            if (c == mex) ++mex;
            else break;
        }
        if (mex == 0) cout << "Yes\n";
        else if (mex == n) cout << "No\n";
        else {
            vi pos;
            f(i,0,n,1) if (a[i] == mex + 1) pos.pb(i);
            if (pos.empty()) cout << "Yes\n";
            else {
                int l = pos.front(), r = pos.back();
                vi cnt(mex);
                f(i,0,n,1) {
                    if (i < l || i > r) {
                        if (a[i] < mex) ++cnt[a[i]];
                    } 
                }
                bool fl = true;
                f(i,0,mex,1) if (cnt[i] == 0) {fl = false; break;}
                if (fl) cout << "Yes\n";
                else cout << "No\n";
            }
        }
	}
	return 0;
}
