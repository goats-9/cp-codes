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
    V<pii> a(6);
    while (
        cin >> a[0].first >> a[0].second 
        >> a[1].first >> a[1].second 
        >> a[2].first >> a[2].second 
        >> a[3].first >> a[3].second 
        >> a[4].first >> a[4].second 
        >> a[5].first >> a[5].second
    ) {
        M<pii, int> dim;
        set<int> st;
        f(i,0,6,1) {
            dim[pii(min(a[i].first, a[i].second), max(a[i].first, a[i].second))]++;
            st.insert(a[i].first), st.insert(a[i].second);
        }
        if ((int)st.size() > 3 || (int)dim.size() > 3) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        bool fl = true;
        for (auto &keyval: dim) {
            if (keyval.second%2) {
                fl = false;
                break;
            }
        }
        if (!fl) cout << "IM";
        cout << "POSSIBLE\n";
    }
	return 0;
}
