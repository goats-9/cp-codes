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
	int t;
	cin >> t;
    string s;
    while (t--) { 
        cin >> s;
        int n = s.size();
        vi a(26);
        ll mn = n;
        f(i,0,n,1) ++a[s[i]-'a'];
        f(i,0,26,1) {
            if (a[i]) {
                char ch = char('a' + i);
                int p = 0;
                ll mnl = 0;
                while (p < n) {
                    while (p < n && s[p] == ch) ++p;
                    int k = 0;
                    while (p + k < n && s[p + k] != ch) ++k;
                    if (k) mnl = max(mnl, 1 + (ll)floor(log2l(k*1.0)));
                    p += k;
                }
                if (mnl < mn) mn = mnl;
            }
        }
        cout << mn << nl;
	}
	return 0;
}
