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
        int k = -1, n = s.size();
        f(i, 1, n - 1, 1) { 
            if (s[i] == 'a') {k = i; break;}
        }
        if (k == -1) cout << s[0] << " " << s.substr(1, n - 2) << " " << s.back() << nl;
        else cout << s.substr(0, k) << " " << s[k] << " " << s.substr(k + 1, n - k - 1) << nl;
	}
	return 0;
}
