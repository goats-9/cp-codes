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
	int t, n;
    string s;
    scanf("%d", &t);
    while (t--) { 
        cin >> n >> s;
        V<pair<string, int>> tp;
        f(i, 0, n - 1, 1) {
            string tpi = "";
            tpi = tpi + s[i] + s[i + 1];
            tp.pb(mp(tpi, i));
        }
        sort(all(tp));
        bool fl = false;
        int i = 0;
        while (i < n - 1) { 
            int k = 0;
            while (tp[i].first == tp[i + k].first) {
                if (tp[i + k].second - tp[i].second > 1) {fl = true; break;}
                ++k;
            }
            if (fl) break;
            i += k;
        }
        if (fl) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
