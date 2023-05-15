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
        int ans = 1;
        if (s[0] == '0') {
            cout << 0 << nl;
            continue;
        }
        f(i,0,s.size(),1){
            if (s[i] == '?') {
                if (i == 0) ans *= 9;
                else ans *= 10;
            }
        }
        cout << ans << nl;
	}
	return 0;
}
