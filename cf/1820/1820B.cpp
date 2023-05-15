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
    string s;
	cin >> t;
    while (t--) { 
        cin >> s;
        ll n = s.size();
        ll i = 0;
        while (i < n && s[i] != '0') i++;
        if (i == n) cout << n*n << nl;
        else {
            string rt = "";
            f(j,0,n,1) rt += s[(i+j)%n];
            ll k = 0, mx = 0;
            while (k < n) {
                while (k < n && rt[k] == '0') k++;
                ll p = 0;
                while (k + p < n && rt[k + p] == '1') p++;
                mx = max(mx, p);
                k += p;
            }
            ll q = (mx+1)>>1;
            cout << q*(mx+1-q) << nl;
        }
	}
	return 0;
}
