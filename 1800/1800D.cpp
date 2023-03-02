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
    string s;
	cin >> t;
    while (t--) { 
        cin >> n >> s;
        int i = 0;
        int ans = 0;
        while (i < n-1) {
            int j = i + 1;
            char c1 = s[i], c2 = s[j];
            while (i < n && s[i] == c1) i += 2;
            while (j < n && s[j] == c2) j += 2;
            i = min(i,j)-1;
            ++ans;
        }
        cout << ans << nl;
	}
	return 0;
}
