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
        vi a(10);
        ++a[s[0]-'0'];
        ++a[s[1]-'0'];
        ++a[s[2]-'0'];
        ++a[s[3]-'0'];
        int p = 0, q = 0, r = 0, s = 0;
        f(i,0,10,1) {
            if (a[i] == 1) ++p;
            else if (a[i] == 2) ++q;
            else if (a[i] == 3) ++r;
            else if (a[i] == 4) ++s;
        }
        if (s == 1) cout << -1 << nl;
        else {
            if (r == 1) cout << 6 << nl;
            else cout << 4 << nl;
        }
	}
	return 0;
}
